#! /bin/bash

if [ $# -lt 1 ]; then
	echo not enough args
	exit 1
fi

dir=$1

for file in $(find $dir -type f -name "*.log"); do
	sort $file -o $file
done
