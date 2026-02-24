#! /bin/bash

df -k -a | awk 'NR>1 {print $1, $3, $5}' | while read -r filesystem used usep; do
	if [ $used -lt 1000000 ]; then
		echo $filesystem
	elif [ $(echo $usep | sed 's/%//' | grep -E "^[0-9]+") -gt 80 ]; then
		echo $filesystem
	fi
done
