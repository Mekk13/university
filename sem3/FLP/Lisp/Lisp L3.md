Solve the following problems using MAP functions.

; mapcan for For a given tree of type (2) return the path from the root node to a certain given node X.


1. Write a function to check if an atom is member of a list (the list is non-linear)
```
; Write a function to check if an atom is member of a list 
; (the list is non-linear)

; mem(l1..ln,x) = 
; = false, n == 0 
; = true , l1 == x
; = mem(l2.ln,x) , otherwise

(defun mem(l x)
  (cond
    ((null l) nil)
    ((equal (car l) x) t)
    (t (mem (cdr l) x))
  )
)

; check(l,x) = 
; = true,  l - atom , l == x
; = false, l - atom , l != x
; = check(l1,x) OR check(l2,x) OR.. OR check(ln ,x) , where
; l = l1..ln

(defun check(l e)
  (cond
    ((and (atom l) (equal l e)) t)
    ((atom l ) nil)
    (t
      (cond  
        ( (mem (mapcar
          #'(lambda (x)
            (check x e)
          ) l 
        ) t) t)
        (t nil)
      )
    )
  )
)

(print (check '(a (b (c)) d (e (f (g))) h 1 2 (7 9) ) '7 ))
```

2. Write a function that returns the sum of numeric atoms in a list, at any level.
```
; Write a function that returns the sum of numeric atoms in a
; list, at any level.

; sum(l) = 
; = 0 , n == 0 , technically not necessary but it's my favourite part
; = 0 , l - atom , l not a number
; = l , l - number
; = sum(l1) + sum(l2) + .. + sum(ln)
; where l = l1..ln

(defun sum1(l)
  (cond
    ((null l) 0)
    ((numberp l) l)
    ((listp l) (apply #'+ (mapcar #'sum1 l ) ) )
    (t 0)
  )
)

(print (sum1 '(1 (2 A) ( -1 ) (B (3 (4))) 5)))
```

3. Define a function to tests the membership of a node in a n-tree represented as (root list_of_nodes_subtree1 ... list_of_nodes_subtreen)
Eg. tree is (a (b (c)) (d) (E (f))) and the node is "b" => true
```
; Define a function to tests the membership of a node in a 
; n-tree represented as :
; (root list_of_nodes_subtree1 ... list_of_nodes_subtreen)
; Eg. tree is (a (b (c)) (d) (E (f))) and the node is "b" 
; => true

; diy member function
; mem(l1..ln,x) = 
; = false, n == 0 
; = true , l1 == x
; = mem(l2.ln,x) , otherwise

(defun mem(l x)
  (cond
    ((null l) nil)
    ((equal (car l) x) t)
    (t (mem (cdr l) x))
  )
)


; membership(l node) = 
; = true , l - atom , l == node
; = false , l - atom 
; = membership(l1) or membership(l2) ... membership(ln)
; where l = l1..ln

(defun membership(l n)
  (cond
    ((and (atom l) (equal l n)) t)
    ((atom l) nil)
    (t 
      (cond
        ((mem (mapcar #'(lambda (x) (membership x n) ) l ) t) t)
        (t nil)
      )
    )
  )
)

(print (membership '(a (b (c)) (d) (E (f))) 'g  ) )
```

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

5. Write a function that computes the sum of even numbers and the decrease the sum of odd numbers,
at any level of a list.
```
; Write a function that computes the sum of even numbers and then
; decreases the sum of odd numbers, at any level of a list.

; sum(l) = 
; = 0 , n == 0
; = l , l - atom & number & even 
; = -l , l - atom & number & odd
; = 0 , l - atom
; = sum(l1) + ... + sum(ln)
; l = l1..ln

(defun sum(l)
  (cond
    ((null l) 0)
    ((numberp l)
      (cond
        ((equal (mod l 2) 0) l)
        (t (- 0 l))
      )
    )
    ((atom l) 0)
    (t (apply #'+ (mapcar #'sum l ) ))
  )
)

(print (sum '(10 (3 A) () (B (5 (6))) 2)))
```


