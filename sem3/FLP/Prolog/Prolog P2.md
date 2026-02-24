P2: Lists in Prolog (2)

1.
a. Sort a list with removing the double values. E.g.: [4 2 6 2 3 4] --> [2 3 4 6]
b. For a heterogeneous list, formed from integer numbers and list of numbers, write a predicate to sort every
sublist with removing the doubles.
Eg.: [1, 2, [4, 1, 4], 3, 6, [7, 10, 1, 3, 9], 5, [1, 1, 1], 7] =>
[1, 2, [1, 4], 3, 6, [1, 3, 7, 9, 10], 5, [1], 7].

```
% a. Sort a list with removing the double values. E.g.: [4 2 6 2 3 4] --> [2 3 4 6]
% insert_sorted(E,l1..ln) = 
% = [E] , n == 0
% = l1 U insert_sorted(E,l2..ln) , E > l1
% = E U l1..ln , E < l1
%

insert_sorted(E,[],[E]).
insert_sorted(E,[E|T],[E|T]):-!. % found duplicate
insert_sorted(E,[H|T],[E,H|T]):-
    E < H, 
    !.
insert_sorted(E,[H|T],[H|Rez]):-
    E > H,
    !,
    insert_sorted(E,T,Rez).

% sortlist(l1..ln,Rez) =
% = Rez , n == 0 
% = sortlist(l2..ln,insert_sorted(l1,Rez)), otherwise

sortlist([],Acc,Acc).
sortlist([H|T],Acc,Rez):-
    insert_sorted(H,Acc,Acc1),
    !,
    sortlist(T,Acc1,Rez).
sortlist(L,R):-
    sortlist(L,[],R).
% a. Sort a list with removing the double values. E.g.: [4 2 6 2 3 4] --> [2 3 4 6]
% insert_sorted(E,l1..ln) = 
% = [E] , n == 0
% = l1 U insert_sorted(E,l2..ln) , E > l1
% = E U l1..ln , E < l1
%

insert_sorted(E,[],[E]).
insert_sorted(E,[E|T],[E|T]):-!. % found duplicate
insert_sorted(E,[H|T],[E,H|T]):-
    E < H, 
    !.
insert_sorted(E,[H|T],[H|Rez]):-
    E > H,
    !,
    insert_sorted(E,T,Rez).

% sortlist(l1..ln,Rez) =
% = Rez , n == 0 
% = sortlist(l2..ln,insert_sorted(l1,Rez)), otherwise

sortlist([],Acc,Acc).
sortlist([H|T],Acc,Rez):-
    insert_sorted(H,Acc,Acc1),
    !,
    sortlist(T,Acc1,Rez).
sortlist(L,R):-
    sortlist(L,[],R).

```

2.
a. Sort a list with keeping double values in resulted list. E.g.: [4 2 6 2 3 4] --> [2 2 3 4 4 6]
b. For a heterogeneous list, formed from integer numbers and list of numbers, write a predicate to sort every
sublist, keeping the doubles.
Eg.: [1, 2, [4, 1, 4], 3, 6, [7, 10, 1, 3, 9], 5, [1, 1, 1], 7] =>
[1, 2, [1, 4, 4], 3, 6, [1, 3, 7, 9, 10], 5, [1, 1, 1], 7].
3.
a. Merge two sorted lists with removing the double values.
b. For a heterogeneous list, formed from integer numbers and list of numbers, merge all sublists with removing
the double values.
[1, [2, 3], 4, 5, [1, 4, 6], 3, [1, 3, 7, 9, 10], 5, [1, 1, 11], 8] =>
[1, 2, 3, 4, 6, 7, 9, 10, 11].
4.
a. Write a predicate to determine the sum of two numbers written in list representation.
b. For a heterogeneous list, formed from integer numbers and list of digits, write a predicate to compute the
sum of all numbers represented as sublists.
Eg.: [1, [2, 3], 4, 5, [6, 7, 9], 10, 11, [1, 2, 0], 6] => [8, 2, 2].
5.
a. Substitute all occurrences of an element of a list with all the elements of another list.
Eg. subst([1,2,1,3,1,4],1,[10,11],X) produces X=[10,11,2,10,11,3,10,11,4].
b. For a heterogeneous list, formed from integer numbers and list of numbers, replace in every sublist all
occurrences of the first element from sublist it a new given list.
Eg.: [1, [4, 1, 4], 3, 6, [7, 10, 1, 3, 9], 5, [1, 1, 1], 7] si [11, 11] =>
[1, [11, 11, 1, 11, 11], 3, 6, [11, 11, 10, 1, 3, 9], 5, [11 11 11 11 11 11], 7]
6.
a. Determine the product of a number represented as digits in a list to a given digit.
Eg.: [1 9 3 5 9 9] * 2 => [3 8 7 1 9 8]
b. For a heterogeneous list, formed from integer numbers and list of numbers, write a predicate to replace every sublist with the position of the maximum element from that sublist.
[1, [2, 3], [4, 1, 4], 3, 6, [7, 10, 1, 3, 9], 5, [1, 1, 1], 7] =>
[1, [2], [1, 3], 3, 6, [2], 5, [1, 2, 3], 7]

