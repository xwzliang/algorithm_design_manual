#include <stdbool.h>
bool is_a_solution(int solution_vector[], int element_num, int range_size);
void construct_candidates(int solution_vector[], int element_num, int range_size, int next_candidate_arr[], int *next_candidate_num_ptr);
void process_solution(int solution_vector[], int element_num, int range_size);
void make_move(int solution_vector[], int element_num, int range_size);
void unmake_move(int solution_vector[], int element_num, int range_size);
void generate_permutations(int range_size);
