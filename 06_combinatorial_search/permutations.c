#include <stdio.h>
#include <stdbool.h>
#include "backtrack.h"

bool is_a_solution(int solution_vector[], int element_num, int range_size) {
	return (element_num == range_size);
}

void construct_candidates(int solution_vector[], int element_num, int range_size, int next_candidate_arr[], int *next_candidate_num_ptr) {
	int i;
	bool is_in_permutation[MAX_NUM_SOLUTIONS];

	for (i = 1; i < MAX_NUM_SOLUTIONS; i++)
		is_in_permutation[i] = false;
	for (i = 1; i < element_num; i++)
		is_in_permutation[solution_vector[i]] = true;

	*next_candidate_num_ptr = 0;
	for (i= 1; i <= range_size; i++)
		/* if not already in permutation, add number to candidate array */
		if (!is_in_permutation[i]) {
			next_candidate_arr[*next_candidate_num_ptr] = i;
			*next_candidate_num_ptr = *next_candidate_num_ptr + 1;
		}
} 

void process_solution(int solution_vector[], int element_num, int range_size) {
	int i;

	printf("[");
	for (i = 1; i <= element_num; i++)
		printf(" %d", solution_vector[i]);
	printf(" ]\n");
}

void make_move(int solution_vector[], int element_num, int range_size) {
	return;
}

void unmake_move(int solution_vector[], int element_num, int range_size) {
	return;
}

void generate_permutations(int range_size) {
	int solution_vector[MAX_NUM_SOLUTIONS];
	backtrack(solution_vector, 0, range_size);
}