```
% 6
% a. Determine the product of a number represented as digits in a list to a given digit.
% Eg.: [1 9 3 5 9 9] * 2 => [3 8 7 1 9 8]

invert([],Acc,Acc).
invert([H|T],Acc,Rez):-
    Acc1 = [H|Acc],
    invert(T,Acc1,Rez).
invert(L,R):-
    invert(L,[],R).
    
% called with reversed list
% prod(l1..ln,D,carry) = 
% = [] , n == 0 and carry == 0
% = [carry] , n == 0 and carry != 0
% = ( l1 * D + carry ) % 10 U prod(l2..ln,D, (l1*D+carry)/10 ) 

prod(_,0,_,[0]):-!.
prod([],_,C,[C]):-
    C \== 0 , 
    !.
prod([],_,_,[]):-!.
prod([H|T],D,C,[H1|Rez]):-
    H1 is (H * D + C) mod 10, 
    C1 is (H * D + C) // 10, 
    prod(T,D,C1,Rez).
prod(L,D,R):-
    invert(L,L1),
    prod(L1,D,0,R1),
    invert(R1,R).
```

7.
a. Determine the position of the maximal element of a linear list.
Eg.: maxpos([10,14,12,13,14], L) produces L = [2,5].
b. For a heterogeneous list, formed from integer numbers and list of numbers, replace every sublist with the
position of the maximum element from that sublist.
[1, [2, 3], [4, 1, 4], 3, 6, [7, 10, 1, 3, 9], 5, [1, 1, 1], 7] =>
[1, [2], [1, 3], 3, 6, [2], 5, [1, 2, 3], 7]

8.
a. Determine the successor of a number represented as digits in a list.
Eg.: [1 9 3 5 9 9] --> [1 9 3 6 0 0]
b. For a heterogeneous list, formed from integer numbers and list of numbers, determine the successor of a
sublist considered as a number.
[1, [2, 3], 4, 5, [6, 7, 9], 10, 11, [1, 2, 0], 6] =>
[1, [2, 4], 4, 5, [6, 8, 0], 10, 11, [1, 2, 1], 6]

