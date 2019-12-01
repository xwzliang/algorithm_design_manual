#!/usr/bin/env bash

rm -f a.out
echo "#include <stdbool.h>" > test.h

# Test subsets
# get_h subsets.c >> test.h
# gcc -I $unity_path $unity_path/unity.c backtrack.c test.c subsets.c
# ./a.out

# Test permutations
# get_h permutations.c >> test.h
# gcc -I $unity_path $unity_path/unity.c backtrack.c test.c permutations.c
# ./a.out

# Test all_graph_paths
get_h all_graph_paths.c >> test.h
gcc -I $unity_path $unity_path/unity.c backtrack.c test.c all_graph_paths.c ../04_graph_traversal/graph.c
./a.out <<-EOF
	6 7
	1 2 
	1 5 
	1 6 
	2 3 
	2 5 
	3 4 
	5 4 
EOF
