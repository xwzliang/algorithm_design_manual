#!/usr/bin/env bash

rm -f a.out
echo "#include <stdbool.h>" > test.h
get_h subsets.c >> test.h
gcc -I $unity_path $unity_path/unity.c *.c
./a.out
