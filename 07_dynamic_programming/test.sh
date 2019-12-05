#!/usr/bin/env bash

rm -f a.out

# Enable extended globbing in bash
shopt -s extglob

get_h !(test).c > test.h
gcc -I $unity_path $unity_path/unity.c *.c
./a.out

# Disable extended globbing in bash
shopt -u extglob
