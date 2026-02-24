P1: Lists in Prolog (1)

# ! 
i dont get when i need cuts and when not for base case. e.g. 6b i need a cut. why.

1.
a. Write a predicate to determine the lowest common multiple of a list formed from integer numbers.
b. Write a predicate to add a value v after 1-st, 2-nd, 4-th, 8-th, … element in a list.

```
% 1.
% a. Write a predicate to determine the lowest common multiple of a list formed from integer numbers.
% b. Write a predicate to add a value v after 1-st, 2-nd, 4-th, 8-th, … element in a list.
%
% a.
% LCM = a*b / LCD
% 
% largest common divisor.
lcd(A,0,A):-!.
lcd(A,B,G):-
    R is A mod B,
    lcd(B,R,G).

lcm2(A,B,G):-
    !,
    lcd(A,B,R),
    G is (A*B)// R.

lcm([Rez],Rez):-!.
lcm([A,B|T],Rez):-
    lcm2(A,B,G),
    L1 = [G|T],
    lcm(L1,Rez).


% b. Write a predicate to add a value v after 1-st, 2-nd, 4-th, 8-th, … element in a list.
% model
% addv(E,l1..ln,count) = 
% [E], n == 0 and count - power of 2
% [] , n == 0 and not ^
% E U l1 U addv(E,l2..ln,count+1) ,  count - power of 2
% addv(E,l2..ln,count+1) , otherwise

% pow2(A,Aux) = 
% = true , Aux == A
% = pow2(A,Aux*2), Aux < A

pow2(A,A):-!.
pow2(A,Aux):-
    Aux < A,
    Aux1 is Aux * 2,
    pow2(A,Aux1).
pow2(A):-
    pow2(A,1).

addv(E,[],[E],C):-
    pow2(C),
    !.
addv(_,[],[],_).
addv(E,[H|T],[E,H|Rez],C):-
    pow2(C),
    !,
    C1 is C+1,
    addv(E,T,Rez,C1).
addv(E,[H|T],[H|Rez],C):-
    C1 is C+1,
    addv(E,T,Rez,C1).

addv(E,L,Rez):-
    addv(E,L,Rez,0).    
    
```

2.
a. Write a predicate to remove all occurrences of a certain atom from a list.
b. Define a predicate to produce a list of pairs (atom n) from an initial list of atoms. In this initial list atom has
n occurrences.
Eg.: numberatom([1, 2, 1, 2, 1, 3, 1], X) => X = [ [ 1, 4 ], [2, 2], [3, 1 ] ].

```
% 2.
% a. Write a predicate to remove all occurrences of a certain atom from a list.
% b. Define a predicate to produce a list of pairs (atom n) from an initial list of atoms. In this initial list atom has
% n occurrences.
% Eg.: numberatom([1, 2, 1, 2, 1, 3, 1], X) => X = [ [ 1, 4 ], [2, 2], [3, 1 ] ].

% a. Write a predicate to remove all occurrences of a certain atom from a list.
% model:
% rm(E,l1..ln) =
% = [], n == 0
% = l1 U rm(E,l2..ln) , l1 != E,
% = rm(E,l2..ln), otherwise.
% (i,i,o)

rm(_,[],[]).
rm(E,[H|T],[H|Rez]):-
    E \== H,
    !,
    rm(E,T,Rez).
rm(E,[_|T],Rez):-
    rm(E,T,Rez).

% b. Define a predicate to produce a list of pairs (atom n) from an initial list of atoms. In this initial list atom has
% n occurrences.
% Eg.: numberatom([1, 2, 1, 2, 1, 3, 1], X) => X = [ [ 1, 4 ], [2, 2], [3, 1 ] ].

% nrocc(A,l1..ln) =
% 0, n == 0
% 1+nrocc(A,l2..ln), l1 == A
% nrocc(A,l2..ln), otherwise

nrocc(_,[],Acc,Acc).
nrocc(A,[H|T],Acc,Rez):-
    A == H,
    !,
    Acc1 is Acc+1,
    nrocc(A,T,Acc1,Rez).
nrocc(A,[_|T],Acc,Rez):-
    nrocc(A,T,Acc,Rez).
nrocc(A,L,Rez):-
    nrocc(A,L,0,Rez).

% lp(l1..ln) =
% = [] , n == 0
% = [l1, nr_occ] U lp(s1..sn), s1..sn == remove_occ_l1(l1..ln)

lp([],[]).
lp([H|T],[L1|Rez]):-
    nrocc(H,T,Nr),
    NrO is Nr + 1,
    rm(H,T,S),
    L1 = [H,NrO],
    lp(S,Rez).
```

