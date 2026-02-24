#! /bin/bash

if [ $# -lt 1 ]; then
	echo not enough args provide a filename
	exit 1
fi
file=$1
string=""
users=$(cat $file | awk '{print $1}')
for user in $users;do
	string+="$user@scs.ubbcluj.ro, "
done
string=$(echo $string | rev | sed 's/,//' | rev) 
echo $string

