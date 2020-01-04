SHELL := /bin/bash -O extglob
a.out: $(unity_path)/unity.c *.c
	get_h !(test).c > test.h;	\
	gcc -I $(unity_path) $(unity_path)/unity.c *.c
