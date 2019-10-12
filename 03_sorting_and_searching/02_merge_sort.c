#include "item_type.h"
#include "../02_data_structures/04_queue.h"
#include "queue.h"

void merge(item_type item_arr[], int index_low, int index_middle, int index_high) {
	int i;
	queue buffer1, buffer2;		// buffers to hold elements for merging

	init_queue(&buffer1);
	init_queue(&buffer2);

	for (i = index_low; i <= index_middle; i++)
		enqueue(&buffer1, item_arr[i]);
	for (i = index_middle + 1; i <= index_high; i++)
		enqueue(&buffer2, item_arr[i]);

	i = index_low;
	while (!(empty_queue(&buffer1) || empty_queue(&buffer2))) {
		if (head_queue(&buffer1) <= head_queue(&buffer2))
			item_arr[i++] = dequeue(&buffer1);
		else
			item_arr[i++] = dequeue(&buffer2);
	}

	/* Now one of the queue is empty, and we put all items of another queue to the item_arr */
	while (!empty_queue(&buffer1))
		item_arr[i++] = dequeue(&buffer1);
	while (!empty_queue(&buffer2))
		item_arr[i++] = dequeue(&buffer2);
}

void merge_sort(item_type item_arr[], int index_low, int index_high) {
	int i;
	int index_middle;

	if (index_low < index_high) {
		index_middle = (index_low + index_high) / 2;
		merge_sort(item_arr, index_low, index_middle);
		merge_sort(item_arr, index_middle+1, index_high);
		merge(item_arr, index_low, index_middle, index_high);
	}
}
