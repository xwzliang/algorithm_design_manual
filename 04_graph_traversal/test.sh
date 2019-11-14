#!/usr/bin/env bash

rm -f a.out
get_h graph.c breadth_first_search.c > test.h
get_h ../02_data_structures/04_queue.c > queue.h
gcc -I $unity_path $unity_path/unity.c *.c ../02_data_structures/04_queue.c
./a.out <<-EOF
	4 4
	1 2
	2 3
	3 4
	4 1
EOF
