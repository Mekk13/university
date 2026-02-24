P3: Backtracking in Prolog

```
better candidate:
% cand(l1..ln) = 
% = (l1,l2..ln)
% = cand(l2..ln)
cand([H|T],H,T).
cand([_|T],E, R):-
	cand(T,E,R).
```


FROM COURSE:
```
%
% Write a non-deterministic predicate that
% generates combinations with k > 1 elements of a non-empty set
% whose elements are non-zero natural numbers, so that the sum
% of the elements in the combination is a given value S.
% ? combSum ([3, 2, 7, 5, 1, 6], 3, 9, C).
% /* flow model (i, i, i, o) – non-deterministic */
% /* k = 3, S = 9 */
% C = [2, 1, 6];
% C = [3, 5, 1].
% i need : candidate, combSum, combAux, constraints


% -> returns each element from a list, non-det 
% candidate(l1..ln) =
% = [l1] , n != 0
% = candidate(l2..ln) 

candidate(E,[E|_]).
candidate(E,[_|T]):-
    candidate(E,T).

% combSum(l1..ln,K,S) -> true if we get a list of K elems with Sum S.
combSum(L,K,S,C):-
    candidate(E,L),
    combAux(L,K,S,C,1,E,[E]).

% checks if a given sum and k are equal to S, K after adding element E and that E is a good
% candidate , so E < Head of the new list 
constraints(Sum,K,NewSum,NewK,NewH,E):-
    E < NewH,
    NewK < K,
    NewSum + E =< Sum.

combAux(_,K,S,C,K,S,C):-!.
combAux(L,K,S,C,NewK,NewS,[H|T]):-
    candidate(E,L),
    constraints(S,K,NewS,NewK,H,E),
    NewK1 is NewK + 1, 
    NewS1 is NewS + E, 
    combAux(L,K,S,C,NewK1,NewS1,[E,H|T]).
```


1. Write a predicate to generate the list of all subsets with all elements of a given list.
Eg: [2, 3, 4] N=2 => [ [2,3],[2,4],[3,4 ] ]

```
% Write a predicate to generate the list of all subsets with all elements of a given list.
% Eg: [2, 3, 4] N=2 => [[2,3],[2,4],[3,4]]
%

% (o,i) -> returns all elements from a given list in E, one by one. non-det.
candidate(E,[E|_]).
candidate(E,[_|T]):-
    candidate(E,T).

solution(L,Rez):-
    candidate(E,L),
    sublist(L,Rez,[E],1).

sublist(_,Rez,Rez,2):-!.
sublist(L,Rez,[H|Acc],Nr):-
    candidate(E,L),
    E < H,
    Nr1 is Nr + 1, 
    sublist(L,Rez,[E,H|Acc],Nr1).

main(L,Rez):-
    setof(R,solution(L,R),Rez).


```

2. A set of n points in a plan (represented using its coordinates) are given. Write a predicate to determine all subsets of collinear points.
```
% 2. A set of n points in a plan (represented using its coordinates) are given. 
% Write a predicate to determine all subsets of collinear points.

colinear(p(X,Y),p(X1,Y1),p(X2,Y2)):-
    %  (Y1-Y)/(X1-X) = (Y2-Y1)(X2-X1)
    (Y1-Y) * (X2-X1) =:= (X1-X) * (Y2-Y1).

candidate(E,[E|_]).
candidate(E,[_|T]):-
    candidate(E,T).

solution(L,Rez):-
    candidate(E,L),
    candidate(E1,L),
    E @< E1,
    aux(L,Rez,[E,E1]).

aux(_,Col,Col).
aux(L,Rez,[A,B|Tacc]):-
    candidate(P,L),
    P @< A,
    colinear(P,A,B),
    aux(L,Rez,[P,A,B|Tacc]).
```

3. Write a predicate to determine all decomposition of n (n given, positive), as sum of consecutive natural numbers.

