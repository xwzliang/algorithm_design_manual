SHELL := /bin/bash -O extglob

sources = $(unity_path)/unity.c *.c 

a.out: $(sources)
	get_h !(test).c > test.h;	\
	gcc -I $(unity_path) $(sources)

test:
	@make -s && ./a.out

clean:
	rm -rf a.out
