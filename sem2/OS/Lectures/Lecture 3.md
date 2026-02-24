find all students from 911:
where do we get the data?
how do we process it?

less /etc/passwd  -> from HERE

cut -d: -f5 /etc/passwd | grep -E " - 911 - "|sort|uniq | wc -l
cut -d: -f5 /etc/passwd | grep -E " - [^ ]+  - "|sort|uniq|wc -l
cut -d: -f5 /etc/passwd | grep -E " - [^3 ]  [^ ]+  - "|sort|uniq|less without 3

most popular names:
\ -> normal meaning
cut -d: -f5 /etc/passwd | grep -E " - [^ ]+  - "|sed -E "s/ \ ..* // "
cut -d: -f5 /etc/passwd | grep -E " - [^ ]+  - "|awk -F. '{print $1}'

"{print }" shows all as does "{print $1}"
BASH, if i use quotes , will replace $1 (with nothing). to prevent bash we use ' '

cut -d: -f5 /etc/passwd | grep -E " - [^ ]+  - "|awk -F. '{print $1}' |sort|uniq -c|sort -n -r
sorted descendingly (reverse)

cut -d: -f5 /etc/passwd | grep -E " - [^ ]+  - "|awk -F. '{print $1}' |sort|uniq -c|sort -n -r|head -n 10

-> the first 10 lines

ps shows current processes!

ps -e  -> all processes

ps -e -f -> to see the owner , also

ps -o etime  123456 (process) to see how long it ran for!

how do i only look at exam students, teachers etc?
groups ex23
ex23 exam
groups bmursa
bmursa is a wheel examiner
etc.

ps -ef gives the process id
if i wanna find out shit abt a process i need the id and owner (and maybe group)

ps -ef | while read U P X; do echo $X; done
first part in U, second in P everything else in X


shell script:

# kill all the processes in the system older than a given nr of seconds: #

```
#! /bin/bash
ps -ef |tail -n +2| while read U P X; do
		if groups $U | grep -E -q "\<exam\>|\<practice\>|\<examiner\>";then
			continue
		fi
		
		D=` ps -o etime $P $|tail -n +2|sed -E "s/^ + //"|sed -E "s/-/:/" `
		if test  -z "$D" ; then # can be done this way too
		if  [  -x "$D" ]; then # if u skip spaces here you are DEAD
			continue # this is to skip processes that are over
			
		S=0
		
		if echo $D | grep -E -q "^[0-9]+(:[0-9]+){3}$"; then
			S=` echo $D | awk -F: '{print ($1 * 24 * 60  * 60+ $2* 60 * 60 + $3* 60 + $4)}'`
		elif  echo $D | grep -E -q "^[0-9]+(:[0-9]+){2}$";then
			S=` echo $D | awk -F: '{print ($1* 60  * 60+ $2* 60 + $3)}'`
		elif echo $D | grep -E -q "^[0-9]+:[0-9]+$";then
			S=` echo $D | awk -F: '{print ($1* 60  * 60+ $2)}'`
		else
			echo "cannot parse duration \"$D\" >&2
		fi
		if [ $S -gt $1 ]; then
			echo kill $P
		fi
		# echo  $U $P $D ` ps -o etime $P ` -> its back ' ' near ~
done
```
` in order to execute whats inside
give it permissions:
chmod 700 file.sh

the header is annoying so we need to get rid of it 

ps -ef|tail -n +2
gets rid of the header because it shows starting from 2


ps -o etime 1213 |tail -n +2|sed -E "s/^ + //"|sed -E "s/-/:/" | awk -F: '{print ($1 * 24 * 60  * 60+ $2* 60 * 60 + $3* 60 + $4)}'


# UNIX PROCESSES #

ps -ef | wc -l
-> nr of processes

processes take turns at the cores of the processor <3

vim
```
#! /bin/bash
F=$1
N=0
while [ $N -lt 200 ]; do
	K=`cat $F`
	K=`expr $K =1`
	echo $k > $F  #echo prints, > redirects the output in F
	N=`expr $N +1`
done

```

./a.sh x & # this gives control back to the command line
#it runs it in the background and the script keeps running
```
#! /bin/bash
echo 0>x
./a.sh x & #concurrently runs it
./a.sh x &
./a.sh x &
```

the processes running :
Load increment store

| value | A   | B   |
| ----- | --- | --- |
| 0     |     |     |
|       | L0  |     |
|       |     | L0  |
|       | I1  |     |
|       |     | I1  |
| 1     | S1  |     |
| 1     |     | S1  |

