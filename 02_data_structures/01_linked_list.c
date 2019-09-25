#include <stdio.h>
#include <stdlib.h>
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

void insert_list(list **ptr_to_head, item_type x) {
	list *p;	// temporary pointer

	p = malloc(sizeof(list));
	p->item = x;
	p->next = *ptr_to_head;
	/* Insertion at the beginning of the list avoids any need to traverse the list, but does require us to update the pointer to the head of the data structure. */
	*ptr_to_head = p;
}