3.
a. Define a predicate to remove from a list all repetitive elements.
Eg.: l=[1,2,1,4,1,3,4] => l=[2,3])
b. Remove all occurrence of a maximum value from a list on integer numbers.

```

%
% a. Define a predicate to remove from a list all repetitive elements.
% Eg.: l=[1,2,1,4,1,3,4] => l=[2,3])
% 
% nrocc(A,l1..ln)=
% = 0, n == 0 
% = 1 + nrocc(A,l2..ln), l1 == A
% = nrocc(A,l2..ln), otherwise

nrocc(_,[],Acc,Acc).
nrocc(A,[H|T],Acc,Rez):-
    A == H,
    !,
    Acc1 is Acc + 1,
    nrocc(A,T,Acc1,Rez).
nrocc(A,[_|T],Acc,Rez):-
    nrocc(A,T,Acc,Rez).
nrocc(A,L,Rez):-
    nrocc(A,L,0,Rez).

% rmocc(A, l1..ln) = 
% = [], n == 0
% = l1 U rmocc(A, l2..ln), l1 != A
% = rmocc(A, l2..ln ) , otherwise

rmocc(_,[],[]).
rmocc(A,[H|T],[H|Rez]):-
    A \== H,
    !,
    rmocc(A,T,Rez).
rmocc(A,[_|T],Rez):-
    rmocc(A,T,Rez).


% rmrep(l1..ln) =
% = [], n == 0 
% = rmrep(rmocc(l1..ln)), nrocc(l1) > 1
% = l1 U rmrep(l2..n) , otherwise

rmrep([],[]).
rmrep([H|T],Rez):-
    nrocc(H,T,Nr),
    Nr \== 0,
    !,
    rmocc(H,T,S),
    rmrep(S,Rez).
rmrep([H|T],[H|Rez]):-
    rmrep(T,Rez).

% b. Remove all occurrence of a maximum value from a list on integer numbers.
%
% findmax(l1..ln, M) = 
% = M, n == 0 
% = findmax(l2..ln, l1), l1 > M
% = findmax(l2..ln,M) , otherwise
%

findmax([],Acc,Acc).
findmax([H|T],Acc,Rez):-
    H >= Acc,
    !,
    findmax(T,H,Rez).
findmax([_|T],Acc,Rez):-
    findmax(T,Acc,Rez).
findmax([H|T],Rez):-
    findmax(T,H,Rez).

%
% rmmax(l1..ln) =
% = [] , n = 0 
% = 
%
%
rmmax(L,Rez):-
    findmax(L,M),
    rmocc(M,L,Rez).
    
```

4.
a. Write a predicate to determine the difference of two sets.
b. Write a predicate to add value 1 after every even element from a list.

```
% a. Write a predicate to determine the difference of two sets.
%
% exists(A,l1..ln) = 
% true, n == 1 , A == l1
% true , A == l1
% exists(A,l2..ln), otherwise

exists(A,[A]).
exists(A,[H|_]):-
	A == H,
	!.
exists(A, [_|T]):-
    exists(A,T).

% elements from l not in s
% difference(l1..ln, s1..sm) = 
% = [], n == 0 
% = l1 U difference(l2..ln,s1..sm) , if l1 not in s1..sm
% = difference(l2..ln,s1..sm) , otherwise
%

difference([],_,[]).
difference([H|T],S,Rez):-
    exists(H,S),
    !,
    difference(T,S,Rez).
difference([H|T],S,[H|Rez]):-
    difference(T,S,Rez).


% b. Write a predicate to add value 1 after every even element from a list.
%
% add(l1..ln) = 
% = [] , n == 0 
% = l1 U 1 U add(l2..ln) , otherwise
%

add([],[]).
add([H|T],[H|[1|Rez]]):-
    add(T,Rez).


```

