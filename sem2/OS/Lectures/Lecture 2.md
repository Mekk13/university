Problem:

copy file to another with .c and fix problems using valgrind
mv fixit.c fixit.txt
mv fixit.txt tc.txt
vim tc.txt
gcc -Wall -Wextra -Werror -g -o a a.c
viim tc.txt
ls
cp tc.txt a.c
gcc -Wall -Wextra -Werror -g -o a a.c

implicit declaration -> you need to add the header file
whatis write -> man 2 write

run with ./a
cat out.txt to see contents


valgrind ./a to see hidden problems

only syntax and memory - no logic errors


---------------------------------------
shell programming

standard   input  0
        output 1 
        error   2

in linux everything is a file. 
Every program has an array of open files. When it starts - first 3 are in out and error. 
stdin , stdout, stderr 

ctrl c to stop a program 
ctrl d will stop a file

```
int main(){
	char s[64];
	int i;
	char *p;
	while(1){
		p=fgets(s,64,stdin);
		if(p==NULL)
			break;
		for(i=0;i<(int)strlen(s);i++)
			if(s[i]!='\n)
				s[i]='*';
		fputs(s,stdout);
	}
	return 0;
}

```

echo xxuui > x
cat x-> xxuui

 for append: >>

./b < x  -> reads from file b

excho lalala | ./b  

---------------------------

if i say rm -> command that removes a file

to redirect errors you use 2> file

cat x t
contentx of x
error t doesnt exist

cat x t > y 2>&1 //with the ampersand it takes the address of the first elem so i think first file

/dev/null anything you write here dissapears <3
in windows its NUL

for arrays you need to pass the length explicitly.

sed "s/.* /g"

-------------------------------------------------------

for the command line 0 is true , everything else is false

true
echo $?
0

true || echo ashsds
prints nothing

false || echo lala
lala

the command test exists :3 i also exist
test -f ke || echo not there
not there if file ke doesnt exist

test 1 -eq 2 || echo nope
nope

test -z "okay" || not empty
not empty

! test -n "lala" || echo not empty
not empty


VARIABLES IN SHELL:

A=6 
b=7
c="okaey"
echo $A
6
echo $A $b
6 7 


E=tom
echo $(E)cat
tomcat


who | wc -l
4

N=` who |wc -l `
the output of the command is in N
its with the ' near ~

C="ps -ef"
$C -> executex the comand in C

_________________________________________________

shell scripts <3 any file that contains commands

vim c.sh
//write whatever
./c sh
Permission denied

ls -l
permissions:

rwxr - xr -x
010

user
rwx -read write execute
010

group
rwx
101 

other
rwx
111

chmod - to change permissions

chmod 700 c.ch

vim c.sh 
#! /bin/bash 
so that it will always be interpreted by bash . can be anythng like python.

```
#! /bin/bash 

echo command $0 
echo first four args $1 $2 $3 $4
echo all args $@
echo all args $*
echo arg count $#

# ./c.sh a b c d e f g h i j k l m 

echo =======================================

shift 5
echo command $0 
echo first four args $1 $2 $3 $4
echo all args $@
echo all args $*
echo arg count $#

```

FOR:
its more like the for each in python than the c one

```
#! /bin/bash 
for X in cat dog cow mouse bear ; do
	echo Here is another animal that i know of: $X
done
# ./d.sh

for F in *.c; do
	wc -l $F
done
# shows the nr of lines in that file

for F in $@; do
	echo arg $F
done

for F; do
	echo arg $F
done

#these 2 just iterate thru the args 


```

IF:
really simple <3
if ...;then
elif ..; then
else ..; then
fi -> to close i think


```
#! /bin/bash 
for A in $@; do
	if test -f $A ; then
		echo $A is a file
	elif test -d $A
	then 
		echo $A is a directory
	elif echo $A | grep -E -q "^[0-9]+$";then
		echo $A is a number
		if test $A -gt 5; then
			echo $A is a number greater than 5
		fi
	else
		echo Not sure what $A is 
	fi
done

```

WHILE:
if and for combined

```
#! /bin/bash 
while true; do 
	read -p "Give 2 nrs: " X Y 
	if echo $X | grep -E -q "^[0-9]+$" && \
	   echo $Y | grep -E -q "^[0-9]+$" && \
	   test $X -gt $Y; then
	    break
	fi
done


```