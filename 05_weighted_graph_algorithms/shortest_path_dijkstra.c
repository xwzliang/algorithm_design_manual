#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include "graph.h"

int parent[MAX_VERTICES_NUM+1];		// discovery relation tree

void shortest_path_dijkstra(graph *graph_ptr, int start_vertex) {
	int i;
	edge *tmp_edge_ptr;
	bool is_in_tree[MAX_VERTICES_NUM+1];
	int cost_of_adding_to_tree[MAX_VERTICES_NUM+1];
	int vertex;
	int vertex_next_candidate;
	int current_edge_weight;
	int best_next_edge_weight;

	for (i = 1; i <= graph_ptr->num_vertices; i++) {
		is_in_tree[i] = false;
		cost_of_adding_to_tree[i] = INT_MAX;
		parent[i] = -1;
	}

	cost_of_adding_to_tree[start_vertex] = 0;
	vertex = start_vertex;

	while (!is_in_tree[vertex]) {
		is_in_tree[vertex] = true;

		// Print edge for test
		printf("%d %d\n", parent[vertex], vertex);
		
		tmp_edge_ptr = graph_ptr->edges[vertex];
		while (tmp_edge_ptr != NULL) {
			vertex_next_candidate = tmp_edge_ptr->vertex_connected;
			current_edge_weight = tmp_edge_ptr->edge_weight;
			if (cost_of_adding_to_tree[vertex_next_candidate] > (cost_of_adding_to_tree[vertex] + current_edge_weight)) {
				cost_of_adding_to_tree[vertex_next_candidate] = cost_of_adding_to_tree[vertex] + current_edge_weight;
				parent[vertex_next_candidate] = vertex;
			}
			tmp_edge_ptr = tmp_edge_ptr->next;
		}

		/* select next vertex with the smallest weight from vertices connected to tree but haven't been added yet */
		vertex = 1;
		best_next_edge_weight = INT_MAX;
		for (i = 1; i <= graph_ptr->num_vertices; i++) {
			if ((!is_in_tree[i]) && (best_next_edge_weight > cost_of_adding_to_tree[i])) {
				best_next_edge_weight = cost_of_adding_to_tree[i];
				vertex = i;
			}
		}
	}
}
