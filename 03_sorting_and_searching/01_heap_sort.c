#include "item_type.h"
#include "../02_data_structures/03_priority_queue.h"
#include "priority_queue.h"

void heap_sort(item_type item_arr[], int item_num) {
	int i;
	priority_queue q;

	make_heap(&q, item_arr, item_num);

	for (i=0; i<item_num; i++)
		item_arr[i] = extract_min(&q);
}
