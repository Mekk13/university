For next time p2 Pb 2


% a)
% substitute element for another
% sub(l1..ln,x,y)
% = [] , n ==0
% = y U (l2..ln,x,y) , x == l1 
% = l1 U (l2..ln,x,y) , otherwise
% (i,i,i,o)
substitute([],_,_,[]).

substitute([H|T],X,Y,Res):-
    X == H,
    substitute(T,X,Y,Res1),
    Res = [Y|Res1].

substitute([H|T],X,Y,Res):-
    H \ == X ,
    substitute(T,X,Y,Res1),
    Res = [H|Res1].

% with tail recursion:
substitute1([],_,_,[]).
substitute1([H|T],X,Y,[Y|Res]):-
    X==H,
    substitute1(T,X,Y,Res).

substitute1([H|T],X,Y,[H|Res]):-
    H\==X ,
    substitute1(T,X,Y,Res).

% Write a predicate to create the sublist (lm, …, ln) from the list (l1,…, lk).
% sublist(l1..lk,m,n)
% = [] , k ==0 or n<1
% = sublist(l2..lk,m-1,n-1), m>1
% = l1 U sublist(l2..ln,1,n-1) , m==1 and n>1
% (i,i,i,o)

sublist([],_,_,[]).
sublist([_|T],M,N,R):- 
    M > 1,
    M1 is M-1,
    N1 is N-1,
    sublist(T,M1,N1,R).
sublist([H|T],M,N,[H|R]):-
    N >=1,
    N1 is N-1,
    sublist(T,M,N1,R).
sublist(_,_,N,[]):-
    N < 1.
    
