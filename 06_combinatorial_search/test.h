#include <stdbool.h>
bool is_a_solution(int solution_vector[], int element_num, int vertex_end_index);
void construct_candidates(int solution_vector[], int element_num, int vertex_end_index, int next_candidate_arr[], int *next_candidate_num_ptr);
void process_solution(int solution_vector[], int element_num, int vertex_end_index);
void make_move(int solution_vector[], int element_num, int vertex_end_index);
void unmake_move(int solution_vector[], int element_num, int vertex_end_index);
void generate_all_graph_paths(int vertex_end_index);
