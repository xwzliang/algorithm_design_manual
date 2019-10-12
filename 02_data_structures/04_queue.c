#include <stdio.h>
#include "item_type.h"
#include "04_queue.h"

void init_queue(queue *q) {
	q->head = 0;
	q->tail = QUEUE_SIZE-1;
	q->length = 0;
}

void enqueue(queue *q, item_type item_value) {
	if (q->length >= QUEUE_SIZE-1)
		printf("Warning: queue overflow enqueue item_value=%d\n", item_value);
	else {
		q->tail = (q->tail + 1) % QUEUE_SIZE;
		q->arr[ q->tail ] = item_value;
		q->length = q->length + 1;
	}
}

item_type dequeue(queue *q) {
	item_type head_item;

	if (q->length <= 0)
		printf("Warning: empty queue, cannot dequeue.\n");
	else {
		head_item = q->arr[ q->head ];
		q->head = (q->head + 1) % QUEUE_SIZE;
		q->length = q->length - 1;
	}

	return head_item;
}

item_type head_queue(queue *q) {
	return q->arr[ q->head ];
}

int empty_queue(queue *q) {
	return q->length == 0;
}
