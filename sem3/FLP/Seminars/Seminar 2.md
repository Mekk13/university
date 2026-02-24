% remove all uniq elems from num list
% [1 , 2 , 1, 3,3,4,7,2 ] -> 
% removeUnique(l1..ln, list_copy1..list_copyn)
%	=[], n==0
%	= l1 U removeUnique(l2..ln, list_copy1..list_copyn),
%	 countOcc(list_copy1..list_copyn,l1)>1 
%	 =removeUnique(l2..ln,list_copy1..list_copyn),
%	 countOcc(list_copy1..list_copyn,l1)==1
%	 (i,i,o)

removeUnique([], _ , []).
%removeUnique([H|T], L, Res):- countOcc(L,H,Count), Count >1,
%    removeUnique(T,L,Res1), Res = [H|Res1].

% [H|T], L, - bounded 
% H|Res this has different meanings depending on case - for output it will be 'remade' with 
%backtracking at the end so created then - its a reunion of all the H pieces that have passed all conditions 
removeUnique([H|T], L, [H|Res]):- %to make it tail recursive - recursive call is last 
    countOcc(L,H,Count), Count >1,
    removeUnique(T,L,Res).
removeUnique([H|T], L, Res):-
    countOcc(L,H,Count), Count =:= 1,
    removeUnique(T,L,Res).

removeUnique(L,R):- removeUnique(L,L,R).

%counts the nr of occ of an elem in a list 
% countOcc(l1,..,ln,elem) = 0 , if n==0 (l==[])
% =1 + countOcc(l2,..,ln,elem) if l1==elem
% = countOcc(l2,..,ln,elem), otherwise
% (i, i , o) 

%countOcc(List, _, Res):-List =[], Res is 0.
countOcc([], _, 0).

% H is the first elem, T is the list of all the rest . it splits list. 
% H =:= Elem, ??
countOcc([H|T],H,Res):- 
    countOcc(T,H,Res1),
    Res is Res1 + 1.

% optimised
countOcc([H|T],Elem,Res):- 
    H =\= Elem,
    countOcc(T,Elem,Res).

% tail rec. count occ: (i,i,i,o)
c2([],_,R,R).
c2([H|T],H,Col,Res):- 
    Col1 is Col+1, % because its input parameter
    c2(T,H,Col1,Res).
c2([H|T],Elem,Col,Res):- 
    H =\= Elem,
    c2(T,Elem,Col,Res).

c2(L,Elem,R):- c2(L,Elem,0,R).


%reverse a list: (i,i,o)
rev([],Col,Col).
rev([H|T],Col,R):- rev(T,[H|Col],R).


%check if a nr is prime: (i,i)
% isPrime(N,D) = 
%	= true , D>N/2
%	= isPrime(N,D+1), N%D != 0
isPrime(N,D):- D>N div 2.
isPrime(N,D):- N mod D =\= 0, D1 is D+1, isPrime(N,D1).
isPrime(N):-N >1, isPrime(N,2).

%duplicate every prime nr in a list
%duplicatePrimes(l1..ln) =
%	=[], n==0
%	=l1 U l1 U duplicate(l2..ln), isPrime(l1)
%	= l1 U duplicate(l2..ln), otherwise
duplicatePrimes([],[]).
duplicatePrimes([H|T],[H,H|R]):- isPrime(H), duplicatePrimes(T,R). % or H | [H|R]
duplicatePrimes([H|T],[H|R]):-not(isPrime(H)),duplicatePrimes(T,R).




