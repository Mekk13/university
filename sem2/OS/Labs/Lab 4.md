Shell - > c
Bash -> c++
conceptually . anything you can do in shell you can do in bash. 

# grep 

regular expressions - a mechanism which allows you to define patterns for strings

grep -E "what to find" wheretofind.txt in greedy hihi

/etc/passwd is a file thats an os file and it holds all the usernames from a given server. SO if we connect to the server you can use this.

. -> means anything (1 character)
everything between [] is considered as an OR   [a-z] from a to z <3
[aeiou]
case sensitive 
[a-zA-Z]
[0-9]

a[a-z]+a goes on and on until we find them ALL
```
* is none or more
```

^|a -> from the beginning of the line
|$ end of the line

^|a[a-z]+a|$ so gets all that begin and start with a

[^a-z] if ^ is inside [] its a NEGATION

^$ -> since the beginning until the end there is nothing so this matches empty lines (replaces \n)

example:
no numbers in user:

^[a-z]+ :   

grep -E "^[^0-9:]+:" /etc/passwd -> you also dont wanna match the : otherwise it goes for as long as it can!

# Hardest example in the teaching notes 🔥🔥🔥🔥

We wanna match all the usernames which have at least 2 vowels in the username. 
```
grep -E "^[^:]*[aeiou][^:]*[aeiou][^:]*:" /etc/passwd
```
Basically as many times as possible anything(except for ":" ), vowel , -//- , vowel, -//- 

we can group up repeating things! {2,} means from 2-> inf

```
 grep -E "^[^:]*([aeiou][^:]*){2,}:" /etc/passwd
```

exactly 2 vowels:

```
grep -E "^[^aeiou:]*([aeiou][^aeiou:]*){2}:" /etc/passwd
```

to make case insensitive we use -E -i

# SED 
-> case insensitive is  -i
->finds and replaces a pattern with a replacement and returns the file as it being replaced without actually modifying it

**MODES**

1) substitute:
	s/find/replace/ 
	->replaces the first instance not everything
	 -> if you use g it replaces all: s/find/replace/g. hi for case insensitve
	 
2) delete:
	-> /find/d
3) y
	-> y/aei/a3!/  => replaces one by one a->a, e->3 i->!

For groups we can us e\1 \2 -> first and second regular expression groups
ex: letter digit -> digit letter

```
sed -E  "s/([a-z])([0-9])/\2 \1/gi"
```

# Cool website 🔥🔥🔥🔥 🥺😔

https://regex101.com



