#!/usr/bin/env bash

rm -f a.out

get_h fibonacci.c > test.h
gcc -I $unity_path $unity_path/unity.c *.c
./a.out
