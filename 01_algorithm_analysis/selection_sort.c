#include "swap.h"

/* selection sort: repeatedly identifies the smallest remaining unsorted element and puts it at the end of the sorted portion of the array. */
void selection_sort(int s[], int n) {
	int i, j;		/* counters */
	int min;		/* index of minimum */

	for (i=0; i<n; i++) {
		min = i;
		for (j=i+1; j<n; j++)
			if (s[j] < s[min]) 
				min = j;
		swap(&s[i], &s[min]);
	}
}
