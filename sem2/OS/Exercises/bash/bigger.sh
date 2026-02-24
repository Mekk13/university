#!/bin/bash

for A in `find $1 -type f`; do
        N=`ls -l $A | awk '{print $5}'`
        if test $N -gt $2; then
                echo $A,$N,$2
        fi
done

find $1 -type f | while read A; do
        N=`ls -l $A | awk '{print $5}'`
        if test $N -gt $2; then
                echo $A,$N,$2
        fi
done

