#! /bin/bash

names=$(cat last.fake | grep -E "still" | awk '{print $1}')

for name in $names; do
	nrp=$(cat ps.fake | grep -E ^$name | wc -l)
	echo $name $nrp
done