```
% 8.
% a. Determine the successor of a number represented as digits in a list.
% Eg.: [1 9 3 5 9 9] --> [1 9 3 6 0 0]
% 
% invert(l1..ln) = 
% = [] , n == 0
% = invert(l2..ln) U l1, otherwise
% 

invert([],Acc,Acc).
invert([H|T],Acc,Rez):-
    Acc1 = [H|Acc],
    !,
    invert(T,Acc1,Rez).
invert(L,R):-
    invert(L,[],R).

% inverted nr list 
% suc(l1..ln,carry) = 
% = [] , n == 0 and carry == 0
% = [1] , n == 0 and carry != 0
% = l1+1 U l2..ln , l1 != 9
% = 0 U suc(l2..ln, 1) , l1 == 9

append1([],B,B).
append1([H|T],B,[H|Rez]):-
    append1(T,B,Rez).

suc([],C,Acc,Rez):-
    C == 1, 
    !,
    Rez = [1|Acc].
suc([],_,Acc,Acc):-!.
suc([H|T],_,Acc,Rez):-
    H == 9, 
    !,
    Acc1 = [0|Acc],
    suc(T,1,Acc1,Rez).
suc([H|T],_,Acc,Rez):-
    !,
    H1 is H + 1, 
    Acc1 = [H1|Acc],
    invert(T,T1),
    append1(T1,Acc1,Rez).
suc(L,R):-
    invert(L,L1),
    suc(L1,0,[],R).
```
9.
a. For a list of integer number, write a predicate to add in list after 1-st, 3-rd, 7-th, 15-th element a given value
e.
b. For a heterogeneous list, formed from integer numbers and list of numbers; add in every sublist after 1-st,
3-rd, 7-th, 15-th element the value found before the sublist in the heterogenous list. The list has the particularity
that starts with a number and there aren’t two consecutive elements lists.
Eg.: [1, [2, 3], 7, [4, 1, 4], 3, 6, [7, 5, 1, 3, 9, 8, 2, 7], 5] =>
[1, [2, 1, 3], 7, [4, 7, 1, 4, 7], 3, 6, [7, 6, 5, 1, 6, 3, 9, 8, 2, 6, 7], 5].
```
% a. For a list of integer number, write a predicate to add in list after 1-st, 3-rd, 7-th, 15-th element a 
% given value e.
% rule : 2^n - 1
% 1 = 2^1 - 1
% 3 = 2^2 - 1 
% 7 = 2^3 - 1
% etc.
% 
% starts with R = 1
% cp2mi(N,R) = 
% = R - 1 , N == 0
% = cp2mi(N-1,R*2) , otherwise

cp2mi(0,Acc,Res):-
    Res is Acc - 1,!.
cp2mi(N,Acc,Res):-
    Acc1 is Acc * 2, 
    N1 is N - 1,
    cp2mi(N1,Acc1,Res).
cp2mi(N,R):-
    cp2mi(N,1,R).
    

% adaf(l1..ln,crr,next,nextnr) = 
% = [], n == 0
% = l1 U E U adaf(l2..ln,crr+1,next+1, cp2mi(crr+1) ), crr+1 == nexnr
% = l1 U adaf(l2..ln,crr+1,next,nextnr), otherwise

adaf([],_,_,_,_,[]).
adaf([H|T],E,Crr,Next,Nextnr,[H,E|Rez]):-
    Crr1 is Crr + 1, 
    Crr1 == Nextnr,
    !,
    Next1 is Next + 1, 
    cp2mi(Next1,Nextnr1),
    adaf(T,E,Crr1,Next1,Nextnr1,Rez).
adaf([H|T],E,Crr,Next,Nextnr,[H|Rez]):-
    Crr1 is Crr + 1,
    !,
    adaf(T,E,Crr1,Next,Nextnr,Rez).
adaf(L,E,Rez):-
    adaf(L,E,0,1,1,Rez).
```
10.
a. For a list of integer numbers, define a predicate to write twice in list every prime number.
b. For a heterogeneous list, formed from integer numbers and list of numbers, define a predicate to write in
every sublist twice every prime number.
Eg.: [1, [2, 3], 4, 5, [1, 4, 6], 3, [1, 3, 7, 9, 10], 5] =>
[1, [2, 2, 3, 3], 4, 5, [1, 4, 6], 3, [1, 3, 3, 7, 7, 9, 10], 5]

```
ez
```

11.
a. Replace all occurrences of an element from a list with another element e.
b. For a heterogeneous list, formed from integer numbers and list of numbers, define a predicate to determine the maximum number of the list, and then to replace this value in sublists with the maximum value of sublist.
Eg.: [1, [2, 5, 7], 4, 5, [1, 4], 3, [1, 3, 5, 8, 5, 4], 5, [5, 9, 1], 2] =>
[1, [2, 7, 7], 4, 5, [1, 4], 3, [1, 3, 8, 8, 8, 4], 5, [9, 9, 1], 2]

