#!/usr/bin/env bash

for dir in */; do
	cd $dir
	echo $dir
	./test.sh
	echo -e "\n"
	cd ..
done
