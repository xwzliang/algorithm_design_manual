#include <stdbool.h>
#include "backtrack.h"

void backtrack(int solution_vector[], int element_num, data input_data) {
	int next_candidate_arr[MAX_NUM_CANDIDATES];
	int next_candidate_num;
	int i;

	bool is_a_solution();
	void construct_candidates();
	void process_solution();
	void make_move();
	void unmake_move();
	void generate_subsets();

	if (is_a_solution(solution_vector, element_num, input_data))
		process_solution(solution_vector, element_num, input_data);
	else {
		element_num = element_num + 1;
		construct_candidates(solution_vector, element_num, input_data, next_candidate_arr, &next_candidate_num);
		for (i = 0; i < next_candidate_num; i++) {
			solution_vector[element_num] = next_candidate_arr[i];
			make_move(solution_vector, element_num, input_data);
			backtrack(solution_vector, element_num, input_data);
			unmake_move(solution_vector, element_num, input_data);
		}
	}
}
