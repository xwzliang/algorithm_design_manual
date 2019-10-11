#include <stdio.h>
#include "item_type.h"
#include "03_priority_queue.h"
/*
 * We will store the root of the tree in the first position of the array, and its left and right children in the second and third poisions, respectively.
 * We assume that the array starts with index 1 to simplify matters.
 */

int pq_parent(int n_index) {
	if (n_index == 1)
		return -1;
	else
		return (int) n_index/2;		// implicitly take floor(n/2)
}

int pq_young_child(int n_index) {
	return 2 * n_index;
}

void pq_swap(priority_queue *q, int a_index, int b_index) {
	item_type tmp;
	tmp = q->arr[a_index];
	q->arr[a_index] = q->arr[b_index];
	q->arr[b_index] = tmp;
}

void bubble_up(priority_queue *q, int item_index) {
	if (pq_parent(item_index) == -1)
		return;		// at root of heap, no parent
	if (q->arr[pq_parent(item_index)] > q->arr[item_index]) {
		pq_swap(q, item_index, pq_parent(item_index));
		bubble_up(q, pq_parent(item_index));
	}
}

void pq_insert(priority_queue *q, item_type item_value) {
	if (q->length >= PQ_SIZE)
		printf("Warning: priority queue overflow insert item_value=%d\n", item_value);
	else {
		q->length = (q->length) + 1;
		q->arr[ q->length ] = item_value;
		bubble_up(q, q->length);
	}
}

void pq_init(priority_queue *q) {
	q->length = 0;
}

void make_heap(priority_queue *q, item_type item_arr[], int item_num) {
	int i;
	pq_init(q);
	for (i=0; i<item_num; i++) {
		pq_insert(q, item_arr[i]);
	}
}

void  bubble_down(priority_queue *q, int item_index) {
	int young_child_index;
	int min_index;		// index of lightest child
	int i;

	young_child_index = pq_young_child(item_index);
	min_index = item_index;

	/* check for both children */
	for (i=0; i<=1; i++)
		if ((young_child_index + i) <= q->length)
			if (q->arr[min_index] > q->arr[young_child_index+i])
				min_index = young_child_index + i;

	if (min_index != item_index) {
		pq_swap(q, item_index, min_index);
		bubble_down(q, min_index);
	}
}

item_type extract_min(priority_queue *q) {
	int min = -1;

	if (q->length <= 0)
		printf("Warning: empty priority queue.\n");
	else {
		min = q->arr[1];	// min is the root
		/* rearrange the tree, fill the hole after the root has been removed. */
		q->arr[1] = q->arr[ q->length ];
		q->length = q->length - 1;
		bubble_down(q, 1);
	}
	return min;
}
