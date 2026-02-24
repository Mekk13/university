#!/bin/bash

while true; do
        read X
        if test "$X" == "stop"; then
                break
        fi
        echo $X
done

