Except for problems 4 and 9, conversion between types is not allowed; a direct method should be
used instead.

1. For a given tree of type (1) return the path from the root node to a certain given node X.
```
; For a given tree of type (1) return the path from the root node to a certain given node X.

; l(l1..ln,children, nrc) = 
; = () , children == nrc
; = (l1 l2) U l(l3...ln, children + l2, nrc +1) ,otherwise

(defun l(l c nrc)
  (cond
    ((equal c nrc) nil)
    (t (cons 
      (car l)
      (cons
        (cadr l)
        (l (cddr l) (+ c (cadr l)) (+ nrc 1) )
      )
    ))
  )
)

; left(l1..ln) = 
; = (), n == 0 
; = l(l3..ln,1,0)

(defun left(l)
  (cond
    ((null l) nil)
    (t (l (cddr l) 1 0 ))
  )
)

; (print (left '( A 2 B 1 D 0 C 2 E 1 I 0 F 2 J 0 K 0 ) ))

; r(l1..ln,children,nrc) =
; = (l1..ln) , children == nrc
; = lr(l3...ln, children + l2, nrc +1) , otherwise

(defun r(l c nrc)
  (cond
    ((equal c nrc) l)
    (t 
      (r (cddr l) (+ c (cadr l)) (+ nrc 1) )
    )
  )
)

(defun right(l)
  (cond
    ((null l) nil)
    (t (r (cddr l) 1 0))
  )
)

; (print (right '( A 2 B 1 D 0 C 2 E 1 I 0 F 2 J 0 K 0 ) ))

; is_in(l1..ln,x) =
; = false, n == 0
; = true , l1 == X
; = is_in(l3..ln,x), otherwise

(defun is_in(l x)
  (cond
    ((null l) nil)
    ((equal (car l) x) t)
    (t (is_in (cddr l) x))
  )
)

; findp(l1..ln,x) = 
; = l1 , l1 == x
; = l1 U findp(left-subtree,x) , if x is in left-subtree
; = l1 U findp(right-subtree,x) , if x is in right-subtree

(defun findp(l x)
  (cond
    ((equal (car l) x) (list (car l)))
    ((is_in (left l) x ) (cons (car l) (findp (left l) x)  )  )
    (t (cons (car l) (findp (right l) x )))
  )
)

(defun findt(l x)
  (cond
    ( (not (or (is_in (left l) x) (is_in (right l) x) ) ) nil)
    (t (findp l x))
  )
)

(print (findt '( A 2 B 1 D 0 C 2 E 1 I 0 F 2 J 0 K 0 ) 'K))

```

2. Return the list of nodes on the k-th level of a tree of type (1).
```

; l(l1..ln,children, nrc) = 
; = () , children == nrc
; = (l1 l2) U l(l3...ln, children + l2, nrc +1) ,otherwise

(defun l(l c nrc)
  (cond
    ((equal c nrc) nil)
    (t (cons 
      (car l)
      (cons
        (cadr l)
        (l (cddr l) (+ c (cadr l)) (+ nrc 1) )
      )
    ))
  )
)

; left(l1..ln) = 
; = (), n == 0 
; = l(l3..ln,1,0)

(defun left(l)
  (cond
    ((null l) nil)
    (t (l (cddr l) 1 0 ))
  )
)

; (print (left '( A 2 B 1 D 0 C 2 E 1 I 0 F 2 J 0 K 0 ) ))

; r(l1..ln,children,nrc) =
; = (l1..ln) , children == nrc
; = lr(l3...ln, children + l2, nrc +1) , otherwise

(defun r(l c nrc)
  (cond
    ((equal c nrc) l)
    (t 
      (r (cddr l) (+ c (cadr l)) (+ nrc 1) )
    )
  )
)

(defun right(l)
  (cond
    ((null l) nil)
    (t (r (cddr l) 1 0))
  )
)


(defun myappend(a b)
  (cond
    ((null a) b)
    (t (cons (car a) (myappend (cdr a) b)))
  )
)

; klev(k,cnt,l1..ln) = 
; = () , n == 0 
; = l1  , cnt == k
; = klev(k,cnt+1,left(l)) U klev(k,cnt+1,right(l)) , cnt < k

(defun klev(k cnt l)
  (cond
    ((null l) nil)
    ((equal cnt k) (list (car l)))
    ((> cnt k) nil)
    (t 
      (myappend
        (klev k (+ cnt 1 ) (left l))
        (klev k (+ cnt 1 ) (right l))
      )
    )
  )
)

(defun klevel (k l)
  (klev k 0 l)
)

(print (klevel 2 '( A 2 B 1 D 0 C 2 E 1 I 0 F 2 J 0 K 0 ) ))
```

