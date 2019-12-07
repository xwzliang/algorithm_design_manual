/* Problem: Integer Partition without Rearrangement */
/* Input: An arrangement S of nonnegative numbers {s1, . . . , sn} and an integer k. */
/* Output: Partition S into k or fewer ranges, to minimize the maximum sum over all the ranges, without reordering any of the numbers. */

#include <stdio.h>
#include <limits.h>

#define MAX_NUM_ELEMENTS 100
#define MAX_NUM_SUB_ARRAYS 100
#define MAX(a,b) ((a) > (b) ? (a) : (b))

void print_partition_solution(int input_arr[], int start_index, int end_index) {
	int i;

	for (i = start_index; i <= end_index; i++)
		printf(" %d ", input_arr[i]);
	printf("\n");
}

void output_partition_solution(int input_arr[], int partition_location_matrix[MAX_NUM_ELEMENTS+1][MAX_NUM_ELEMENTS+1], int num_elements, int num_sub_arrays) {
	if (num_sub_arrays == 1)
		print_partition_solution(input_arr, 1, num_elements);
	else {
		output_partition_solution(input_arr, partition_location_matrix, partition_location_matrix[num_elements][num_sub_arrays], num_sub_arrays - 1);
		print_partition_solution(input_arr, partition_location_matrix[num_elements][num_sub_arrays] + 1, num_elements);
	}
}

void minimum_sum_partition(int input_arr[], int num_elements, int num_sub_arrays) {
	/* two dimentional matrix: number of elements and number of sub arrays */
	int mini_sum_matrix[MAX_NUM_ELEMENTS+1][MAX_NUM_SUB_ARRAYS+1];
	int partition_location_matrix[MAX_NUM_ELEMENTS+1][MAX_NUM_SUB_ARRAYS+1];
	int sum_so_far_arr[MAX_NUM_ELEMENTS+1];
	int partition_cost;
	int i, j, k;

	sum_so_far_arr[0] = 0;
	for (i = 1; i <= num_elements; i++)
		sum_so_far_arr[i] = sum_so_far_arr[i-1] + input_arr[i];

	/* initialize boundaries */
	for (i = 1; i <= num_elements; i++)
		mini_sum_matrix[i][1] = sum_so_far_arr[i];	// If only one sub array, then no partition, the sum is total elements
	for (i = 1; i <= num_sub_arrays; i++)
		mini_sum_matrix[1][i] = input_arr[1];		// If only one element, then the sum is the value of first element

	for (i = 2; i <= num_elements; i++) {
		for (j = 2; j <= num_sub_arrays; j++) {
			mini_sum_matrix[i][j] = INT_MAX;
			for (k = 1; k <= i-1; k++) {
				partition_cost = MAX(mini_sum_matrix[k][j-1], sum_so_far_arr[i] - sum_so_far_arr[k]);
				/* select the minimum partition_cost */
				if (mini_sum_matrix[i][j] > partition_cost) {
					mini_sum_matrix[i][j] = partition_cost;
					partition_location_matrix[i][j] = k;
				}
			}
		}
	}
	output_partition_solution(input_arr, partition_location_matrix, num_elements, num_sub_arrays);
}
