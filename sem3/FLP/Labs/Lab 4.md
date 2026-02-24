15. For a given n, positive, determine all decompositions of n as a sum of consecutive natural numbers
for next lab: L1 pb 9

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
% L1 pb 9

cand(N,Nr,Nr):- Nr =< N div 2.
cand(N,Nr,Res):- Nr =< N div 2, Nr1 is Nr+1, cand(N,Nr1,Res).


mySum(0,_,[]).
mySum(N,Nr,[Nr|R]):- N>=Nr, N1 is N-Nr, Nr1 is Nr+1, mySum(N1,Nr1,R).

main(N,Result):- cand(N,1,Start),mySum(N,Start,Result).

