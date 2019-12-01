#!/usr/bin/env bash

rm -f a.out
echo "#include <stdbool.h>" > test.h

# Test subsets
# get_h subsets.c >> test.h
# gcc -I $unity_path $unity_path/unity.c backtrack.c test.c subsets.c

# Test permutations
get_h permutations.c >> test.h
gcc -I $unity_path $unity_path/unity.c backtrack.c test.c permutations.c

./a.out
