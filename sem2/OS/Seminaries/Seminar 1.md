mkdir  <name>=  make a directory 
ls -> see the files in the crr dir. linux

ANY LINUX based OS has a manual/can have one installed
access it with man man

man cd, man <command> 

We are allowed to use the manual for tests - we need to know how to use it :)

Regular expressions - REGEX


cat in -> look in file

GREP -> A search tool for files

grep -E "y" in /// or < / path >
-> will show the line that contains y and colors the found y
-E -> extended expression
-> fine for small files

grep -E "hore[ab]" /etc/file -> finds horea or horeb
grep -E "[y4]" /etc/file -> files that contain y OR 4 OR both

IF i wanna find the NAMES with at LEAST 5 vowels:
if i do grep -E "[a-z0-9][a-z0-9]" in -> finds the letters/digits that are next to each other

OR grep -E "[a-x0-9]{2,2}" ->  at least m at most n respectively (2 and 2)
{2}-> only a minimum

grep -E ":[a-x0-9]{2,}:" in ->find shit between 2 :
grep -E "[^:]:[a-x0-9]{2,}:" in -> ^ is not only if its in the beginning
grep -E "[^:]*:[^:]*:[a-x0-9]{2,}:" in  -> * is for as many chars as can be

grep -E "^([^:]*:){2}[a-z0-9]{2,}" in

grep -E "^([^:]*:){4}([^AEIOUaeiou:]*[AEIOUaeiou][^AEIOUaeiou:]*){5,}:" /etc/passwd

[^AEIOUaeiou:]* -> everything that's not a vowel and it repeats as many times as it wants (the *) and that can be 0 times , so we can have consecutive vowels

{n}->exactly n
{n,}->at least n
{,n}->at most n

REGEX have greedy vibes canonically speaking

"^$" ->empty line fr
grep -E -c "^$" in -> counts empty lines in file! :D

-v -> another flag that does a reverse match (on grep at least? )  => will show you the lines that DON'T respect whatever you say

-q -> makes it so that grep doesn't print shit hihi

LOWKEY BASH:
Any command is a program and has a code of return that's either success or failure . It's accessed by using $?
so , echo $?
0 is true, 1 false/error IN BASH

so if i do:
grep -E -q "^$" in 
echo $?
=> it will print 0 or 1 - if it used q or not 


SED
=> usually doesn't do JUST a search, it searches and does smth else too!

sed -E "s/d/z/" in -> search and replace d with z -> does only 1 by default
sed -E "s/[a-z]/z/g" in  -> makes them all z
sed -E "s/([a-z])/[a-z][a-z]/g" in -> sed when it sees () tries to number them. ()- group 1 , group 2, etc. You can refer to them with \1, \2 etc

sed -E "s/([a-z])/\1\1/g" in 
sed -E "s/([a-z])([a-z])/\2\2/g" in -> swaps shit up idk atp
sed -E "s/^([^:]*:){4}/" in 

\2 -> face referire la al 2-lea grup de paranteze ()

sed command in pic:

1) not separator si separator grupate cate 4!!!!!
2) al 5-lea fir al 2-lea grup
3) la fel ca prima da pt final, grupu din stanga are separator la dreapta, in dreapta la stanga , raman fix cu ce i in centru, si il reprezint prin \2 si ma duc si tai tot si raman cu centru


sed -E "s/^[^:]*://" in ->
sed -E "/3/d" in -> deletes THE WHOLE line that begins with 3! you can put [] too 

-i ca sa modifici fisieru direct 
doesnt show on screen but modifiees the file. sed doesnt modify the file directly.

swap?

transliterate :
sed -E "y/abc/123/" in 
-> replaces a w 1, bw 2 and c w 3. Strings of diff sizes don't work.








space -x to execute line by lineeeeeeeeeeeeeeee