```
% a. Replace all occurrences of an element from a list with another element e.
%
% replace(A,E,l1..ln) = 
% = [] , n == 0 
% = l1 U replace(A,E,l2..ln), l1 != A
% = E U replace(A,E,l2..ln) , l1 == A

replace(_,_,[],[]):-!.
replace(A,E,[A|T],[E|R]):-
    !,
    replace(A,E,T,R).
replace(A,E,[H|T],[H|R]):-
    H \== A,
    !,
    replace(A,E,T,R).

% b. For a heterogeneous list, formed from integer numbers and list of numbers, define a predicate to determine 
% the maximum number of the list, and then to replace this value in sublists with the maximum value of sublist.
% Eg.: [1, [2, 5, 7], 4, 5, [1, 4], 3, [1, 3, 5, 8, 5, 4], 5, [5, 9, 1], 2] =>
% [1, [2, 7, 7], 4, 5, [1, 4], 3, [1, 3, 8, 8, 8, 4], 5, [9, 9, 1], 2]

% mlist(l1..ln, max) = 
% = max , n == 0
% = mlist(l2..ln,l1), l1 > max and l1 - number
% = mmlist(l2..ln,max), l1 < max or l1 - list
%

mlist([],Acc,Acc).
mlist([H|T],Acc,Rez):-
    (   is_list(H) ; H =< Acc ),
    !,
    mlist(T,Acc,Rez).
mlist([H|T],Acc,Rez):-
    H > Acc,
    !,
    mlist(T,H,Rez).
mlist([H|T],R):-
    mlist([H|T],H,R).

% bb(l1..ln,m) = 
% = [] , n == 0 
% = l1 U bb(l2..ln) , l1 - number
% = replace(m,sublist_max,l1) U bb(l2..ln) , l1 - list

bb([],_,[]).
bb([H|T],M,[H1|Rez]):-  % question: can i put H1 like this here or do i need accumulator? Ans: Yes.
    is_list(H),
    !,
    mlist(H,MaxSublist),
    replace(M,MaxSublist,H,H1),
    bb(T,M,Rez).
bb([H|T],M,[H|Rez]):-
    number(H),
    !,
    bb(T,M,Rez).

bb([H|T],R):-
    mlist([H|T],M),
    bb([H|T],M,R).

         
```

12.
a. Define a predicate to add after every element from a list, the divisors of that number.
b. For a heterogeneous list, formed from integer numbers and list of numbers, define a predicate to add in
every sublist the divisors of every element.
Eg.: [1, [2, 5, 7], 4, 5, [1, 4], 3, 2, [6, 2, 1], 4, [7, 2, 8, 1], 2] =>
[1, [2, 5, 7], 4, 5, [1, 4, 2], 3, 2, [6, 2, 3, 2, 1], 4, [7, 2, 8, 2, 4, 1], 2]

```
% 12.
% a. Define a predicate to add after every element from a list, the divisors of that number.
% divs(A, D) = 
% = [A] , D > A/2
% = D U divs(A,D+1) , A mod D == 0 
% = divs(A, D+1), otherwise

divs(A,D,[A]):-
    D > A//2,
    !.
divs(A,D,[D|R]):-
    A mod D =:= 0,
    !,
    D1 is D + 1,
    divs(A,D1,R).
divs(A,D,R):-
    !,
    D1 is D + 1,
    divs(A,D1,R).
divs(A,R):-
    divs(A,1,R).

myappend([],B,B).
myappend([H|T],B,[H|Rez]):-
    myappend(T,B,Rez).

% diva(l1..ln) = 
% = [] , n == 0
% = l1 U divs(l1) U diva(l2..ln) , otherwise

diva([],Acc,Acc).
diva([H|T],Acc,Rez):-
    divs(H,D),
    Acc1 = [H|D],
    myappend(Acc,Acc1,Acc2),
    diva(T,Acc2,Rez).
diva(L,R):-
    diva(L,[],R).
```

