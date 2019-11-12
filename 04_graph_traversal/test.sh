#!/usr/bin/env bash

rm -f a.out
get_h graph.c > test.h
gcc -I $unity_path $unity_path/unity.c *.c
./a.out <<-EOF
	4 4
	1 2
	2 3
	3 4
	4 1
EOF
