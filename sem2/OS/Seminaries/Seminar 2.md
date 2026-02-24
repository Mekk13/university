	grep - search
	sed - s&r / transliterate
	awk - all
awk uses ' ' exclusively

awk 'CONDITION {ACTIONS}' file

if no conditions => true => actions are executed

awk '{print "abc"}' file

awk '{print $1}' in -> prints first column from file

awk '{print $1,$2}' in 

awk '{print FNR,NR, $1,$2}' in in2 (2 files)

NR -> global counter
FNR-> resets at the start of each file

awk 'FNR % 2 == 0 {print FNR,NR,$1}' in

NF -> how many elems on each column

$0 -> whole line 

fields = coloanele

awk '{BEGIN {print FNR}}' in
awk '{END {print FNR}}' in

vim f.awk
awk -f f.awk in2

in f.awk:
BEGIN{
	s=0
}
{
	s=s+1
}
END{
	print s
}

awk -F: '$5 ~ /( [^aeiouAEIOU]* [^aeiouAEIOU]* [^aeiouAEIOU] * ){25,}/{print $5} '

```
{
	for(i=1;i<=NF;i++){
		print "Field nr: "i" value="$1; //concatenashn boom
		print i //last block instruction doesn't need a ;
	}
}
```

awk '(NF % 2== 1) && ($1 ~ /[24680]$ /) {print FNR,NF,$0} {second action}' in2

the if doesn't work on the second action! 

__________________________________________


# BASH PROGRAMMING <3

ps -ef | awk 'NR> 1 {print $1}'  |  sort | uniq  -c


we can make a file in which we put commands 
vim l.sh :
ps -ef | awk 'NR> 1 {print $1}'  |  sort | uniq  -c

ls -l  

how do i  gain permission to execute a file???
chmod  :D

chmod u+x l.sh
chmod g+x l.sh
chmod o+x l.sh

u-user, g- group,  o- others

chmod o-wrx l.sh -> deleting permission

chmod g=r l.sh

chmod 755 l.sh
(rwx) (r-x) (r-x)

now: what do I USE to execute the file?

#!/bin/bash
->says that i want to run this file with bash <3
-> # followed by ! is a directive, not a comment

```
#!/bin/bash
while true; do
	clear
	ps -ef | awk 'NR> 1 {print $1}'  |  sort | uniq  -c
	sleep 1
done

```

echo "First" $1
echo $2
...

$# -> arg count

$(10) bc $10 takes $1 first

g="uehru"
echo $g ->writes the text

expansion
manual <3 man bash 

command substitution:

g=grep -E "." in
echo "Output: " $g ->expand with replace
can be echo "Output: $g" ->normal expand 

for x in $ g; do
	echo $x
done

arithmetic expansion:

for x in $ g; do
	echo $x
	#i=i+1
	 i=$((i+1))
done

variable assign:
i= if there is a space b4 or after the = it's NOT good




