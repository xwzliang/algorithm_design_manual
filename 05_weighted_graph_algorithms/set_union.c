#include <stdbool.h>
#include "set_union.h"

/* typedef struct set_union { */
/* 	int parent_element_arr[SET_SIZE+1]; */
/* 	int num_elements_in_subtree_arr[SET_SIZE+1]; */
/* 	int num_elements_in_set; */
/* } set_union; */

void set_union_init(set_union *set_ptr, int num_elements_in_set) {
	int i;

	for (i = 1; i <= num_elements_in_set; i++) {
		set_ptr->parent_element_arr[i] = i;
		set_ptr->num_elements_in_subtree_arr[i] = 1;
	}
	set_ptr->num_elements_in_set = num_elements_in_set;
}

int find_root(set_union *set_ptr, int element) {
	if (set_ptr->parent_element_arr[element] == element)
		return element;
	else
		return find_root(set_ptr, set_ptr->parent_element_arr[element]);
}

void union_sets(set_union *set_ptr, int element_1, int element_2) {
	int root_1, root_2;

	root_1 = find_root(set_ptr, element_1);
	root_2 = find_root(set_ptr, element_2);

	if (root_1 == root_2)	// already in the same set
		return;

	if (set_ptr->num_elements_in_subtree_arr[root_1] >= set_ptr->num_elements_in_subtree_arr[root_2]) {
		set_ptr->num_elements_in_subtree_arr[root_1] = set_ptr->num_elements_in_subtree_arr[root_1] + set_ptr->num_elements_in_subtree_arr[root_2];
		set_ptr->parent_element_arr[root_2] = root_1;
	}
	else {
		set_ptr->num_elements_in_subtree_arr[root_2] = set_ptr->num_elements_in_subtree_arr[root_1] + set_ptr->num_elements_in_subtree_arr[root_2];
		set_ptr->parent_element_arr[root_1] = root_2;
	}
}

bool is_same_component(set_union *set_ptr, int element_1, int element_2) {
	return (find_root(set_ptr, element_1) == find_root(set_ptr, element_2));
}
