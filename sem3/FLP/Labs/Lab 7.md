4. Write a function that returns the product of numeric atoms in a list, at any level.

```

; Write a function that returns the product of numeric atoms in a list, at any level.
; my_prod(l) = 
; = 1 , n = 0 
; = 1 , l - not numeric
; = l , l - numeric
; = my_prod(l1) * my_prod(l2) * .. * my_prod(ln) , where l = (l1..ln) otherwise

(defun my_prod (l)
  (cond
    ((null l) 1)
    ( (numberp l) l)
    ( (atom l) 1)
    (T (apply #'* (mapcar #'my_prod l) ) )
  )
)

(print (my_prod '(1 2 a (3 b (4 c) (5) ) (6))  ))

```
