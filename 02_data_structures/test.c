#include <stdio.h>
#include <unity.h>
#include "item_type.h"
#include "test.h"

void test_linked_list() {
	list test_list = {5, NULL};
	list *pl = &test_list;

	TEST_ASSERT_EQUAL(5, test_list.item);
	TEST_ASSERT_EQUAL(5, search_list(pl, 5)->item);
	TEST_ASSERT_EQUAL(NULL, search_list(pl, 4));
}

int main() {
	UNITY_BEGIN();
	RUN_TEST(test_linked_list);
	return UNITY_END();
}