3. Return the number of levels of a tree of type (1).
```
; level(l1..ln) = 
; = 0 , n == 2 ( only one node left)
; = 1+max(level(left l), level(right l))

(defun level(l)
  (cond
    ((equal (cddr l) nil) 0)
    (t (+ 1 (max
      (level (left l))
      (level (right l))
    )))
  )
)
```

4. Convert a tree of type (2) to type (1).
```
; Convert a tree of type (2) to type (1).
; (A (B) (C (D) (E)))   
; convert(l1 l2 l3) = 
; = null , l - empty
; = (l1 0 ), l2 - null 
; = (l1 2) U convert(l2) U convert(l3) , l2 , l3 - not null
; = (l1 1) U convert(l2) , l2 - not null 

(defun convert(l)
  (cond
    ((null l) nil)
    ((null (cadr l)) (list (car l) '0) )
    ((and (not (null (cadr l))) (not (null (caddr l))) )
      (append
        (list (car l) '2)
        (append
          (convert (cadr l))
          (convert (caddr l))
        )
      )
    )
    (t (append
        (list (car l) '1)
        (convert (cadr l))
      )
    )
  )
)
```

5. Return the level (depth) of a node in a tree of type (1). The level of the root element is 0.
```
; depth(l1..ln,x) = 
; = 0 , l1 == x
; = nil , n == 0  
; = nil , l1 has no children
; = 1 + depth(left(l)) , if depth(left(l)) is a number
; = 1 + depth(right(l)), if depth(right(l)) is a number

(defun depth(l x)
  (cond
    ((null l) nil)
    ((equal (car l) x) 0)
    ((equal (cadr l) 0) nil)
    (t
      ((lambda (L R)
        (cond
          (L (+ 1 L))
          (R (+ 1 R))
          (t nil)
        )
      ) (depth (left l) x ) (depth (right l) x) )
    )
  )
)
```

6. Return the list of nodes of a tree of type (1) accessed inorder.
```
; in(l1..ln,c1..ck) =
; = null  , n == 0
; = l1 U in(l3..ln, c1..ck) , l2 == 0 and k == 0 
; = l1 U in(c1 U 0 U l3..ln,c3..ck) , l2 == 0 and c2 == 1
; = l1 U c1 U in(l3..ln, c3..ck) , l2 == 0 and c2 == 2
; = in(l3..ln,l1 U l2 U c1..ck), otherwise

(defun in(l c)
  (cond
    ((null l) nil)
    ((= (cadr l) 0)
      (cons (car l)
        (cond
          ((null c) (in (cddr l) c) )
          ((= (cadr c) 1) (in (cons (car c) (cons 0 l)) c ) )
          (t (cons (car c) (in (cddr l) (cddr c) )))
        )
      )
    )
    (t (in (cddr l) (cons (car l) (cons (cadr l) c ))))
  )
)
```

7. Return the level of a node X in a tree of type (1). The level of the root element is 0.
```
like 5
```

8. Return the list of nodes of a tree of type (2) accessed inorder.
```

; in(l1 l2 l3) = 
; = null, l - empty 
; = in(l2) U l1 U in(l3), otherwise

(defun in(l)
  (cond
    ((null l) nil)
    (T (append 
      (in (cadr l))
      (append
        (list (car l))
        (in (caddr l))
      )
    ))
  )
)

```

9. Convert a tree of type (1) to type (2).
```
??? your mother.
```

10. Return the level of a node X in a tree of type (2). The level of the root element is 0.
```

; Return the level of a node X in a tree of type (2). The level of the root element is 0.
; level(l1 l2 l3 x) =
; = 0 , l1 == x
; = null , n == 0 
; = 1 + level(l2) , if level(l2) returns a number
; = 1 + level(l3) , if level(l3) returns a number

(defun level(l x)
  (cond
    ((null l) nil)
    ((equal (car l) x) 0)
    (t (
      (lambda (L R)
        (cond
          (L (+ 1 L))
          (R (+ 1 R))
          (t nil)
        )
      ) (level (cadr l) x) (level (caddr l) x) )
    )
  )
)

```

