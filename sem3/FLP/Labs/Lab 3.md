P3 : 15

% 2.
% a) Sort a list with keeping double values in resulted list. 
%  E.g.: [4 2 6 2 3 4] --> [2 2 3 4 4 6]
% Mathematical model:
% my_sort(l1..ln) =
% = [] , n==0
% = insert(l1,my_sort(l2..ln)) , otherwise
%
% Mathematical model for insert:
% insert(x,l1..ln) = 
% = [x], n==0
% = x U (l1..ln), x <= l1
% = l1 U insert(x,l2..ln), otherwise
%

% (i,i,o)
insert(X,[],[X]).
insert(X,[H|T],[X,H|T]):-
    X =< H.
insert(X,[H|T],[H|Res]):-
    X>H,
    insert(X,T,Res).
   
% (i,o)
my_sort([],[]).
my_sort([H|T],Res):- 
    my_sort(T, SortedTail),
    insert(H,SortedTail,Res).

% b) For a heterogeneous list, formed from integer numbers and list of numbers,
%  write a predicate to sort every sublist, keeping the doubles.
% Eg.: [1, 2, [4, 1, 4], 3, 6, [7, 10, 1, 3, 9], 5, [1, 1, 1], 7] =>
% [1, 2, [1, 4, 4], 3, 6, [1, 3, 7, 9, 10], 5, [1, 1, 1], 7].
%
% Mathematical model:
% sort_het([l1]..[ln]) =
% [] , n==0
% l1 U sort_het([l2]..[ln]), if l1 is a number
% my_sort(l1) U sort_het([l2]..[ln]), if l1 is a list
% (i,o)
sort_het([],[]).
sort_het([H|T],[H|Res]):-
    number(H),
    sort_het(T,Res).
sort_het([H|T],[Sorted_Tail|Res]):-
    my_is_list(H),
    my_sort(H,Sorted_Tail),
    sort_het(T,Res).

% making a function that checks if a parameter is a list or not:
% my_is_list(l1..ln) =
% = True, n==0
% = my_is_list(l2..ln) , l1 - exists
% = False, otherwise
%(i)
my_is_list([]).
my_is_list([_|T]):-
    my_is_list(T).
    