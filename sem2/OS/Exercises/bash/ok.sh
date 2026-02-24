#!/bin/bash
file=$1
if ([ -f $file ] && ([ -w $file ] || [ -r $file ] || [ -x file ])); then
        echo yes
else
        echo no
fi
