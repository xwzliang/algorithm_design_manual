long binomial_coefficient();
typedef struct edit_dist_matrix_cell {
	int dist_so_far;
	int parent;		// Use parent to track the edit solution path
} edit_dist_matrix_cell;
void edit_dist_matrix_row_init();
void edit_dist_matrix_column_init();
void insert_space_to_beginning_of_string();
int match_or_substitution_cost();
int insert_or_delete_cost();
void last_cell_of_solution_path();
int edit_dist();
void print_operation_match_or_substitution();
void print_operation_insert();
void print_operation_delete();
void print_edit_solution_path_recursion();
void print_edit_solution_path();
long fib_by_recursion();
long fib_by_caching();
long fib_c();
long fib_by_dynamic_programming();
void print_partition_solution();
void output_partition_solution();
void minimum_sum_partition();
