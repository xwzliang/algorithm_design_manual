#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

void initialize_graph(graph *graph_ptr, int is_directed) {
	int i;

	graph_ptr->num_vertices = 0;
	graph_ptr->num_edges = 0;
	graph_ptr->is_directed = is_directed;

	for (i = 1; i <= MAX_VERTICES_NUM; i++)
		graph_ptr->degree_of_vertex[i] = 0;
	for (i = 1; i <= MAX_VERTICES_NUM; i++)
		graph_ptr->edges[i] = NULL;
}

void insert_edge(graph *graph_ptr, int vertex, int vertex_connected, int is_directed) {
	edge *tmp_edge_ptr;

	tmp_edge_ptr = malloc(sizeof(edge));

	tmp_edge_ptr->edge_weight = 0;
	tmp_edge_ptr->vertex_connected = vertex_connected;
	tmp_edge_ptr->next = graph_ptr->edges[vertex];

	graph_ptr->edges[vertex] = tmp_edge_ptr;		// insert at the head of list
	graph_ptr->degree_of_vertex[vertex] ++;

	if (is_directed)
		graph_ptr->num_edges ++;
	else
		insert_edge(graph_ptr, vertex_connected, vertex, 1);
}

void read_graph(graph *graph_ptr, int is_directed) {
	int i;
	int num_edges;
	int vertex_x, vertex_y;		// vertices in edge (x, y)

	initialize_graph(graph_ptr, is_directed);

	scanf("%d %d", &(graph_ptr->num_vertices), &num_edges);

	for (i = 1; i <= num_edges; i++) {
		scanf("%d %d", &vertex_x, &vertex_y);
		insert_edge(graph_ptr, vertex_x, vertex_y, is_directed);
	}
}

void print_graph(graph *graph_ptr) {
	int i;
	edge *tmp_edge_ptr;

	for (i = 1; i <= graph_ptr->num_vertices; i++) {
		printf("%d: ", i);
		tmp_edge_ptr = graph_ptr->edges[i];
		while (tmp_edge_ptr != NULL) {
			printf(" %d", tmp_edge_ptr->vertex_connected);
			tmp_edge_ptr = tmp_edge_ptr->next;
		}
		printf("\n");
	}
}
