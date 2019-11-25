#!/usr/bin/env bash

rm -f a.out
get_h graph.c minimum_spanning_tree_*.c > test.h
gcc -I $unity_path $unity_path/unity.c *.c
./a.out <<-EOF
	6 7
	1 2 2
	1 5 3
	1 6 1
	2 3 3
	2 5 2
	3 4 1
	5 4 3
EOF