```
% Write a predicate to determine all decomposition of n (n given, positive), as sum of consecutive
% natural numbers.

% cand(N,Nr)=
% = Nr , Nr =< N div 2
% = cand(N,Nr+1) , Nr =< N div 2

cand(N,Nr,Nr):-
    Nr =< N // 2.
cand(N,Nr,Rez):-
    Nr =< N // 2, 
    Nr1 is Nr + 1, 
    cand(N,Nr1,Rez).

% mysum(N,C) = 
% = [] , N == 0 
% = C U mysum(N-C, C+1) , N - C >= 0 

mysum(0,_,[]).
mysum(N,C,[C|Rez]):-
    N >= C, 
    N1 is N - C ,
    C1 is C + 1, 
    mysum(N1,C1,Rez).


solution(N,Rez):-
    cand(N,1,Start),
    mysum(N,Start,Rez).
    
```

4. The list a1... an is given. Write a predicate to determine all sublists strictly ascending of this list a.

```
% 4. The list a1... an is given. Write a predicate to determine all sublists 
% strictly ascending of this list a.

% cand(E,l1..ln) = 
% = l1 , n != 0 
% = cand(E, l2..ln ) 

cand(E,[E|_]).
cand(E,[_|T]):-
    cand(E,T).

allSubs(L,Rez):-
    cand(E,L),
    aux(L,Rez,[E]).

% any one single element is valid, because i said so .
aux(_,Col,Col).
aux(L,Rez,[HCol|TCol]):-
    cand(E,L),
    E < HCol,
    aux(L,Rez,[E,HCol|TCol]).

main(L,Rez):-
    setof(R,allSubs(L,R),Rez).
```

5. Two integers, n and m are given. Write a predicate to determine all possible sequences of numbers
from 1 to n, such that between any two numbers from consecutive positions, the absolute difference
to be >= m.

```
% 5. Two integers, n and m are given. Write a predicate to determine all possible sequences of numbers
% from 1 to n, such that between any two numbers from consecutive positions, the absolute difference
% to be >= m.

% (o,i)
cand(N,N).
cand(E,I):-
    I > 1, 
    I1 is I - 1,
    cand(E,I1).

allSeq(N,M,Rez):-
    cand(E,N),
    aux(N,M,Rez,[E]).

% once again if its just ONE number clearly it meets the conditions
aux(_,_,Acc,Acc).
aux(N,M,Rez,[HAcc|TAcc]):-
    cand(E,N),
    \+ member(E,[HAcc|TAcc]),
    Nr is abs(E - HAcc),
    Nr >= M,
    aux(N,M,Rez,[E,HAcc|TAcc]).

main(N,M,Rez):-
    setof(R,allSeq(N,M,R),Rez).
    
```

6. Generate the list of all arrangements of K elements of a given list.
Eg: [2, 3, 4] K=2 => [[2,3], [3,2], [2,4], [4,2], [3,4], [4,3]] (not necessary in this order)

```
% 6. Generate the list of all arrangements of K elements of a given list.
% Eg: [2, 3, 4] K=2 => [[2,3], [3,2], [2,4], [4,2], [3,4], [4,3]] (not necessary in this order)


cand(E,[E|_]).
cand(E,[_|T]):-
    cand(E,T).

arr(L,K,Rez):-
    cand(E,L),
    aux(L,K,Rez,1,[E]).

% i am assuming the L list has no duplicates 
aux(_,K,Acc,K,Acc).
aux(L,K,Rez,NewK,Acc):-
	cand(E,L),
    \+ member(E,Acc),
    NewK1 is NewK + 1,
    aux(L,K,Rez,NewK1,[E|Acc]).

main(L,K,Rez):-
    setof(R,arr(L,K,R),Rez).
    
```

7. A player wants to choose the predictions for 4 games. The predictions can be 1, X, 2. Write a predicate
to generate all possible variants considering that: last prediction can’t be 2 and no more than two
possible predictions X.

```
% 7. A player wants to choose the predictions for 4 games. The predictions can be 1, X, 2. 
% Write a predicate to generate all possible variants considering that: 
% last prediction can’t be 2 and no more than two possible predictions X.
% 
% so a K = 4 -> total games  
% nr_X <= 2 
% no 2 last element

cand(1).
cand(2).
cand('x').

nr_X([],0).
nr_X([H|T],Rez):-
    H == 'x', 
    !,
    nr_X(T,Rez1),
    Rez is Rez1 + 1.
nr_X([_|T],Rez):-
    nr_X(T,Rez).
    
prediction(Rez):-
    cand(E),
    E \== 2, % last one can't be 2 and we prepend so this is the last elem. 
    make_pred(Rez,1,[E]).
    
make_pred(Acc,4,Acc).
make_pred(Rez,NewK,Acc):-
    cand(E),
    NewK < 4,
    Acc1 = [E|Acc],
    nr_X(Acc1,Nr),
    Nr =< 2,
    NewK1 is NewK + 1,
    make_pred(Rez, NewK1, Acc1).
    
main(Rez):-
    findall(R,prediction(R),Rez).
    
```

