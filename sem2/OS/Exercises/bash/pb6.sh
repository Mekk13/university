#! /bin/bash

if [ $# -lt 1 ]; then
	echo not enough args
	exit 1
fi

dir=$1

for f in $(find $dir -type f); do
	permissions=$(ls -l $f | awk '{print $1}')
	if echo $permissions | grep -E -q ".*w.$" ; then
		echo $permissions $f
		chmod o-w $f
		echo $(ls -l $f | awk '{print $1}') $f
	fi
done
