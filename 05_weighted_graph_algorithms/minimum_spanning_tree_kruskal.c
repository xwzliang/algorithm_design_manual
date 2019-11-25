#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "graph.h"
#include "set_union.h"

typedef struct edge_pair_vertices {
	int vertex_x, vertex_y;
	int edge_weight;
} edge_pair_vertices;

void convert_graph_edges_to_edge_arr(graph *graph_ptr, edge_pair_vertices edge_arr[]) {
	int i;
	int arr_index;
	edge *tmp_edge_ptr;

	arr_index = 1;
	for (i = 1; i <= graph_ptr->num_vertices; i++) {
		tmp_edge_ptr = graph_ptr->edges[i];
		while (tmp_edge_ptr != NULL) {
			if (tmp_edge_ptr->vertex_connected > i) {
				edge_arr[arr_index].vertex_x = i;
				edge_arr[arr_index].vertex_y = tmp_edge_ptr->vertex_connected;
				edge_arr[arr_index].edge_weight = tmp_edge_ptr->edge_weight;
				arr_index++;
			}
			tmp_edge_ptr = tmp_edge_ptr->next;
		}
	}
}

/* The prototype for qsort() is: */
/* void qsort(void *base, size_t nmemb, size_t size, */
/*            int(*compar)(const void *, const void *)); */
/* Thus, your sorting function needs to either match int(*compar) (const void *, const void *), or you need to cast when calling qsort(). */
int weight_compare(const void *ptr1, const void *ptr2) {
	const edge_pair_vertices *edge_ptr_x = ptr1, *edge_ptr_y = ptr2;
	return ( edge_ptr_x->edge_weight > edge_ptr_y->edge_weight );
}

void minimum_spanning_tree_kruskal(graph *graph_ptr) {
	int i;
	set_union set_vertex;
	edge_pair_vertices edge_arr[MAX_VERTICES_NUM+1];
	int weight_compare();

	set_union_init(&set_vertex, graph_ptr->num_vertices);

	convert_graph_edges_to_edge_arr(graph_ptr, edge_arr);
	/* sort edges by increasing weight */
	qsort(&edge_arr, graph_ptr->num_edges, sizeof(edge_pair_vertices), weight_compare);

	for (i = 0; i < (graph_ptr->num_edges); i++) {
		if (!is_same_component(&set_vertex, edge_arr[i].vertex_x, edge_arr[i].vertex_y)) {
			/* find edge in minimum_spanning_tree */
			printf("%d %d\n", edge_arr[i].vertex_x, edge_arr[i].vertex_y);
			union_sets(&set_vertex, edge_arr[i].vertex_x, edge_arr[i].vertex_y);
		}
	}
}
