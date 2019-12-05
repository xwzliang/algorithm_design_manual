#define MAX_NUM_FIB 45
#define UNKNOWN -1
long fib_value_arr[MAX_NUM_FIB+1];


/* Fibonacci numbers by recursion */
long fib_by_recursion(int num) {
	if (num == 0)
		return 0;
	if (num == 1)
		return 1;

	return fib_by_recursion(num - 1) + fib_by_recursion(num - 2);
}


/* Fibonacci numbers by caching */
long fib_by_caching(int num) {
	int i;
	long fib_c();

	fib_value_arr[0] = 0;
	fib_value_arr[1] = 1;
	for (i = 2; i <= num; i++)
		fib_value_arr[i] = UNKNOWN;

	return fib_c(num);
}

long fib_c(int num) {
	if (fib_value_arr[num] == UNKNOWN)
		fib_value_arr[num] = fib_c(num - 1) + fib_c(num - 2);

	return fib_value_arr[num];
}


/* Fibonacci numbers by dynamic programming */
long fib_by_dynamic_programming(int num) {
	int i;

	fib_value_arr[0] = 0;
	fib_value_arr[1] = 1;
	for (i = 2; i <= num; i++)
		fib_value_arr[i] = fib_value_arr[i-1] + fib_value_arr[i-2];

	return fib_value_arr[num];
}
