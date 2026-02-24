#!/bin/bash
for A in `find $1`; do
        if test -f $A; then
                echo "$A is a file"
        elif test -d $A; then 
                echo "$A is a directory"
        else
                echo "we have no idea what $A is"
        fi
done
