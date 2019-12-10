#include "item_type.h"

int binary_search(item_type item_arr[], item_type key_value, int index_low, int index_high) {
	int index_middle;

	if (index_low > index_high)
		return -1;		// key not found

	index_middle = (index_low + index_high) / 2;

	if (item_arr[index_middle] == key_value)
		return index_middle;
	if (item_arr[index_middle] > key_value)
		return binary_search(item_arr, key_value, index_low, index_middle-1);
	else
		return binary_search(item_arr, key_value, index_middle+1, index_high);
}
