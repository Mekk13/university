#! /bin/bash

while true; do
	read -p "input: " X
	if test "$X" == "stop"; then
		break
	fi
done