6. Write a function that returns the maximum of numeric atoms in a list, at any level.
```
; Write a function that returns the maximum of numeric atoms
; in a list, at any level.

; mymax(l1..ln, m) =
; = m , n == 0 
; = = mymax(l2..ln , m) , l1 < m or l1 - not number
; = mymax(l2..ln , l1) , otherwise

(defun mymax(l m)
  (cond
    ((null l) m)
    ((not (numberp (car l ))) (mymax (cdr l) m) )
    ((> (car l) m) (mymax (cdr l) (car l)))
    (t (mymax (cdr l) m))
  )
)

; maximum(l) = 
; = null , n == 0 
; = l, l - number
; = nil , l - atom 
; = mymax ( maximum(l1) U ... maximum(ln) )

(defun maximum(l)
  (cond
    ((null l) nil)
    ((numberp l) l )
    ((atom l) nil)
    (t
      (mymax (mapcar  #'maximum l ) -999999 )
    )
  )
)

(print (maximum '(10 (3 A) (111) (B (5 (6))) 2) ))
```

7. Write a function that substitutes an element E with all elements of a list L1 at all levels of a given list L.
```
; Write a function that substitutes an element E with all 
; elements of a list L1 at all levels of a given list L.
; subs(l s E) = 
; = () , n == 0 
; = s, l - atom & l == E
; = l , l- atom 
; = subs(l1 s E) U .. U subs(ln s E)
; l = l1..ln

(defun subs(l s e)
  (cond
    ((and (atom l) (equal l e)) s )
    ((atom l) l )
    (t 
      (mapcar #'(lambda (x) (subs x s e) ) l
      )
    )
  )
)

(print (subs '(1 2 A B (C (A)) A (A B (A)) 2 L) '(R E) 'A))
```

8. Write a function to determine the number of nodes on the level k from a n-tree represented as follows:
(root list_nodes_subtree1 ... list_nodes_subtreen)
Eg: tree is (a (b (c)) (d) (e (f))) and k=1 => 3 nodes
```
; Write a function to determine the number of nodes on the level k from a n-tree represented as follows:
; (root list_nodes_subtree1 ... list_nodes_subtreen)
; Eg: tree is (a (b (c)) (d) (e (f))) and k=1 => 3 nodes

; nrn(l k) = 
; = 0 , l - atom & k > 0
; = 1 , l - atom & k == 0 
; = nrn(l1 k) + ... + nrn(ln k)

(defun nrn(l k)
  (cond
    ((null l) 0)
    ((and (atom l) (= k -1)) 1 )
    ((atom l) 0 )
    (t 
      (apply #'+
        (mapcar #'(lambda (x) (nrn x (- k 1) ) )l )
      )
    )
  )
)

(print (nrn '(a (b (c)) (d) (s) (e (f))) 1))
```


9. Write a function that removes all occurrences of an atom from any level of a list.
```

```

10. Define a function that replaces one node with another one in a n-tree represented as: root
list_of_nodes_subtree1... list_of_nodes_subtreen)
Eg: tree is (a (b (c)) (d) (e (f))) and node 'b' will be replace with node 'g' => tree (a (g (c)) (d) (e (f)))}
```

```


11. Write a function to determine the depth of a list.
```

```

12. Write a function that substitutes an element through another one at all levels of a given list.
```

```

13. Define a function that returns the depth of a tree represented as (root list_of_nodes_subtree1 ...
list_of_nodes_subtreen)
Eg. the depth of the tree (a (b (c)) (d) (e (f))) is 3
```

```


14. Write a function that returns the number of atoms in a list, at any level.
```

```

15. Write a function that reverses a list together with all its sublists elements, at any level.
```

```

16. Write a function that produces the linear list of all atoms of a given list, from all levels, and written in
the same order. Eg.: (((A B) C) (D E)) --> (A B C D E)
```
; Write a function that reverses a list together with all its sublists elements, at any level.
; ( 1 2 3 (4 5) (6 (7 8 9 )) 10 )

; reverse1(l1..ln) = 
; = null , n == 0  
; = reverse1(l2..ln) U l1

(defun reverse1(l)
  (cond
    ((null l ) nil)
    (t (append (reverse (cdr l)) (list (car l) ) ))
  )
)

; rev(l) =
; = l, l - atom 
; = reverse( rev(l1) U rev(l2).. U rev(ln) )

(defun rev(l)
  (cond
    ((atom l) l)
    (t (reverse1 (mapcar #'rev l ) ))
  )
)

(print (rev '( 1 2 3 (4 5) (6 (7 8 9 )) 10 ) ))
```