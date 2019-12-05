#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <unity.h>
#include "test.h"

static int stdout_bk; 	// is fd for stdout backup
static int pipefd[2];
static char buf[1001];

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

void test_fib_by_recusion() {
	clock_t begin = clock();
	TEST_ASSERT_EQUAL(1134903170, fib_by_recursion(45));
	clock_t end = clock();
	float time_spent = (float)(end - begin) / CLOCKS_PER_SEC; 
	printf("time used: %fs\n", time_spent);
}

void test_fib_by_caching() {
	clock_t begin = clock();
	TEST_ASSERT_EQUAL(1134903170, fib_by_caching(45));
	clock_t end = clock();
	float time_spent = (float)(end - begin) / CLOCKS_PER_SEC; 
	printf("time used: %fs\n", time_spent);
}

void test_fib_by_dynamic_programming() {
	clock_t begin = clock();
	TEST_ASSERT_EQUAL(1134903170, fib_by_dynamic_programming(45));
	clock_t end = clock();
	float time_spent = (float)(end - begin) / CLOCKS_PER_SEC; 
	printf("time used: %fs\n", time_spent);
}


int main() {
	UNITY_BEGIN();
	/* RUN_TEST(test_fib_by_recusion); */
	RUN_TEST(test_fib_by_caching);
	RUN_TEST(test_fib_by_dynamic_programming);
	/* time used: 9.617470s */
	/* test.c:58:test_fib_by_recusion:PASS */
	/* time used: 0.000001s */
	/* test.c:59:test_fib_by_caching:PASS */
	/* time used: 0.000009s */
	/* test.c:60:test_fib_by_dynamic_programming:PASS */
	return UNITY_END();
}
