#!/bin/bash


while [ 1 ]; do
	ps -ef | grep hello.exe | wc > test.file
	n_line=$(awk '{print $1}' test.file)
	if [ "$n_line"=="1" ]; then
		./hello.exe
	fi
done
