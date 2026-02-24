% 6. 
% a. Determine the product of a number represented as digits in a list to a given digit. 
% Eg.: [1 9 3 5 9 9] * 2 => [3 8 7 1 9 8]
% 
% Reverse(l1..ln)=
% = [] , n == 0 
% = reverse(l2..ln) U l1, otherwise
% 

reverse([],Acc,Acc).
reverse([H|T],Acc,Rez):-reverse(T,[H|Acc],Rez).

reverse(L,Rez):- reverse(L,[],Rez).

% 
% Mathematical model:
% prod(l1..ln,Carry,Digit) =
% = [Carry] , n == 0 and Carry !=0
% = [], n==0 and Carry == 0 
% = Digit* l1+Carry U prod(l2..ln,0,Digit) , Digit*l1+Carry < 10
% = (Digit* l1+Carry)%10 U prod(l2..ln,(Digit* l1+Carry)/10,Digit), Digit*l1+Carry >= 10
%

%prod([],Carry,Digit,Acc,Rez):-
prod([],Carry,_,Acc,Acc):- Carry == 0.
prod([],Carry,_,[Carry|Acc],Acc):- Carry \= 0.
prod([H|T],Carry,Digit,Acc,Rez):- 
    M is Digit*H+Carry,
    M<10,
    prod(T,0,Digit,[M|Acc],Rez).

prod([H|T],Carry,Digit,Acc,Rez):-
    M is Digit*H+Carry,
    M >= 10,
    Carry1 is M // 10,
    M1 is M mod 10,
    prod(T,Carry1,Digit,[M1|Acc],Rez).

prod(L,Digit,Rez):- 
    reverse(L,RevL),
    prod(RevL,0,Digit,[],Rez).

% no accumulator:

prod1([],Carry,_,[]):- Carry == 0.
prod1([],Carry,_,[Carry|_]):- Carry \= 0.
prod1([H|T],Carry,Digit,[M|Rez]):-
    M is Digit*H+Carry,
    M<10,
    prod1(T,0,Digit,Rez).
prod1([H|T],Carry,Digit,[M1|Rez]):-
    M is Digit*H+Carry,
    M >= 10,
    Carry1 is M // 10,
    M1 is M mod 10,
    prod1(T,Carry1,Digit,Rez).

prod1(L,Digit,Rez):- 
    reverse(L,RevL),
    prod1(RevL,0,Digit,RevRez),
    reverse(RevRez,Rez).


% make a list into a number:

list_to_nr([],Acc,Acc).
list_to_nr([H|T],Acc,Rez):- 
    Acc1 is Acc*10+H,
    list_to_nr(T,Acc1,Rez).

list_to_nr(L,Rez):-list_to_nr(L,0,Rez).

% make a number into a list:

nr_to_list(0,Acc,Acc).
nr_to_list(Nr,Acc,Rez):-
    M is Nr mod 10 ,
    Nr1 is Nr // 10,
    nr_to_list(Nr1,[M|Acc],Rez).
nr_to_list(L,Rez):-nr_to_list(L,[],Rez).

%determine the succesor
%succesor(L1..ln, Carry) = 

succesor([],0,[]).
succesor([],1,[1]).

succesor([H|T], Carry, [NewH|Res]):-
    Temp is H+Carry,
    NewH is Temp mod 10,
    NewCarry is Temp // 10,
    succesor(T,NewCarry,Res).

succ_main(L,Result):-
    reverse(L,Res),
    succesor(Res,1,Result1),
    reverse(Result1,Result).

%
% reverse(l1..ln) =
% = [] , n==0
% = reverse(l2..ln) U l1, otherwise

reverse([],Acc,Acc).
reverse([H|T],Acc,Rez):- 
    reverse(T,[H|Acc],Rez).
reverse(L,Rez):- reverse(L,[],Rez).

%sum of a nr in list reprezentation with a certain digit:
% sum(l1..ln,Digit,Carry) = 
% [], n==0 and Carry == 0 
% [Carry] , n==0 and Carry !=0 
% ( l1+Digit+Carry ) U sum(l2..ln,0, 0 ), ( l1+Digit+Carry ) < 10
% ( l1+Digit+Carry )%10 U sum(l2..ln,0, ( l1+Digit+Carry ) / 10 ), ( l1+Digit+Carry ) >= 10
%

sum([],_,Carry,Acc,Acc):- Carry == 0.

sum([],_,Carry,Acc,[Carry|Acc]):- Carry \= 0.

sum([H|T],Digit,Carry,Acc,Rez):-
    M is H+Digit+Carry,
    M < 10,
    sum(T,0,0,[M|Acc],Rez).

sum([H|T],Digit,Carry,Acc,Rez):-
    M is H+Digit+Carry,
    M >= 10,
    Carry1 is M // 10,
    M1 is M mod 10,
    sum(T,0,Carry1,[M1|Acc],Rez).

sum(L,Digit,Rez):- 
    reverse(L,RevL),
    sum(RevL,Digit,0,[],Rez).








