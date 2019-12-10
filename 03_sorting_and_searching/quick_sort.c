#include "item_type.h"
#include "swap.h"

int quick_sort_partition(item_type item_arr[], int index_low, int index_high) {
	int i;
	int index_partition_original;
	int index_partition_sorted;		// The index of the first item whose value is larger than partition item or the last item whose value is smaller than the partition item

	index_partition_original = index_high;
	index_partition_sorted = index_low;
	for (i = index_low; i < index_high; i++)
		if (item_arr[i] < item_arr[index_partition_original]) {
			swap(&item_arr[i], &item_arr[index_partition_sorted]);
			index_partition_sorted++;
		}
	swap(&item_arr[index_partition_original], &item_arr[index_partition_sorted]);

	return index_partition_sorted;
}

void quick_sort(item_type item_arr[], int index_low, int index_high) {
	int index_partition;

	if ((index_high - index_low) > 0) {
		index_partition = quick_sort_partition(item_arr, index_low, index_high);
		quick_sort(item_arr, index_low, index_partition-1);
		quick_sort(item_arr, index_partition+1, index_high);
	}
}
