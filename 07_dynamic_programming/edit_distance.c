#include <stdio.h>
#include <string.h>

#define MAX_NUM_EDIT_DIST 100

#define MATCH_SYMBOL 0
#define INSERT_SYMBOL 1
#define DELETE_SYMBOL 2

typedef struct edit_dist_matrix_cell {
	int dist_so_far;
	int parent;		// Use parent to track the edit solution path
} edit_dist_matrix_cell;

edit_dist_matrix_cell edit_dist_matrix[MAX_NUM_EDIT_DIST+1][MAX_NUM_EDIT_DIST+1];


void edit_dist_matrix_row_init(int row_num) {
	edit_dist_matrix[0][row_num].dist_so_far = row_num;
	if (row_num > 0)
		edit_dist_matrix[0][row_num].parent = INSERT_SYMBOL;
	else
		edit_dist_matrix[0][row_num].parent = -1;
}

void edit_dist_matrix_column_init(int row_num) {
	edit_dist_matrix[row_num][0].dist_so_far = row_num;
	if (row_num > 0)
		edit_dist_matrix[row_num][0].parent = DELETE_SYMBOL;
	else
		edit_dist_matrix[row_num][0].parent = -1;
}

void insert_space_to_beginning_of_string(char *str, char *str_raw) {
	int i;
	str[0] = 32;
	for (i = 1; i < strlen(str_raw)+1; i++) {
		str[i] = str_raw[i-1];
	}
}

int match_or_substitution_cost(char a, char b) {
	if (a == b)
		return 0;
	else
		return 1;
}

int insert_or_delete_cost(char c) {
	return 1;
}

void last_cell_of_solution_path(char *str_a, char *str_b, int *i, int *j) {
	*i = strlen(str_a) - 1;
	*j = strlen(str_b) - 1;
}

int edit_dist(char *str_a_raw, char *str_b_raw) {
	int i, j, k;
	int operation_cost_arr[3];
	char str_a[strlen(str_a_raw)+1];
	char str_b[strlen(str_b_raw)+1];
	void print_edit_solution_path();

	for (i = 0; i < MAX_NUM_EDIT_DIST; i++) {
		edit_dist_matrix_row_init(i);
		edit_dist_matrix_column_init(i);
	}

	// Insert space to the beginning for string a and b
	insert_space_to_beginning_of_string(str_a, str_a_raw);
	insert_space_to_beginning_of_string(str_b, str_b_raw);

	for (i = 1; i < strlen(str_a); i++) {
		for (j = 1; j < strlen(str_b); j++) {
			operation_cost_arr[MATCH_SYMBOL] = edit_dist_matrix[i-1][j-1].dist_so_far + match_or_substitution_cost(str_a[i], str_b[j]);
			operation_cost_arr[INSERT_SYMBOL] = edit_dist_matrix[i][j-1].dist_so_far + insert_or_delete_cost(str_b[j]);
			operation_cost_arr[DELETE_SYMBOL] = edit_dist_matrix[i-1][j].dist_so_far + insert_or_delete_cost(str_a[i]);

			/* select the cheapest operation */
			edit_dist_matrix[i][j].dist_so_far = operation_cost_arr[MATCH_SYMBOL];
			edit_dist_matrix[i][j].parent = MATCH_SYMBOL;
			for (k = INSERT_SYMBOL; k <= DELETE_SYMBOL; k++) {
				if (operation_cost_arr[k] < edit_dist_matrix[i][j].dist_so_far) {
					edit_dist_matrix[i][j].dist_so_far = operation_cost_arr[k];
					edit_dist_matrix[i][j].parent = k;
				}
			}
		}
	}

	last_cell_of_solution_path(str_a, str_b, &i, &j);
	return edit_dist_matrix[i][j].dist_so_far;
}


void print_operation_match_or_substitution(char *str_a, char *str_b, int i, int j) {
	if (str_a[i] == str_b[j])
		printf("M");
	else
		printf("S");
}

void print_operation_insert(char *str_b, int j) {
	printf("I");
}

void print_operation_delete(char *str_a, int i) {
	printf("D");
}

void print_edit_solution_path_recursion(char *str_a, char *str_b, int i, int j) {
	if (edit_dist_matrix[i][j].parent == -1)
		return;
	if (edit_dist_matrix[i][j].parent == MATCH_SYMBOL) {
		print_edit_solution_path_recursion(str_a, str_b, i-1, j-1);
		print_operation_match_or_substitution(str_a, str_b, i, j);
		return;
	}
	if (edit_dist_matrix[i][j].parent == INSERT_SYMBOL) {
		print_edit_solution_path_recursion(str_a, str_b, i, j-1);
		print_operation_insert(str_b, j);
		return;
	}
	if (edit_dist_matrix[i][j].parent == DELETE_SYMBOL) {
		print_edit_solution_path_recursion(str_a, str_b, i-1, j);
		print_operation_delete(str_a, i);
		return;
	}
}

void print_edit_solution_path(char *str_a_raw, char *str_b_raw, int index_final_char_a, int index_final_char_b) {
	char str_a[strlen(str_a_raw)+1];
	char str_b[strlen(str_b_raw)+1];

	insert_space_to_beginning_of_string(str_a, str_a_raw);
	insert_space_to_beginning_of_string(str_b, str_b_raw);

	print_edit_solution_path_recursion(str_a, str_b, index_final_char_a+1, index_final_char_b+1);
}