8. Generate all strings of n parentheses correctly closed.
Eg: n=4 => (()) and () ()

```
% 8. Generate all strings of n parentheses correctly closed.
% Eg: n=4 => (()) and () ()

% par(N,Nr, C):-
% = [] , C == 0 and Nr == N
% = '(' U par(N, C+1), C < N div 2 , Nr < N
% = ')' U par(N, C-1) , C > 0 , Nr < N

par(N,N,0,[]).
par(N,Nr,C,['('|Acc]):-
    C < N // 2, 
    Nr < N,
    Nr1 is Nr + 1,
    C1 is C + 1, 
    par(N,Nr1,C1,Acc).
par(N,Nr,C,[')'|Acc]):-
    C > 0, 
    Nr < N,
    Nr1 is Nr + 1,
    C1 is C - 1, 
    par(N,Nr1,C1,Acc).

main(N,Rez):-
    par(N,0,0,Rez).
```

9. Generate all permutation of N (N - given) respecting the property: for every 2<=i<=n exists an 1<=j<=i,
so |v(i)-v(j)|=1.

```
% 9. Generate all permutations of N (N - given) respecting the property:
% for every 2<=i<=n exists an 1<=j<=i, so |v(i)-v(j)|=1.

% (o,i)
cand(N,N).
cand(E,I):-
    I > 1 , 
    I1 is I-1, 
    cand(E,I1).

% reverse 
reverse([],Acc,Acc).
reverse([H|T],Rez,Acc):-
    Acc1 = [H|Acc],
    reverse(T,Rez,Acc1).
reverse(L,R):-
    reverse(L,R,[]).

% (i,i)
constraints(E,L):-
    \+ member(E,L),
    A is E + 1,
    B is E - 1, 
    ( member(A,L);member(B,L) ),
    !.

perm(N,Rez):-
    cand(E,N),
    aux(N,Rez1,1,[E]),
    reverse(Rez1,Rez).

aux(N,Acc,N,Acc):-!.
aux(N,Rez,Len,Acc):-
    cand(E,N),
    constraints(E,Acc),
    Len < N, 
    Len1 is Len + 1, 
    aux(N,Rez,Len1,[E|Acc]).
```

10. For a list a1... an with integer and distinct numbers, define a predicate to determine all subsets with sum of elements divisible with n.

```
% 10. For a list a1... an with integer and distinct numbers, define a predicate to determine all 
% subsets with sum of elements divisible with n.

% (o,i)
cand(E,[E|_]).
cand(E,[_|T]):-
    cand(E,T).

len1([],0).
len1([_|T],R):-
    len1(T,R1),
    R is R1 + 1.

subs(L,Rez):-
    cand(E,L),
    len1(L,N),
    aux(L,N,Rez,E,[E]).

aux(_,N,Acc,Sum,Acc):-
    Sum mod N =:= 0,
    !.
aux(L,N,Rez,Sum,[HAcc|TAcc]):-
    cand(E,L),
    E < HAcc,
    Sum1 is Sum + E, 
    aux(L,N,Rez,Sum1,[E,HAcc|TAcc]).
```

11. “Colouring” a map. n countries are given; write a predicate to determine all possibilities of colouring n
countries with m colours, such that two adjacent countries not having the same colour.

