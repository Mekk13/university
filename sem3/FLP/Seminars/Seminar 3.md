% candidate(l1..lm) = 
% =(l1, l2..ln)
% =candidate(l2..ln)

candidate([H|T],H,T).
candidate([_|T],E,R):- candidate(T,E,R).

%other_cand(l1..ln, = l1, [] 
% = l1 U other_cand(l2..ln)

% main(l1..ln, c1..cm)=
% c1..cm , F = 0 
% = main(l2..ln, l1 U c1..cm,1) , l1 > c1 and F = 1
% = main(l2..ln,l1 U c1..cm,0) , l1 < c1 
% = main(l2..ln, c1..cm,F)  

main(_,Col,0,R):- rev(Col,R).
main(L,[C1|Col],_,Res):- candidate(L,E1,T1), E1 > C1, main(T1,[E1|[C1|Col]],0,Res).
main(L,[C1|Col],1,Res):- candidate(L,E1,T1), E1 < C1, main(T1,[E1|[C1|Col]],1,Res).


main(L,Res):- candidate(L,E1,T1) ,  candidate(T1,E2,T2), E1 > E2, main(T2,[E2,E1],1,Res).


% reverse:
% rev(l1..ln,c1..cm)=
% = c1..cm if n==0
% rev(l2..ln,l1 U c1..cm)

rev([],Col,Col).
rev([H|T],Col,R):- rev(T,[H|Col],R).
rev(L,R):-rev(L,[],R).

% write a number as a sum of consecutive positive integers

% N = 9 -> 4+5 or 2+3+4
% mySum(N,C) = 
% [], N == 0 
% C U mySum(N-C, C+1 ) , N > C 
% 

% candidate(N,Nr) =
% Nr, Nr < N/2
% = candidate(N,Nr+1), Nr < N / 2

%main(N) = 
% = mySum(N,candidate(N,1))


cand(N,Nr,Nr):- Nr =< N div 2.
cand(N,Nr,Res):- Nr =< N div 2, Nr1 is Nr+1, cand(N,Nr1,Res).


mySum(0,_,[]).
mySum(N,Nr,[Nr|R]):- N>=Nr, N1 is N-Nr, Nr1 is Nr+1, mySum(N1,Nr1,R).

main1(N,Result):- cand(N,1,Start),mySum(N,Start,Result).


% in a list insert all divisors before each number:

%getDiv(N,D) = 
% =  [], 0 > N/2 
% = D U getDiv(N,D+1), N % D == 0
% = getDiv(N,D+1), otherwise

getDiv(N,D,[]):- 