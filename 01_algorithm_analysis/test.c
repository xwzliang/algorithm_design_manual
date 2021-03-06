#include <stdio.h>
#include <unity.h>
#include "test.h"

void setUp() {}
void tearDown() {}

void test_selection_sort() {
	int arr_num = 10;
	int arr[] = {5, 8, 9, 2, 3, 1, 0, 7, 4, 6};
	int expect[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	selection_sort(arr, arr_num);
	TEST_ASSERT_EQUAL_INT_ARRAY(expect, arr, arr_num);
}

void test_insertion_sort() {
	int arr_num = 10;
	int arr[] = {5, 8, 9, 2, 3, 1, 0, 7, 4, 6};
	int expect[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	insertion_sort(arr, arr_num);
	TEST_ASSERT_EQUAL_INT_ARRAY(expect, arr, arr_num);
}

void test_findmatch() {
	char * pattern1 = "awesome";
	char * pattern2 = "hello";
	char * text = "This is awesome";

	TEST_ASSERT_EQUAL_INT(8, findmatch(pattern1, text));
	TEST_ASSERT_EQUAL_INT(-1, findmatch(pattern2, text));
}

int main() {
	UNITY_BEGIN();
	RUN_TEST(test_selection_sort);
	RUN_TEST(test_insertion_sort);
	RUN_TEST(test_findmatch);
	return UNITY_END();
}
