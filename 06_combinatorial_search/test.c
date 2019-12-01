#include <stdio.h>
#include <unistd.h>
#include <unity.h>
#include "../04_graph_traversal/graph.h"
#include "test.h"

static int stdout_bk; 	// is fd for stdout backup
static int pipefd[2];
static char buf[1001];

graph g;

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

/*
void test_subsets() {
	int range_size = 3;
	stdout_capture_start();
	generate_subsets(range_size);
	stdout_capture_finish();

	char *expect =
	"{ 1 2 3 }\n"
	"{ 1 2 }\n"
	"{ 1 3 }\n"
	"{ 1 }\n"
	"{ 2 3 }\n"
	"{ 2 }\n"
	"{ 3 }\n"
	"{ }\n"
	;
	TEST_ASSERT_EQUAL_STRING(expect, buf);
}
*/

/*
void test_permutations() {
	int range_size = 3;
	stdout_capture_start();
	generate_permutations(range_size);
	stdout_capture_finish();

	char *expect =
	"[ 1 2 3 ]\n"
	"[ 1 3 2 ]\n"
	"[ 2 1 3 ]\n"
	"[ 2 3 1 ]\n"
	"[ 3 1 2 ]\n"
	"[ 3 2 1 ]\n"
	;
	TEST_ASSERT_EQUAL_STRING(expect, buf);
}
*/

void test_all_graph_paths() {
	int is_directed = 0;
	int vertex_end_index = 5;

	void initialize_graph();
	void read_graph();

	initialize_graph(&g, is_directed);
	read_graph(&g, is_directed);

	stdout_capture_start();
	generate_all_graph_paths(vertex_end_index);
	stdout_capture_finish();

	char *expect =
		"[ 1 5 ]\n"
		"[ 1 2 5 ]\n"
		"[ 1 2 3 4 5 ]\n"
	;
	TEST_ASSERT_EQUAL_STRING(expect, buf);
}


int main() {
	UNITY_BEGIN();
	/* RUN_TEST(test_subsets); */
	/* RUN_TEST(test_permutations); */
	RUN_TEST(test_all_graph_paths);
	return UNITY_END();
}
