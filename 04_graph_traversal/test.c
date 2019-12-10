#include <stdio.h>
#include <unistd.h>
#include <unity.h>
#include "graph.h"
#include "test.h"

static int stdout_bk; 	// is fd for stdout backup
static int pipefd[2];
static char buf[1001];

static graph g;

void setUp() {}
void tearDown() {}

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
		"1:  4 2\n"
		"2:  3 1\n"
		"3:  4 2\n"
		"4:  1 3\n"
	;
	TEST_ASSERT_EQUAL_STRING(expect, buf);
}

void test_breadth_first_search() {
	int start_vertex = 1;
	stdout_capture_start();
	breadth_first_search(&g, start_vertex);
	stdout_capture_finish();

	char *expect =
		"processed vertex 1\n"
		"processed edge (1, 4)\n"
		"processed edge (1, 2)\n"
		"processed vertex 4\n"
		"processed edge (4, 3)\n"
		"processed vertex 2\n"
		"processed edge (2, 3)\n"
		"processed vertex 3\n"
	;
	TEST_ASSERT_EQUAL_STRING(expect, buf);
}

void test_find_path() {
	extern int parent[];
	stdout_capture_start();
	find_path(1, 3, parent);
	stdout_capture_finish();

	char *expect =
		"\n1 4 3"
	;
	TEST_ASSERT_EQUAL_STRING(expect, buf);
}

void test_depth_first_search() {
	int start_vertex = 1;
	initialize_search(&g);
	stdout_capture_start();
	depth_first_search(&g, start_vertex);
	stdout_capture_finish();

	char *expect =
		"processed vertex 1\n"
		"processed edge (1, 4)\n"
		"processed vertex 4\n"
		"processed edge (4, 3)\n"
		"processed vertex 3\n"
		"processed edge (3, 2)\n"
		"processed vertex 2\n"
	;
	TEST_ASSERT_EQUAL_STRING(expect, buf);
}

int main() {
	UNITY_BEGIN();
	RUN_TEST(test_build_graph);
	RUN_TEST(test_breadth_first_search);
	RUN_TEST(test_find_path);
	RUN_TEST(test_depth_first_search);
	return UNITY_END();
}
