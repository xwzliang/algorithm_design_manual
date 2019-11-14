#include <stdbool.h>
#include <stdio.h>
#include "item_type.h"
#include "../02_data_structures/04_queue.h"
#include "queue.h"
#include "graph.h"

bool is_processed[MAX_VERTICES_NUM+1];		// which vertices have been processed or not
bool is_discovered[MAX_VERTICES_NUM+1];		// which vertices have been discovered or not
int parent[MAX_VERTICES_NUM+1];		// discovery relation tree

void initialize_search(graph *graph_ptr) {
	int i;

	for (i = 1; i <= graph_ptr->num_vertices; i++) {
		is_processed[i] = is_discovered[i] = false;
		parent[i] = -1;
	}
}

void process_vertex_early(int vertex) {
	printf("processed vertex %d\n", vertex);
}

void process_vertex_late(int vertex) {
	return;
}

void process_edge(int vertex, int vertex_successor) {
	printf("processed edge (%d, %d)\n", vertex, vertex_successor);
}

void breadth_first_search(graph *graph_ptr, int start_vertex) {
	queue q_vertices;	// queue of vertices to visit
	int vertex;
	int vertex_successor;
	edge *tmp_edge_ptr;

	init_queue(&q_vertices);
	enqueue(&q_vertices, start_vertex);
	is_discovered[start_vertex] = true;

	while (empty_queue(&q_vertices) == false) {
		vertex = dequeue(&q_vertices);
		process_vertex_early(vertex);
		is_processed[vertex] = true;
		tmp_edge_ptr = graph_ptr->edges[vertex];
		while (tmp_edge_ptr != NULL) {
			vertex_successor = tmp_edge_ptr->vertex_connected;
			if (!is_processed[vertex_successor] || graph_ptr->is_directed)
				process_edge(vertex, vertex_successor);
			if (!is_discovered[vertex_successor]) {
				enqueue(&q_vertices, vertex_successor);
				is_discovered[vertex_successor] = true;
				parent[vertex_successor] = vertex;
			}
			tmp_edge_ptr = tmp_edge_ptr->next;
		}
		process_vertex_late(vertex);
	}
}
