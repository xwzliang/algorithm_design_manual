typedef struct list {
	item_type item;		// data item
	struct list *next;		// point to successor
} list;
list *search_list();
void insert_list();
list *predecessor_list();
void delete_list();
typedef struct tree {
	item_type item;		// data item
	struct tree *parent;	// pointer to parent
	struct tree *left;		// pointer to left child
	struct tree *right;		// pointer to right child
} tree;
tree *search_tree();
void insert_tree();
tree *find_minimum();
void traverse_tree();
void process_item();
int pq_parent();
int pq_young_child();
void pq_swap();
void bubble_up();
void pq_insert();
void pq_init();
void make_heap();
void  bubble_down();
item_type extract_min();
void init_queue();
void enqueue();
item_type dequeue();
item_type head_queue();
int empty_queue();