5.
a. Write a predicate to compute the union of two sets.
b. Write a predicate to determine the set of all the pairs of elements in a list.
Eg.: L = [a b c d] => [ [  a b] [a c] [a d] [b c] [b d] [c d  ] ].

```
%
% exists(A,l1..ln) = 
% true, n == 1 , A == l1
% true , A == l1
% exists(A,l2..ln), otherwise

exists(A,[A]).
exists(A,[H|_]):-
	A == H,
	!.
exists(A, [_|T]):-
    exists(A,T).

% union(l1..ln,s1..sm) =
% = [s1..sm] , 
% = l1 U union(l2..ln,s1..sm), l1 not in s1..sm
% =  union(l2..ln,s1..sm) , otherwise

union([],S,S).
union([H|T],S,Rez):-
    exists(H,S),
    !,
    union(T,S,Rez).
union([H|T],S,[H|Rez]):-
    union(T,S,Rez).

% b. Write a predicate to determine the set of all the pairs of elements in a list.
% Eg.: L = [a b c d] => [[a b] [a c] [a d] [b c] [b d] [c d]].
%
% pairs(E, l1..ln) =
% = [] , n == 0
% = [E,l1] U pairs(E, l2..ln) , otherwise

% append(l1..ln,s1..sm) = 
% = s1..sm , n == 0
% = l1 U append(l2..ln,s1..sm ) , otherwise

append1([],S,S).
append1([H|T],S,[H|Rez]):-
    append1(T,S,Rez).

pairs(_,[],[]).
pairs(E,[H|T],[[E,H]|Rez]):-
    pairs(E,T,Rez).

% allpairs(l1..ln) =
% = [] , n == 0 
% = pairs(l1, l2..ln) U allpairs(l2..ln) , otherwise

allpairs([],[]).
allpairs([H|T],Rez):-
    pairs(H,T,S),
    append1(S,Rez1,Rez),
    allpairs(T,Rez1).
```


6.
a. Write a predicate to test if a list is a set.
b. Write a predicate to remove the first three occurrences of an element in a list. If the element occurs less than three times, all occurrences will be removed.
```
% a. Write a predicate to test if a list is a set.
% 
% nrocc(A,l1..ln) = 
% = 0 , n == 0 
% = 1 + nrocc(A,l2..ln) , l1 == A
% = nrocc(A,l2..ln), otherwise

nrocc(_,[],Acc,Acc).
nrocc(A,[H|T],Acc,Rez):-
    A == H, 
    !,
    Acc1 is Acc + 1,
    nrocc(A,T,Acc1,Rez).
nrocc(A,[_|T],Acc,Rez):-
    nrocc(A,T,Acc,Rez).
nrocc(A,L,Rez):-
    nrocc(A,L,0,Rez).

% isset(l1..ln) = 
% = true , n == 0 
% = false , if nrocc(l1,l2..ln) > 0 
% = isset(l2..ln) , otherwise .

isset([]).
isset([H|T]):-
    nrocc(H,T,Nr),
    Nr == 0,
    isset(T).

% b. Write a predicate to remove the first three occurrences of an element in a list. 
% If the element occurs less than three times, all occurrences will be removed.
% rm(E,count,l1..ln) =
% = [] , n == 0
% = l1 U rm(E,count,l2..ln) , l1 != E
% = l1 U rm(E,count,l2..ln), l1 == E and count >= 3
% = rm(E,count+1,l2..ln), l1 == E and count < 3

rm(_,_,[],[]):-!.
rm(E,C,[H|T],[H|Rez]):-
    H \== E,
    !,
    rm(E,C,T,Rez).
rm(E,C,[H|T],Rez):-
    H == E,
    C < 3,
    !,
    C1 is C + 1,
    rm(E,C1,T,Rez).

rm(E,C,[H|T],[H|Rez]):-
    rm(E,C,T,Rez).

rm(E,L,Rez):-
    rm(E,0,L,Rez).
```


7.
a. Write a predicate to compute the intersection of two sets.
b. Write a predicate to create a list (m, ..., n) of all integer numbers from the interval [m, n].

