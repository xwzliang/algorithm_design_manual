#!/usr/bin/env bash

rm -f a.out

# Enable extended globbing in bash
shopt -s extglob

get_h !(test).c > test.h
get_h ../02_data_structures/priority_queue.c > priority_queue.h
get_h ../02_data_structures/queue.c > queue.h
gcc -I $unity_path $unity_path/unity.c *.c ../02_data_structures/{priority_queue.c,queue.c}
./a.out

# Disable extended globbing in bash
shopt -u extglob
