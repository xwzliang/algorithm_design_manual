#include <stdio.h>
#include <stdbool.h>
#include "backtrack.h"

bool is_a_solution(int solution_vector[], int element_num, int range_size) {
	return (element_num == range_size);
}

void construct_candidates(int solution_vector[], int element_num, int range_size, int next_candidate_arr[], int *next_candidate_num_ptr) {
	next_candidate_arr[0] = true;
	next_candidate_arr[1] = false;
	*next_candidate_num_ptr = 2;
} 

void process_solution(int solution_vector[], int element_num, int range_size) {
	int i;

	printf("{");
	for (i = 1; i <= element_num; i++)
		if (solution_vector[i] == true)
			printf(" %d", i);
	printf(" }\n");
}

void make_move(int solution_vector[], int element_num, int range_size) {
	return;
}

void unmake_move(int solution_vector[], int element_num, int range_size) {
	return;
}

void generate_subsets(int range_size) {
	int solution_vector[MAX_NUM_SOLUTIONS];
	backtrack(solution_vector, 0, range_size);
}
