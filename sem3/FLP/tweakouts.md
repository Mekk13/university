# 1 .
Write a factorial predicate (N, F) that works in all three flow models (i, i), (i, o) and (o, i).

-> cant get it to work on all 3 only i o i i or o i i i 
```
(o,i)
fact(N,F) :- 
  fact_aux(N,F,1).

fact_aux(F,F,F) :- !.

fact_aux(N,F,M) :-
  F1 is F div M,
  F mod M =:= 0,
  M1 is M+1,
  fact_aux(N,F1,M1).
```



