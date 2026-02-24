#! /bin/bash

if [ $# -lt 1 ]; then
	echo "not enough args"
	exit 1
fi

dir=$1

nr=0

for file in $(find $dir -type f -name "*.c"); do
	if [ $nr -eq 2 ]; then
		exit 0
	fi
	if [ $(wc -l $file | awk '{print $1}') -gt 500 ]; then
		echo $file
		nr=$((nr+1))
	fi
done
