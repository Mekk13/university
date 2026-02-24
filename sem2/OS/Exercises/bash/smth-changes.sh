#! /bin/bash

D=$1
if [ -z "$D" ]; then 
	echo "Error: no directory provided! " >&2
	exit 1
fi

if [ ! -d "$D" ];then
	echo "Error: directory does not exist! " >&2
	exit 1
fi

STATE=""
while true; do
	S=""
	for P in `find $D`; do
		if [ -f $P ]; then
			METADATA=`ls -l $P | sha1sum`
			CONTENT=`sha1sum $P`
		elif [ -d $P ]; then
			METADATA=`ls -l -d $P | sha1sum`
			CONTENT=`ls -l $P | sha1sum`
		fi
		S="$S\n$METADATA $CONTENT"
	done
	if [ -n "$STATE" ] && [ "$STATE" != "$S" ]; then
		echo "Dir state changed"
	fi
	STATE=$S
	sleep 1
done
