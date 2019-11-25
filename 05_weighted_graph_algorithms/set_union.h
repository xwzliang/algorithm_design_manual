#define SET_SIZE 1000
typedef struct set_union {
	int parent_element_arr[SET_SIZE+1];
	int num_elements_in_subtree_arr[SET_SIZE+1];
	int num_elements_in_set;
} set_union;
void set_union_init(set_union *set_ptr, int num_elements_in_set);
int find_root(set_union *set_ptr, int element);
void union_sets(set_union *set_ptr, int element_1, int element_2);
bool is_same_component(set_union *set_ptr, int element_1, int element_2);
