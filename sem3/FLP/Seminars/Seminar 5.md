preorder = RSD (root left right)
postorder = SDR (left right root)

```
; post : left - right - root
; (A 2 B 1 D 0 C 0) -> D B C A
;
; post(l1..ln, c1..ck) =
; = null , n = 0 and k = 0 
; = c1 , n = 0 
; = post(l3..ln,l1 U l2 U c1..cn ), l2 != 0
; = l1 U post(l3..ln,c1 U (c2 - 1) U ... ck ) , l2 = 0 and c2 = 2
; = l1 U c1 U post ( l3..ln, c3..ck ) , l2 = 0 and c2 = 1                            


; in - order : left - root - right 
; ( A 2 B 1 D 0 C 2 E 0 F 0 ) -> D B A E C F 
; in(l1..ln,c1..ck) =
; = null , n = 0 
; = l1 U in( l3...ln, c1..ck ),l2 = 0 and  k = 0
; = l1 U in( c1 U 0 U l3..ln, c3..ck) , l2 = 0 and c2 = 1 
; = l1 U c1 U in( l3..ln, c3..ck ), l2 = 0 and c2 = 2
; = in ( l3..ln, l1 U l2 U c1..ck), otherwise

(defun in_order(l c)
  (cond
    ((null l ) nil)
    ((= (cadr l) 0)
      (cons (car l)
        (cond 
          ((null c) (in_order (cddr l) c))
          ((= (cadr c) 1) (in_order (cons (car c) (cons 0 (cddr l ))) (cddr c) ))
          (T (cons  (car c) (in_order (cddr l) (cddr c))))
        )
      )
    )
    (T (in_order (cddr l) (cons (car l) (cons (cadr l) c))))
  )
)

(print (in_order '(a 2 b 0 c 0) nil)) ; b a c
```

map function :
-> applies a fct. on each element of a list , resulting in a list. 

```


(defun f(x)
  (list (list x))
)

(print (f 100))

(print ( mapcar #'f '(1 2 3)))
(print (list (f 1) (f 2) (f 3)))


(print ( mapcan #'f '(1 2 3)))
(print (nconc (f 1) (f 2) (f 3)))



;triple all nr atoms
; ( 1 (a (3) 2) b) -> (3 (a (9) 6) b)

; triple ( l1..ln ) = 
; = null , n= 0 
; = 3* l, l is a number
; = l, l not a number
; = triple(l1) U triple(l2) U .. U triple(ln)

(defun triple (l)
  (cond
    ((null l) nil)
    ((numberp l) (* 3 l))
    ((listp l) (mapcar #'triple l ))
    (T l)
  )
)

(print (triple '(1 (a (3) 2) b)))

```

```

(defun triple (l)
  (cond
    ((null l) nil)
    ((atom l) (list l l l))
    ((listp l) (list(mapcan #'triple l )))
  )
)

(print (car(triple '(1 (a (3) 2) b))))

```  

```
; flatten (l1..ln) = 
; = null , n = 0 
; { l } , l is atom
; flatten(l1) U ... U flatten(ln)

(defun flatten(l)
  (cond
    ((null l) nil)
    ((atom l) (list l))
    (T (mapcan #'flatten l))
  )
)
(print (flatten '(1 (2 (3) 2) 5)))
```

```
(print (apply '/ '(300 2 3)))
(print (funcall '/ 300 2 3))
(print (/300 2 3))
```

```

;count all the atoms from a list on the k-th level
; count_level( l, k ) =
; =  0, n = 0 
; = 1  , k = 0 and l is an atom
; = 0 , l is atom 
; = count_level( l1, k-1 ) + count_level( l2, k-1 ) + ... + count_level( ln, k-1 )

(defun count_level (l k)
  (cond
    ((null l) 0)
    ((and (= k 0) (atom l )) 1)
    ((atom l) 0)
    (T (apply #'+
        (mapcar #'(lambda (x) 
	        (count_level x (- k 1 ))) 
	    l)
      )
    )
  )
)

(print (count_level '(1 (2 (3 4)) (3 4 )) 2))
```