```
% 11. “Colouring” a map. n countries are given; write a predicate to determine all possibilities 
% of colouring n countries with m colours, such that two adjacent countries won't have the same colour.
%
% i am assuming list form - e.g. :
% 10 countries, 3 colours
% one possible way: 1 2 3 1 2 3 1 2 3 1
% another : 1 2 1 2 1 2 1 2 1 3 
% etc.
% ALSO i assumed i can use AT MOST M colours , and less if i want to. And i want to.

% (o,i)
get_colour(N,N).
get_colour(E,I):-
    I > 1,
    I1 is I - 1,
    get_colour(E,I1).

colour_map(N,M,Rez):-
    get_colour(C,M),
    potential_map(N,M,Rez,1,[C]).


potential_map(N,_,Acc,N,Acc):-!.
potential_map(N,M,Rez,K,[HAcc|TAcc]):-
    get_colour(C,M),
    C \== HAcc, 
    K < N,
    K1 is K + 1, 
    potential_map(N,M,Rez,K1,[C,HAcc|TAcc]).
    
    
    
% fine here's the version with the EXACT nr of colours too
% (o,i)
get_colour(N,N).
get_colour(E,I):-
    I > 1,
    I1 is I - 1,
    get_colour(E,I1).

colour_map(N,M,Rez):-
    get_colour(C,M),
    potential_map(N,M,Rez,1,1,[C]).

% Condition -> ThenClause ; ElseClause

potential_map(N,M,Acc,N,M,Acc):-!.
potential_map(N,M,Rez,K,Nrc,[HAcc|TAcc]):-
    get_colour(C,M),
    C \== HAcc, 
    (   
    	\+ member(C,[HAcc|TAcc]) ->  Nrc1 is Nrc + 1; Nrc1 is Nrc
    ),
    K < N,
    K1 is K + 1, 
    potential_map(N,M,Rez,K1,Nrc1,[C,HAcc|TAcc]).
```

12. Generate all sub-strings of a length 2*n+1, formed from values of 0, 1 or -1, so a1 = ..., a2n+1 = 0 and
|a(i+1) - ai| = 1 or 2, for every 1 <= i <= 2n.

```
% 12. Generate all sub-strings of a length 2*n+1, formed from values of 0, 1 or -1, so:
%  a1 = ..., a2n+1 = 0 and |a(i+1) - ai| = 1 or 2, for every 1 <= i <= 2n.
%  
% fun task! what did the author mean. 
%
%
% a1 = ..., a2n+1 = 0 
% I'm assuming this means all elements can be any value from -1,0,1 except for the last one,
% which must be 0.
% 
% |a(i+1) - ai| = 1 or 2
% basically , no consecutive values can be = . 
% 
% yippee.
%

cand(-1).
cand(0).
cand(1).

solution(N,Rez):-
	aux(N,Rez,1,[0]). % last element must be 0. We add it FIRST because the list is built by prepending.

aux(N,Acc,K,Acc):-
    N1 is 2*N +1, 
    K =:= N1 , 
    !.
aux(N,Rez,K,[HAcc|TAcc]):-
    cand(E),
    K < 2*N + 1, 
    Nr is abs(HAcc - E),
    (   Nr == 1 ; Nr == 2 ) ,
    K1 is K + 1,
    aux(N,Rez,K1,[E,HAcc|TAcc]).


```

13. The list a1, ..., an is given and it consists of distinct integers. Write a predicate to determine all subsets
with aspect of "mountain" (a set has a "mountain" aspect if the elements increase to a certain point
and then decrease).

```
% 13. The list a1, ..., an is given and it consists of distinct integers.
% Write a predicate to determine all subsets with aspect of "mountain".
% (a set has a "mountain" aspect if the elements increase to a certain point and then decrease).

cand(E,[E|_]).
cand(E,[_|T]):-
    cand(E,T).

solution(L,R):-
    cand(A,L),
    cand(B,L),
    A < B ,
    generator(L,R,[B,A],0).

generator(_,Acc,Acc,1):-
    !.
generator(L,R,[H|T],Flag):-
    cand(E,L),
    \+ member(E,[H|T]),
    E > H,
    Flag == 0,
    generator(L,R,[E,H|T],0).

generator(L,R,[H|T],_):-
    cand(E,L),
    \+ member(E,[H|T]),
    E < H,
    generator(L,R,[E,H|T],1).
```

14. Write a program to generate the list of all subsets of sum S with the elements of a list (S - given).
Eg: [1,2,3,4,5,6,10] si S=10 => [[1,2,3,4], [1,4,5], [2,3,5], [4,6], [10]] (not necessary in this order)

```
done similar b4 
```

15. For a given n, positive, determine all decompositions of n as a sum of consecutive natural numbers.
```
also this 
```