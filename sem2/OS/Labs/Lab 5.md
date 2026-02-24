AWK:
file.awk
NF ->Nr of (columns)
NR -> Nr of rows? (records)

awk '{print NF}' words.txt
awk '{print NR}' words.txt
awk '{print NR $0}' words.txt
awk -F: '{print NF $0}' words.txt

awk '{print NF $1}' words.txt ->first column

awk '{print NR " " $NF}' words.txt -> prints last word from each column

the keyword BEGIN b4 a block of code will cause it to be executed only once at the beginning of the file.
END -//- at the end of the file
curly brackets and BEGIN on the SAME line

using -f we are pointing to the awk script and then we give the file
awk -f a.awk words.txt

if we want even lines we do NR%2== 0
we can use as many && and || as we want


```
  1 $1 ~ /[aeiou].*[aeiou].*/ {
  2     print $1
  3 }

and run with awk -F : -f b.awk /etc/passwd

Shows: all usernames (first word) that have at least 2 vowels

OR

  1 $1 ~ /([^aeiou]*[aeiou]){2,}[^aeiou]*/ {
  2     print $1
  3 }
  
same thing

```

# SHELL scripting

file.sh

echo "Hello world!"
We need to COMPILE IT

```
sh a.sh 

OR

bash a.sh
```


#!/bin/bash
pointing out what the interpreter is (bash)
this is added at the beginning of a file
=> then , ./a.sh will work if permission is given

chmod for permission
hihi
read write execute 

-rw     r--       r--
 110   100     100

user group others
7        4         4              ---> to enable full for user and just read and write for the rest


echo command $0
$0   <=> argv[0]

echo $1 $2 $3 $4

```
  1 #!/bin/bash
  2 echo command: $0
  3 echo $1 $2 $3 $4
  4 echo $@
  5 echo $#  


./yo.sh a b c
command: ./yo.sh
a b c
a b c
3

./yo.sh a b c
command: ./yo.sh
a b c
a b c
3
a
b
c
```

