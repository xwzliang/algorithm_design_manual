#include <stdio.h>
#include <stdbool.h>
#include "backtrack.h"
#include "../04_graph_traversal/graph.h"

extern graph g;
int solution_count;

bool is_a_solution(int solution_vector[], int element_num, int vertex_end_index) {
	return (solution_vector[element_num] == vertex_end_index);
}

void construct_candidates(int solution_vector[], int element_num, int vertex_end_index, int next_candidate_arr[], int *next_candidate_num_ptr) {
	int i;
	bool is_in_solution[MAX_NUM_SOLUTIONS];
	edge *tmp_edge_ptr;
	int last_vertex_index;
	
	for (i = 1; i < MAX_NUM_SOLUTIONS; i++)
		is_in_solution[i] = false;
	for (i = 1; i < element_num; i++)
		is_in_solution[solution_vector[i]] = true;

	if (element_num == 1) {
		/* always start from vertex 1 */
		next_candidate_arr[0] = 1;
		*next_candidate_num_ptr = 1;
	}
	else {
		*next_candidate_num_ptr = 0;
		last_vertex_index = solution_vector[element_num-1];
		tmp_edge_ptr = g.edges[last_vertex_index];
		while (tmp_edge_ptr != NULL) {
			if (!is_in_solution[tmp_edge_ptr->vertex_connected]){
				next_candidate_arr[*next_candidate_num_ptr] = tmp_edge_ptr->vertex_connected;
				*next_candidate_num_ptr = *next_candidate_num_ptr + 1;
			}
			tmp_edge_ptr = tmp_edge_ptr->next;
		}
	}
} 

void process_solution(int solution_vector[], int element_num, int vertex_end_index) {
	int i;

	printf("[");
	for (i = 1; i <= element_num; i++)
		printf(" %d", solution_vector[i]);
	printf(" ]\n");

	solution_count ++;
}

void make_move(int solution_vector[], int element_num, int vertex_end_index) {
	return;
}

void unmake_move(int solution_vector[], int element_num, int vertex_end_index) {
	return;
}

void generate_all_graph_paths(int vertex_end_index) {
	int solution_vector[MAX_NUM_SOLUTIONS];
	backtrack(solution_vector, 0, vertex_end_index);
}