11. Return the level (and coresponded list of nodes) with maximum number of nodes for a tree of type (2). The level of the root element is 0.
```
; Return the level (and coresponded list of nodes) with maximum number of nodes for a tree of type (2). 
; The level of the root element is 0.

; get_level(l1 l2 l3 k) = 
; = null , l is empty 
; = l1 , k == 0 
; = get_level(l2,k-1) U get_level(l3,k-1)

(defun get_level(l k)
  (cond
    ((null l) nil)
    ((= k 0) (list (car l)))
    (t 
      (append
        (get_level (cadr l) (- k 1))
        (get_level (caddr l) (- k 1))
      )
    )
  )
)

(print (get_level '(A (B (D))   (C (E (I)) (F (J) (K)) )) 0 ))

; nr of nodes on a level k 
; nr_nodes(l1 l2 l3 k) = 
; = 0 , l -empty
; = 1 , k == 0 
; = nr_nodes(l2, k-1) + nr_nodes(l3 , k-1)

(defun nr_nodes(l k)
  (cond
    ((null l) 0)
    ((= k 0) 1)
    (t (+ (nr_nodes (cadr l) (- k 1) ) (nr_nodes (caddr l) (- k 1) ) ))
  )
)

(print (nr_nodes '(A (B (D))   (C (E (I)) (F (J) (K)) )) 1 ))

; depth(l1 l2 l3)
; = 0 , l2 -empty
; = 1 + max(depth(l2), depth(l3))

(defun depth(l)
  (cond
    ((null (cadr l)) 0)
    (t (+ 1 (max (depth (cadr l) ) (depth (caddr l)) ) ) )
  )
)

(print (depth '(A (B (D))   (C (E (I (L))) (F (J) (K)) )) ) )


; max_level(l1..ln, maxi,ml, deep) = 
; = null , n == 0
; = maxi , deep = 0
; = max_level(l1..ln, nr_nodes(l1..ln,deep) ,deep,deep-1 ) , nr_nodes(l1..ln, deep) > maxi 
; = max_level(l1..ln, maxi ,ml, deep-1 ) , otherwise

(defun max_level(l m ml d)
  (cond
    ((null l) 0)
    ((= d 0) ml)
    (t (cond
      ((> (nr_nodes l d) m ) (max_level l (nr_nodes l d) d (- d 1) ))
      (t (max_level l m ml (- d 1) ) )
    ) )
  )
)


(print (max_level '(A (B (D))   (C (E (I)) (F (J) (K)) )) 0 0 3 ))


(defun final(M l)
  (setq M (max_level l 0 0 (depth l)) )
  (get_level l M)
)

(print (final 'M '(A (B (D))   (C (E (I)) (F (J) (K)) )) ))
```

12. Determine the list of nodes accessed in preorder in a tree of type (2).
```
; pre(l1 l2 l3) = 
; = null , l1 - empty
; = l1 U pre(l2) U pre(l3)

(defun pre(l)
  (cond
    ((null l) nil)
    (t 
      (append
        (list (car l) )
        (append
          (pre (cadr l))
          (pre (caddr l))
        )
      )
    )
  )
)

(print (pre '(1 (2 (4) (5)) (3 (6)) ) ))
```

13. For a given tree of type (2) return the path from the root node to a certain given node X.
```

```

14. Determine the list of nodes accessed in postorder in a tree of type (1).
```
; post(l1..ln, c1..ck) =
; = null , n = 0 and k = 0 
; = c1 , n = 0 
; = post(l3..ln,l1 U l2 U c1..cn ), l2 != 0
; = l1 U post(l3..ln,c1 U (c2 - 1) U ... ck ) , l2 = 0 and c2 = 2
; = l1 U c1 U post ( l3..ln, c3..ck ) , l2 = 0 and c2 = 1                           

(defun post(l c)
  (cond
    ((and (null l) (null c)) nil)
    ((null l) (list (car c)) )
    ((not (zerop (cadr l)) ) (post (cddr l) (cons (car l) (cons (cadr l) c )) )  )
    (t 
      (cond
        ((= 2 (cadr c)) (cons (car l) (post (cddr l) (cons (car c) (cons (- (cadr c) 1) (cddr c)) ) ) ) )
        (t (cons (car l) (cons (car c) (post (cddr l) (cddr c)) ) ) )
      )
    )
  )
)

(print (post '(A 2 B 1 D 0 C 0) () ))
```

15. Determine the list of nodes accessed in postorder in a tree of type (2).
```

```

16. Determine if a tree of type (2) is balanced (the difference between the depth of two subtrees is equal to 1).
```

```