```

% 7a. Write a predicate to compute the intersection of two sets.
%
% exists(A,l1..ln) = 
% true, n == 1 and l1 == A
% true, l1 == A
% exists(A,l2..ln) , otherwise

exists(A,[A]).
exists(A,[H|_]):-
    A == H,
    !.
exists(A,[_|T]):-
    exists(A,T).

% intersection(l1..ln,s1..sm) = 
% = [] , n == 0 
% = l1 U intersection(l2..ln,s1..sm) , l1 in s1..sm
% = intersection(l2..ln,s1..sm) , otherwise

intersection([],_,[]).
intersection([H|T],S,[H|Rez]):-
    exists(H,S),
    !,
    intersection(T,S,Rez).
intersection([_|T],S,Rez):-
    intersection(T,S,Rez).

% 7b.  Write a predicate to create a list (m, ..., n) of all integer numbers from the interval [m, n].
% create(M,N) =
% = [N] , M == N
% = M U create (M+1,N), otherwise 

create(M,M,[M]):-!.
create(M,N,[M|Rez]):-
    M < N,
    !,
    M1 is M+1,
    create(M1,N,Rez).
```

8.
a. Write a predicate to determine if a list has even numbers of elements without counting the elements from the list.
b. Write a predicate to delete first occurrence of the minimum number from a list.

```
% 8.
% a. Write a predicate to determine if a list has even numbers of elements without counting the elements
% from the list.                
% check(l1..ln) = 
% = true, n == 0 
% = false , n == 1
% = check(l3..ln)

check([]).
check([_,_|T]):-
    check(T).
```

9.
a. Insert an element on the position n in a list.
b. Define a predicate to determine the greatest common divisor of all numbers from a list.

10.
a. Define a predicate to test if a list of an integer elements has a "valley" aspect (a set has a "valley" aspect if
elements decreases up to a certain point, and then increases.
eg: 10 8 6 9 11 13 – has a “valley” aspect
b. Calculate the alternate sum of list’s elements (l1 - l2 + l3 ...).

```

% 10.
% a. Define a predicate to test if a list of an integer elements has a "valley" aspect
%  (a set has a "valley" aspect if elements decrease up to a certain point, and then increase.
% eg: 10 8 6 9 11 13 – has a “valley” aspect

% valley(l1..ln,ok) = 
% = true , n == 0 and ok == 1
% = valley(l2..ln, 0), l1 > l2 and ok == -1
% = valley(l2..ln, 0), l1 > l2 and ok == 0 
% = valley(l2..ln, 1), l1 < l2 and ok == 0
% = valley(l2..ln, 1) , l1 < l2 and ok == 1.

valley([],1).
valley([_], 1):-!.
valley([A,B|T],Ok):-
    A > B,
    (   Ok == -1 ; Ok == 0 ) ,
    !,
    valley([B|T],0).
valley([A,B|T],Ok):-
    A < B,
    (   Ok == 0 ; Ok == 1 ),
    !,
    valley([B|T],1).

valley(L):-
    valley(L,-1).
```


11.
a. Write a predicate to substitute an element from a list with another element in the list.
b. Write a predicate to create the sublist (lm, …, ln) from the list (l1,…, lk).
12.
a. Write a predicate to substitute in a list a value with all the elements of another list.
b. Remove the n-th element of a list.
13.
a. Transform a list in a set, in the order of the last occurrences of elements. Eg.: [1,2,3,1,2] is transformed in
[3,1,2].
b. Define a predicate to determine the greatest common divisor of all numbers in a list.

```
% 13.
% a. Transform a list in a set, in the order of the last occurrences of elements. 
% Eg.: [1,2,3,1,2] is transformed in [3,1,2].
%
% toset(l1..ln) =
% = [], n == 0
% = l1 U toset(l2..ln) , exists(l1,l2..ln) - false
% = toset(l2..ln) , otherwise

toset([],[]).
toset([H|T],Rez):-
    exists(H,T),
    !,
    toset(T,Rez).
toset([H|T],[H|Rez]):-
    toset(T,Rez).
```


14.
a. Write a predicate to test equality of two sets without using the set difference.
b. Write a predicate to select the n-th element of a given list.
15.
a. Write a predicate to transform a list in a set, considering the first occurrence.
Eg: [1,2,3,1,2] is transform in [1,2,3].
b. Write a predicate to decompose a list in a list respecting the following: [list of even numbers list of odd
numbers] and also return the number of even numbers and the numbers of odd numbers.