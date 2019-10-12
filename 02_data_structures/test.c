#include <stdio.h>
#include <unity.h>
#include "item_type.h"
#include "03_priority_queue.h"
#include "04_queue.h"
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

void test_binary_search_tree() {
	tree root = {0, NULL, NULL, NULL};
	TEST_ASSERT_EQUAL(0, search_tree(&root, 0)->item);

	tree *ptr_to_root = &root;
	insert_tree(&ptr_to_root, -1, NULL);
	TEST_ASSERT_EQUAL(-1, root.left->item);
	TEST_ASSERT_EQUAL(ptr_to_root, root.left->parent);
	insert_tree(&ptr_to_root, -3, NULL);
	insert_tree(&ptr_to_root, 5, NULL);
	TEST_ASSERT_EQUAL(5, root.right->item);
	TEST_ASSERT_EQUAL(-3, root.left->left->item);

	TEST_ASSERT_EQUAL(-3, find_minimum(ptr_to_root)->item);

	traverse_tree(ptr_to_root);
	TEST_ASSERT_EQUAL(-6, find_minimum(ptr_to_root)->item);
}

void test_priority_queue() {
	priority_queue q;
	pq_init(&q);
	int item_num = 4;
	int item_arr[] = {5, 3, 1, 4};

	make_heap(&q, item_arr, item_num);

	int expect_arr[] = {1, 4, 3, 5};
	TEST_ASSERT_EQUAL_INT_ARRAY(q.arr+1, expect_arr, item_num);	// The first 0 is default, start with index 1

	int expect_arr_new[] = {3, 4, 5};
	TEST_ASSERT_EQUAL(1, extract_min(&q));
	TEST_ASSERT_EQUAL_INT_ARRAY(q.arr+1, expect_arr_new, item_num-1);
}

void test_queue() {
	queue q;
	init_queue(&q);
	enqueue(&q, 1);
	TEST_ASSERT_EQUAL(0, empty_queue(&q));
	TEST_ASSERT_EQUAL(1, head_queue(&q));
	enqueue(&q, 2);
	TEST_ASSERT_EQUAL(1, dequeue(&q));
	TEST_ASSERT_EQUAL(2, head_queue(&q));
	TEST_ASSERT_EQUAL(0, empty_queue(&q));
	TEST_ASSERT_EQUAL(2, dequeue(&q));
	TEST_ASSERT_EQUAL(1, empty_queue(&q));
}

int main() {
	UNITY_BEGIN();
	RUN_TEST(test_linked_list);
	RUN_TEST(test_binary_search_tree);
	RUN_TEST(test_priority_queue);
	RUN_TEST(test_queue);
	return UNITY_END();
}
