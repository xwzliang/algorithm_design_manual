/*
 * Problem: Substring Pattern Matching 
 * Input: A text string t and a pattern string p. 
 * Output: Does t contain the pattern p as a substring, and if so where?
 */

#include <string.h>

int findmatch(char * pattern, char * text) {
	int len_pattern, len_text;
	int i, j;

	len_pattern = strlen(pattern);
	len_text = strlen(text);

	for (i = 0; i <= (len_text-len_pattern); i++) {
		for (j = 0; pattern[j] == text[i+j] && j < len_pattern; j++) 
			;
		if (j == len_pattern)
			return i;
	}
	return -1;
}
