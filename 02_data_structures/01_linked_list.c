#include <stdio.h>
#include "item_type.h"

typedef struct list {
	item_type item;		// data item
	struct list *next;		// point to successor
} list;

list *search_list(list *l, item_type x) {
	if (l == NULL) 
		return (NULL);

	if (l->item == x)
		return l;
	else
		return ( search_list(l->next, x) );
}
