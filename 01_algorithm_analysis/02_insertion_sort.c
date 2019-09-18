#include "swap.h"

/* insertion sort: A method for sorting that starts with a single element (thus forming a trivially sorted list) and then incrementally inserts the remaining elements so that the list stays sorted. */
void insertion_sort(int s[], int n) {
	int i, j;	// counters

	for (i = 0; i < n; i++) {
		j = i;
		while (j > 0 && s[j] < s[j-1]) {
			swap(&s[j], &s[j-1]);
			j--;
		}
	}
}