13.
a. Given a linear numerical list write a predicate to remove all sequences of consecutive values.
Eg.: remove([1, 2, 4, 6, 7, 8, 10], L) will produce L=[4, 10].
b. For a heterogeneous list, formed from integer numbers and list of numbers; write a predicate to delete from
every sublist all sequences of consecutive values.
Eg.: [1, [2, 3, 5], 9, [1, 2, 4, 3, 4, 5, 7, 9], 11, [5, 8, 2], 7] =>
[1, [5], 9, [4, 7, 9], 11, [5, 8, 2], 7]
```
% a. Given a linear numerical list write a predicate to remove all sequences of consecutive values.
% Eg.: remove([1, 2, 4, 6, 7, 8, 10], L) will produce L=[4, 10].
%
% rmc(l1..ln,prev) = 
% = [] , n == 0
% = [l1] , n == 1 and l1 != prev +- 1
% = rmc(l2..ln, l1), l1 == prev +- 1 or l1 == l2 +-1
% = l1 U rmc(l2..ln, l1) , otherwise

rmc([],[],_).
rmc([E],[E],P):-
    E =\= P + 1, E =\= P - 1,
    !.
rmc([A,B|T],[A|Rez],P):-
    A =\= B + 1, A =\= B - 1,
    A =\= P + 1, A =\= P - 1,
    !,
    rmc([B|T],Rez,A).
rmc([A|T],Rez,_):-
    !,
    rmc(T,Rez,A).


rmc([H|T],Rez):-
    rmc([H|T],Rez,H).
rmc([],[]):-!.


% b. For a heterogeneous list, formed from integer numbers and list of numbers; write a predicate to delete from
% every sublist all sequences of consecutive values.
% Eg.: [1, [2, 3, 5], 9, [1, 2, 4, 3, 4, 5, 7, 9], 11, [5, 8, 2], 7] =>
% [1, [5], 9, [4, 7, 9], 11, [5, 8, 2], 7]

% hrm(l1..ln) = 
% = [] , n == 0 
% = l1 U hrm (l2..ln), l1 - not a list
% = processed(l1) U hrm(l2..ln), l1 - list

hrm([],[]).
hrm([H|T],[H|R]):-
    number(H),
    !,
    hrm(T,R).
hrm([H|T],[H1|R]):-
    is_list(H),
    !,
    rmc(H,H1),
    hrm(T,R).
% it works except for me it removes nrs tht are consecutive up and down. personal decision.
```
14.
a. Define a predicate to determine the longest sequences of consecutive even numbers (if exist more maximal
sequences one of them).
b. For a heterogeneous list, formed from integer numbers and list of numbers, define a predicate to replace
every sublist with the longest sequences of even numbers from that sublist.
Eg.: [1, [2, 1, 4, 6, 7], 5, [1, 2, 3, 4], 2, [1, 4, 6, 8, 3], 2, [1, 5], 3] =>
[1, [4, 6], 5, [2], 2, [4, 6, 8], 2, [], 3]

```
% a. Define a predicate to determine the longest sequences of consecutive even numbers (if exist more maximal
% sequences one of them).
%
% max_seq_len(l1..ln,len,maxlen) = 
% = maxlen , n == 0
% = max_seq_len(l2..ln, len+1,max(maxlen,len+1)) , l1 % 2 == 0
% = max_seq_len(l2..ln,0,maxlen), l1 % 2 != 0
%
maxi(A,B,A):-
    A > B,
    !.
maxi(_,B,B).

len([],Acc,Acc).
len([_|T],Acc,R):-
    Acc1 is Acc + 1,
    len(T,Acc1,R).
len(L,R):-
    len(L,0,R).

invert([],Acc,Acc).
invert([H|T],Acc,Rez):-
    Acc1 = [H|Acc],
    invert(T,Acc1,Rez).
invert(A,B):-
    invert(A,[],B).

% seq(l1..ln,crrs,crrl,maxs,maxl) = 
% = maxs, n == 0
% = seq(l2..ln, l1 U crrs, crrl+1, maxs, maxl ), l1 % 2 == 0 and max(maxl,crrl) = maxl
% = seq(l2..ln, l1 U crrs, crrl+1, l1 U crrs, crrl+1 ), l1 % 2 == 0 and max(maxl,crrl) = crrl
% = seq(l2..ln, [] , 0, maxs, maxl ), l1 % 2 != 0

seq([],_,_,Maxs,_,Maxs).
seq([H|T],Crrs,Crrl,Maxs,Maxl,Rez):-
    H mod 2 =:= 0,
    Crrl1 is Crrl + 1,
    maxi(Maxl,Crrl1,MM),
    MM == Maxl,
    !,
    Crrs1 = [H|Crrs],
    seq(T,Crrs1,Crrl1,Maxs,Maxl,Rez).

seq([H|T],Crrs,Crrl,_,Maxl,Rez):-
    H mod 2 =:= 0,
    Crrl1 is Crrl + 1,
    maxi(Maxl,Crrl1,MM),
    MM == Crrl1,
    !,
    Crrs1 = [H|Crrs],
    seq(T,Crrs1,Crrl1,Crrs1,Crrl1,Rez).

seq([H|T],_,_,Maxs,Maxl,Rez):-
    H mod 2 =\= 0,
    !,
    seq(T,[],0,Maxs,Maxl,Rez).

seq(L,R):-
    seq(L,[],0,[],-1,R1),
	invert(R1,R).



% b. For a heterogeneous list, formed from integer numbers and list of numbers, define a predicate to replace
% every sublist with the longest sequences of even numbers from that sublist.
% Eg.: [1, [2, 1, 4, 6, 7], 5, [1, 2, 3, 4], 2, [1, 4, 6, 8, 3], 2, [1, 5], 3] =>
% [1, [4, 6], 5, [2], 2, [4, 6, 8], 2, [], 3]

% rep(l1..ln) =
% = [] ,n == 0
% = l1 U rep(l2..ln), l1 - not a list
% = seq(l1) U rep(l2..ln), l1 - list

rep([],[]).
rep([H|T],[R|Rez]):-
    is_list(H),
    !,
    seq(H,R),
    rep(T,Rez).
rep([H|T],[H|Rez]):-
    !,
    rep(T,Rez).
    

```

