
Check if a number has only even digits
f(X):-X<10, X mod 2 =:= 0.
f(X):-X>=10, X mod 2 =:= 0, f(X div 10).

Used to need:
X1 is X div 10, f(X1).

Prolog uses backtracking 

Determine if a nr contains just 4,7 digits


```handdrawn-ink
{
	"versionAtEmbed": "0.3.4",
	"filepath": "Ink/Drawing/2025.10.1 - 23.40pm.drawing",
	"width": 684,
	"aspectRatio": 2.4963503649635035
}
```

f(4).
f(7).
f(X):-X =:= 4.
f(X):-X =:= 7.
f(X):-X mod 10 =:= 4, X1 is X div 10, f(X1).
f(X):-X mod 10 =:= 7, X1 is X div 10, f(X1).

Or operator is ;

Tail recursion is optimized because it avoids stack overflow. Final exam type shi.

Sum of all divisors other than 1 and n :


```handdrawn-ink
{
	"versionAtEmbed": "0.3.4",
	"filepath": "Ink/Drawing/2025.10.1 - 23.53pm.drawing",
	"width": 670,
	"aspectRatio": 2.168284789644013
}
```



# ! 
is going to cut from the solutions

% flow model : h(i,i,o) input output. Needs to be specified. 

f(N,X,Sum):-X>N div 2, Sum is 0. % OR  f(N,X,0):-X>N div 2, 
f(N,X,Sum):-X1 is X+1,N mod X =:= 0, f(N,X1,Sum1),
    Sum is Sum1 + X.
f(N,X,Sum):-X1 is X+1, N mod X =\= 0, f(N,X1,Sum).


Trace command:
trace, h(4,2,x) shows the stack 


Reunion (making lists) :

```handdrawn-ink
{
	"versionAtEmbed": "0.3.4",
	"filepath": "Ink/Drawing/2025.10.2 - 0.31am.drawing",
	"width": 714,
	"aspectRatio": 1.934959349593496
}
```


f(N,X,[]):-X>N div 2.
f(N,X,L):-X1 is X+1,N mod X =:= 0, f(N,X1,L1),
    L=[X|L1].
f(N,X,L):-X1 is X+1, N mod X =\= 0, f(N,X1,L).


%wrapper:
f(N,L):-f(N,2,L).

With lists i can concatenate in the call: 
f(N,X,[]):-X>N div 2.
f(N,X<mark style="background: #ABF7F7A6;">,L=[X|L1].</mark>):-X1 is X+1,N mod X =:= 0, f(N,X1,L1).
f(N,X,L):-X1 is X+1, N mod X =\= 0, f(N,X1,L).

And it's also tail recursive . Somehow . 



