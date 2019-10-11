typedef struct list {
	item_type item;		// data item
	struct list *next;		// point to successor
} list;
list *search_list(list *l, item_type x);
void insert_list(list **ptr_to_head, item_type x);
list *predecessor_list(list *l, item_type x);
void delete_list(list **ptr_to_head, item_type x);
typedef struct tree {
	item_type item;		// data item
	struct tree *parent;	// pointer to parent
	struct tree *left;		// pointer to left child
	struct tree *right;		// pointer to right child
} tree;
tree *search_tree(tree *l, item_type x);
void insert_tree(tree **ptr_ptr, item_type x, tree *parent);
tree *find_minimum(tree *l);
void traverse_tree(tree *l);
void process_item(item_type *item);
int pq_parent(int n_index);
int pq_young_child(int n_index);
void pq_swap(priority_queue *q, int a_index, int b_index);
void bubble_up(priority_queue *q, int item_index);
void pq_insert(priority_queue *q, item_type item_value);
void pq_init(priority_queue *q);
void make_heap(priority_queue *q, item_type item_arr[], int item_num);
void  bubble_down(priority_queue *q, int item_index);
item_type extract_min(priority_queue *q);
