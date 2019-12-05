#define MAX_NUM_BINO 1000

/* from n elements choose k elements */
long binomial_coefficient(int n, int k) {
	int i, j;
	long bino_table[MAX_NUM_BINO][MAX_NUM_BINO];

	for (i = 0; i <= n; i++)
		bino_table[i][0] = 1;
	for (j = 0; j <= n; j++)
		bino_table[j][j] = 1;

	for (i = 1; i <= n; i++)
		for (j = 1; j < i; j++)
			bino_table[i][j] = bino_table[i-1][j-1] + bino_table[i-1][j];	// Use Pascal's triangle

	return bino_table[n][k];
}
