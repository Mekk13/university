test -f tests if its a file
the value of a variable is taken by using a $ in front

test -f $A checks if its a file
test -d $A checks if its a directory


if test -f $A; then
if [ -f $A ]; then 
-> the same but leave spaces for [  ]

```
if we wanna store code into a variable we use ` `
```

ls -l a.txt -> shows metadata of a.txt
cat a.txt -> shows content of a.txt

ls -l -d  dir -> shows metadata of directory

We use sha1sum to get a checksum that is statistically impossible to be identical for different contents

always 32 bites -> if its the same state the bytes are in the same order with no changes

-n i s checking is $STATE is empty or not 
if -n "$STATE" means non empty


