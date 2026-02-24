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

find "$1" -type f | while read file; do
	md5sum $file >> temp_md5.txt
done

cut -d ' ' -f 1 temp_md5.txt | sort | uniq -d > tmp_dupe.txt

for hash in $(cat tmp_dupe.txt);do
	grep -E "$hash" temp_md5.txt | awk '{print $2}'
done

rm temp_md5.txt
rm tmp_dupe.txt

