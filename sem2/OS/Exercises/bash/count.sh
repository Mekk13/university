#!/bin/bash

S=0
for F in `find $1 -type f -name "*.c"`; do
        A=`grep -E "[^ ]" $F | wc -l`
        S=$(($S + $A))
done
echo $S
