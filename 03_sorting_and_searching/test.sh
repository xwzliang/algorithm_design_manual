#!/usr/bin/env bash

rm -f a.out
get_h 0*.c > test.h
get_h ../02_data_structures/03_priority_queue.c > priority_queue.h
get_h ../02_data_structures/04_queue.c > queue.h
gcc -I $unity_path $unity_path/unity.c *.c ../02_data_structures/{03_priority_queue.c,04_queue.c}
./a.out
