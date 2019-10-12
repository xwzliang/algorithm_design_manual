#include "item_type.h"

void swap(item_type *x, item_type *y) {
	item_type temp;

	temp = *x;
	*x = *y;
	*y = temp;
}
