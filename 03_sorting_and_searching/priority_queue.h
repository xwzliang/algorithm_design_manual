int pq_parent(int n_index);
int pq_young_child(int n_index);
void pq_swap(priority_queue *q, int a_index, int b_index);
void bubble_up(priority_queue *q, int item_index);
void pq_insert(priority_queue *q, item_type item_value);
void pq_init(priority_queue *q);
void make_heap(priority_queue *q, item_type item_arr[], int item_num);
void  bubble_down(priority_queue *q, int item_index);
item_type extract_min(priority_queue *q);
