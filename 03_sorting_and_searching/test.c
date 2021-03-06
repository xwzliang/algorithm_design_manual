#include <stdio.h>
#include <unity.h>
#include "item_type.h"
#include "test.h"

void setUp() {}
void tearDown() {}

void test_heap_sort() {
	int arr_num = 10;
	int arr[] = {5, 8, 9, 2, 3, 1, 0, 7, 4, 6};
	int expect[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	heap_sort(arr, arr_num);
	TEST_ASSERT_EQUAL_INT_ARRAY(expect, arr, arr_num);
}

void test_merge_sort() {
	int arr_num = 10;
	int arr[] = {5, 8, 9, 2, 3, 1, 0, 7, 4, 6};
	int expect[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	merge_sort(arr, 0, arr_num-1);
	TEST_ASSERT_EQUAL_INT_ARRAY(expect, arr, arr_num);
}

void test_quick_sort() {
	int arr_num = 10;
	int arr[] = {5, 8, 9, 2, 3, 1, 0, 7, 4, 6};
	int expect[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	quick_sort(arr, 0, arr_num-1);
	TEST_ASSERT_EQUAL_INT_ARRAY(expect, arr, arr_num);
}

void test_binary_search() {
	int arr_num = 10;
	int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	TEST_ASSERT_EQUAL(9, binary_search(arr, 9, 0, arr_num-1));
	TEST_ASSERT_EQUAL(3, binary_search(arr, 3, 0, arr_num-1));
}

int main() {
	UNITY_BEGIN();
	RUN_TEST(test_heap_sort);
	RUN_TEST(test_merge_sort);
	RUN_TEST(test_quick_sort);
	RUN_TEST(test_binary_search);
	return UNITY_END();
}