15.
a. Define a predicate to determine the predecessor of a number represented as digits in a list.
Eg.: [1 9 3 6 0 0] => [1 9 3 5 9 9]
b. For a heterogeneous list, formed from integer numbers and list of numbers, define a predicate to determine
the predecessor of the every sublist considered as numbers.
Eg.: [1, [2, 3], 4, 5, [6, 7, 9], 10, 11, [1, 2, 0], 6] =>
[1, [2, 2], 4, 5, [6, 7, 8], 10, 11, [1, 1, 9] 6]

```
% a. Define a predicate to determine the predecessor of a number represented as digits in a list.
% Eg.: [1 9 3 6 0 0] => [1 9 3 5 9 9]
% 
% invert(l1..ln) = 
% = [], n == 0 
% = [] , l1 == 0 , n == 1
% = invert(l2..ln) U l1 ,otherwise

invert([],Acc,Acc).
invert([H|T],Acc,Rez):-
    invert(T,[H|Acc],Rez).
invert(L,Rez):-
    invert(L,[],Rez).

% invert but removes a leading 0 
invert_clean([],Acc,Acc).
invert_clean([0],Acc,Acc):-!.
invert_clean([H|T],Acc,Rez):-
    invert_clean(T,[H|Acc],Rez).
invert_clean(L,Rez):-
    invert_clean(L,[],Rez).

% using the inverted list -> [1,2,3,4] becomes [4,3,2,1] 
% pred(l1..ln) =
% = [] , n == 0
% = (l1-1) U l2..ln , l1 >= 1
% = 9 U pred(l2..ln) , l1 == 0

pred([],[]).
pred([H|T],[H1|T]):-
    H >= 1,
    !,
    H1 is H - 1.
pred([0|T],[H1|Rez]):-
    H1 = 9,
    pred(T,Rez).

pred_final(L,R):-
    invert(L,L1),
    pred(L1,R1),
    invert_clean(R1,R).

% b. For a heterogeneous list, formed from integer numbers and list of numbers, define a predicate to determine
% the predecessor of the every sublist considered as numbers.
% Eg.: [1, [2, 3], 4, 5, [6, 7, 9], 10, 11, [1, 2, 0], 6] =>
% [1, [2, 2], 4, 5, [6, 7, 8], 10, 11, [1, 1, 9] 6]
%
% subpred(l1..ln) = 
% = [], n == 0 
% = l1 U subpred(l2..ln) , l1-atom
% = pred_final(l1) U subpred(l2..ln) , l1 - list 

subpred([],[]).
subpred([H|T],[H|R]):-
    number(H),
    !,
    subpred(T,R).
subpred([H|T],[Rez|R]):-
    is_list(H),
    !,
    pred_final(H,Rez),
    subpred(T,R).

```