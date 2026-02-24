#! /bin/bash

if [ $# -lt 1 ]; then
	echo not enough args
	exit 1
fi

dir=$1
for thing in $(find $dir); do
	if [ -L $thing ]; then
		if [ ! -e $thing ]; then
			echo $thing points to something that does not exist
		fi
	fi
done
