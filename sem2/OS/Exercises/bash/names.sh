#!/bin/bash

awk -F: '{print $5}' passwd.fake | \
cut -d' ' -f2- |\
sed -E 's/[ -]/\n/g' |\
grep -E -v "\.|^.$" |\
tr '[A-Z]' '[a-z]' |\
sort |\
uniq -c |\
sort -n -r |\
less
