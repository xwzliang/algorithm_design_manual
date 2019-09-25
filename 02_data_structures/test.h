typedef struct list {
	item_type item;		// data item
	struct list *next;		// point to successor
} list;
list *search_list(list *l, item_type x);
