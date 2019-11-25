#include <stdio.h>
#include <unistd.h>
#include <unity.h>
#include "graph.h"
#include "test.h"

static int stdout_bk; 	// is fd for stdout backup
static int pipefd[2];
static char buf[1001];

static graph g;

void stdout_capture_start() {
	fflush(stdout);		//flushall();
	stdout_bk = dup(fileno(stdout));

	pipe(pipefd);

	// What used to be stdout will now go to the pipe.
	dup2(pipefd[1], fileno(stdout));
}

void stdout_capture_finish() {
	fflush(stdout);		//flushall();
	write(pipefd[1], "", 9); 	// null-terminated string!
	close(pipefd[1]);

	dup2(stdout_bk, fileno(stdout));	//restore

	read(pipefd[0], buf, 1000);
}

void test_build_graph() {
	int is_directed = 0;

	initialize_graph(&g, is_directed);
	read_graph(&g, is_directed);

	stdout_capture_start();
	print_graph(&g);
	stdout_capture_finish();

	char *expect =
		"1:  6 5 2\n"
		"2:  5 3 1\n"
		"3:  4 2\n"
		"4:  5 3\n"
		"5:  4 2 1\n"
		"6:  1\n"
	;
	TEST_ASSERT_EQUAL_STRING(expect, buf);
}

void test_minimum_spanning_tree_prim() {
	int start_vertex = 1;
	stdout_capture_start();
	minimum_spanning_tree_prim(&g, start_vertex);
	stdout_capture_finish();

	char *expect =
		"-1 1\n"
		"1 6\n"
		"1 2\n"
		"2 5\n"
		"2 3\n"
		"3 4\n"
	;
	TEST_ASSERT_EQUAL_STRING(expect, buf);
}

void test_minimum_spanning_tree_kruskal() {
	stdout_capture_start();
	minimum_spanning_tree_kruskal(&g);
	stdout_capture_finish();

	char *expect =
		"1 6\n"
		"3 4\n"
		"1 2\n"
		"2 5\n"
		"2 3\n"
	;
	TEST_ASSERT_EQUAL_STRING(expect, buf);
}

void test_shortest_path_dijkstra() {
	int start_vertex = 1;
	stdout_capture_start();
	shortest_path_dijkstra(&g, start_vertex);
	stdout_capture_finish();

	char *expect =
		"-1 1\n"
		"1 6\n"
		"1 2\n"
		"1 5\n"
		"2 3\n"
		"5 4\n"
	;
	TEST_ASSERT_EQUAL_STRING(expect, buf);
}

int main() {
	UNITY_BEGIN();
	RUN_TEST(test_build_graph);
	RUN_TEST(test_minimum_spanning_tree_prim);
	RUN_TEST(test_minimum_spanning_tree_kruskal);
	RUN_TEST(test_shortest_path_dijkstra);
	return UNITY_END();
}
