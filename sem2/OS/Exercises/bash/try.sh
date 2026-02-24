#!/bin/bash
echo "Command : $0"
echo "All args: $@"
echo "Arg count: $#"
for A in $@; do
        echo $A
done

for A; do
        echo Arg B: $A
done

shift 1
echo "First 3 args: $1 $2 $3"
A="grep -i -E "dan" passwd.fake | wc -l"
eval "$A"
echo $?
false
echo $?

