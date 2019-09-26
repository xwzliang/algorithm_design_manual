#include <stdio.h>
#include <stdlib.h>
#include "item_type.h"

typedef struct tree {
	item_type item;		// data item
	struct tree *parent;	// pointer to parent
	struct tree *left;		// pointer to left child
	struct tree *right;		// pointer to right child
} tree;

tree *search_tree(tree *l, item_type x) {
	if (l == NULL)
		return NULL;
	if (l->item == x)
		return l;
	if (x < l->item)
		return search_tree(l->left, x);
	else
		return search_tree(l->right, x);
}

void insert_tree(tree **ptr_ptr, item_type x, tree *parent) {
	tree *p;	// temporary pointer

	if (*ptr_ptr == NULL) {
		p = malloc(sizeof(tree));	// allocate new node
		p->item = x;
		p->left = p->right = NULL;
		p->parent = parent;
		*ptr_ptr = p;	// link into parent's record
		return;
	}

	if (x < (*ptr_ptr)->item)
		insert_tree(&((*ptr_ptr)->left), x, *ptr_ptr);
	else
		insert_tree(&((*ptr_ptr)->right), x, *ptr_ptr);
}

tree *find_minimum(tree *l) {
	tree *min;		// pointer to minimum

	if (l == NULL)
		return NULL;

	min = l;
	while (min->left != NULL)
		min = min->left;
	return min;
}

void traverse_tree(tree *l) {
	void process_item(item_type * item);
	if (l != NULL) {
		traverse_tree(l->left);
		process_item(&(l->item));
		traverse_tree(l->right);
	}
}

void process_item(item_type *item) {
	*item *= 2;
}
