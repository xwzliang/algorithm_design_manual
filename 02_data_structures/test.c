#include <stdio.h>
#include <unity.h>
#include "item_type.h"
#include "test.h"

void test_linked_list() {
	list test_list = {5, NULL};
	list *head = &test_list;

	TEST_ASSERT_EQUAL(5, test_list.item);
	TEST_ASSERT_EQUAL(5, search_list(head, 5)->item);
	TEST_ASSERT_EQUAL(NULL, search_list(head, 4));

	insert_list(&head, 8);

	TEST_ASSERT_EQUAL(8, head->item);
	TEST_ASSERT_EQUAL(5, head->next->item);

	insert_list(&head, 13);
	delete_list(&head, 8);

	TEST_ASSERT_EQUAL(13, head->item);
	TEST_ASSERT_EQUAL(5, head->next->item);
}

int main() {
	UNITY_BEGIN();
	RUN_TEST(test_linked_list);
	return UNITY_END();
}
