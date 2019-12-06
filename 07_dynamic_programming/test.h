long binomial_coefficient(int n, int k);
typedef struct edit_dist_matrix_cell {
	int dist_so_far;
	int parent;		// Use parent to track the edit solution path
} edit_dist_matrix_cell;
void edit_dist_matrix_row_init(int row_num);
void edit_dist_matrix_column_init(int row_num);
void insert_space_to_beginning_of_string(char *str, char *str_raw);
int match_or_substitution_cost(char a, char b);
int insert_or_delete_cost(char c);
void last_cell_of_solution_path(char *str_a, char *str_b, int *i, int *j);
int edit_dist(char *str_a_raw, char *str_b_raw);
void print_operation_match_or_substitution(char *str_a, char *str_b, int i, int j);
void print_operation_insert(char *str_b, int j);
void print_operation_delete(char *str_a, int i);
void print_edit_solution_path_recursion(char *str_a, char *str_b, int i, int j);
void print_edit_solution_path(char *str_a_raw, char *str_b_raw, int index_final_char_a, int index_final_char_b);
long fib_by_recursion(int num);
long fib_by_caching(int num);
long fib_c(int num);
long fib_by_dynamic_programming(int num);
