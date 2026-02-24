L1:
1.
a) Write a function to return the n-th element of a list, or NIL if such an element does not exist.
b) Write a function to check whether an atom E is a member of a list which is not necessarily linear.
c) Write a function to determine the list of all sublists of a given list, on any level.  
# <mark style="background: #FF5582A6;">!</mark> 
A sublist is either the list itself, or any element that is a list, at any level. Example:
(1 2 (3 (4 5) (6 7)) 8 (9 10)) => 5 sublists :
( (1 2 (3 (4 5) (6 7)) 8 (9 10)) (3 (4 5) (6 7)) (4 5) (6 7) (9 10) )
d) Write a function to transform a linear list into a set.

```
; 1.
;a) Write a function to return the n-th element of a list, or NIL if such an element does not exist.
;b) Write a function to check whether an atom E is a member of a list which is not necessarily linear.
;c) Write a function to determine the list of all sublists of a given list, on any level.
;A sublist is either the list itself, or any element that is a list, at any level. Example:
;(1 2 (3 (4 5) (6 7)) 8 (9 10)) => 5 sublists :
;( (1 2 (3 (4 5) (6 7)) 8 (9 10)) (3 (4 5) (6 7)) (4 5) (6 7) (9 10) )
;d) Write a function to transform a linear list into a set.

; a)  Write a function to return the n-th element of a list, or NIL if such an element does not exist.
; model:
; a1(l1..ln, k) =
; = nil, n == 0 
; = l1, k == 1 
; = a1(l2..ln,k-1), otherwise

(defun a1(l k) 
  (cond
    ((null l) nil)
    ((equal k 1) (car l))
    (T (a1 (cdr l) (- k 1) ))
  )
)

(print (a1 '(1 2 5) 5))

; b) Write a function to check whether an atom E is a member of a list which is not necessarily linear.
; model:
; b1(l1..ln, E) = 
; = false , n = 0 
; = true , l1 - atom , l1 = E
; = b1(l2..ln), l1 - atom , l1 != E
; = b1(l1) or b1(l2..ln) , l1 not an atom


(defun b1(l E)
  (cond
    ((null l) nil)
    ((and (atom (car l) ) (equal (car l) E)) t)
    ((atom (car l)) (b1 (cdr l) E))
    (t (or (b1 (car l) E)  (b1 (cdr l) E)))
  )
)

(print (b1 '(1 2 3 S T 4) 'S))

; c) Write a function to determine the list of all sublists of a given list, on any level.
;A sublist is either the list itself, or any element that is a list, at any level. Example:
;(1 2 (3 (4 5) (6 7)) 8 (9 10)) => 5 sublists :
;( (1 2 (3 (4 5) (6 7)) 8 (9 10)) (3 (4 5) (6 7)) (4 5) (6 7) (9 10) )
; model:
; c1(l1..ln) = 
; = nil , n == 0 
; = ( l1 U c1(l1) ) U c1(l2..ln),l1 - list
; = c1(l2..ln), otherwise
; 
; helper append for 2 lists
(defun my_append(l s)
  (cond
    ((null l) s)
    (t (cons (car l) (my_append (cdr l) s )) )
  )
)

(defun c1(l)
  (cond
    ((null l) nil)
    ((listp (car l)) (my_append (my_append (list (car l)) (c1 (car l) ) ) (c1 (cdr l)) ))
    (t (c1 (cdr l)))
  )
)

(defun finalc1(l)
  (my_append l (c1 l))
)

(print (finalc1 '(1 2 (3 (4 5) (6 7)) 8 (9 10))))


; d) Write a function to transform a linear list into a set.
; to_set(l1..ln, res) = 
; = res, n == 0 
; = to_set(l2..ln, res U l2), l2 - is not in res
; = to_set(l2..ln, res), otherwise

; helper exists function:
; exists(l1..ln, x) = 
; = false, n == 0 
; = true , l1 == x 
; = exists (l2..ln , x), otherwise

(defun exists(l x)
  (cond
    ((null l) nil)
    ((equal (car l) x ) t)
    (t (exists (cdr l) x))
  )
)

(defun to_set(l res)
  (cond
    ((null l) res)
    ((not (exists res (car l))) (to_set (cdr l) (cons (car l) res )) )
    (t (to_set (cdr l) res))
  )
)

(print (to_set '( 98 1 2  3 4 2 4 6 7 1 2 1 3 4 99) nil ))

```

2.
a) Write a function to return the product of two vectors.
https://en.wikipedia.org/wiki/Dot_product
b) Write a function to return the depth of a list. Example: the depth of a linear list is 1.
c) Write a function to sort a linear list without keeping the double values.
d) Write a function to return the intersection of two sets.

```
;a) Write a function to return the product of two vectors.
;
;helper:

(defun leng(l)
  (cond
    ((null l) 0)
    (t (+ 1 (leng (cdr l) )))
  )
)

; model:
; dotp(l1..ln, s1..sn) = 
; = nil , length(l) != length(s)
; = 0 , n == 0 
; = l1*s1 + dotp(l2..ln, s2..sn)

(defun dotp(l s)
  (cond
    ((not (equal (leng l) (leng s) ) )  nil )
    ((null l) 0)
    ( (+ (* (car l) (car s)) (dotp (cdr l) (cdr s) )) )
  )
)

(print (dotp '(1 2 3) '(1 1 2)))

; Write a function to return the depth of a list. Example: the depth of a linear list is 1.
; model:
; depth(l1..ln) = 
; = 1 , n == 0
; = 1+ maxi(depth(l1) depth(l2..ln)) , l1 - list 
; = depth(l2..ln) , otherwise

;helper:
(defun maxi(a b)
  (cond
    ((> a b) a)
    (t b)
  )
)

(defun depth(l)
  (cond
    ((null l) 1)
    ( (listp (car l )) (maxi (+ 1 (depth (car l)))  (depth (cdr l)) ))  
    (t (depth (cdr l)))
  )
)

(print (depth '(1 2 (3 (4)(5)) (6(7(8)))) ))


;c) Write a function to sort a linear list without keeping the double values.
;
;helper: 
; ins(l1..ln, x) = 
; = x U l, x < l1
; = l1 U ins(l2..ln, x) , x > l1 
; = l1..ln  , x == l1 

(defun ins(l x)
  (cond
    ((null l) (list x))
    ( (< x (car l)) (cons x l))
    ( (> x (car l)) (cons (car l) (ins (cdr l) x)))
    (t l)
  )
)


; mys(l1..ln, res) = 
; = res , n == 0 
; = mys(l2..ln , ins(res, l1))

(defun mys(l res)
  (cond
    ((null l) res)
    (t (mys (cdr l) (ins res (car l))))
  )
)

(print (mys '( 3 8 726 73 8 69 34 22 11 22 1 22 11 22 11) nil))

; d) Write a function to return the intersection of two sets.
; helper :
; exists(l1..ln, x) = 
; = false, n == 0 
; = true , l1 == x 
; = exists (l2..ln , x), otherwise

(defun exists(l x)
  (cond
    ((null l) nil)
    ((equal (car l) x ) t)
    (t (exists (cdr l) x))
  )
)

; inters(l1..ln , s1..sm) = 
; nil , n = 0  
; l1 U inters(l2..ln,s1..sm) , if l1 is in s1..sm
; inters(l2..ln,s1..sm), otherwise

(defun inters(l s)
  (cond
    ((null l) nil)
    ((exists s (car l)) (cons (car l) (inters (cdr l) s)) )
    (t (inters (cdr l) s) )
  )
)

(print (inters '(1 2) '(4 5 3 6 7 8 9 10)))

```

3.
a) Write a function that inserts in a linear list a given atom A after the 2nd, 4th, 6th, ... element.
b) Write a function to get from a given list the list of all atoms, on any
level, but reverse order. Example:
(((A B) C) (D E)) ==> (E D C B A)
c) Write a function that returns the greatest common divisor of all numbers in a nonlinear list.
d) Write a function that determines the number of occurrences of a given atom in a nonlinear list.

```
; a) Write a function that inserts in a linear list a given atom A after the 2nd, 4th, 6th, ... element.
; model: 
; ok(l1..ln, A , count) =
; = A , n == 0 and count % 2 == 0 , count not 0 
; = nil , n == 0 , count % 2 != 0
; = A U l1 U ok(l2..ln,A,count+1), count%2 == 0 , count not 0
; = l1 U ok(l2..ln,A,count+1) , otherwise

(defun ok(l A cnt)
  (cond
    ((null l) 
      (cond
        ((and 
           (equal (mod cnt 2) 0)
           (not (equal cnt 0)) ) 
           (list A)
        )
        (t nil)
      )
    )
    ((and 
      (equal (mod cnt 2) 0)
      (not (equal cnt 0)) ) 
      (cons A (cons (car l) (ok (cdr l) A (+ cnt 1))) )
    )
    (t (cons (car l) (ok (cdr l) A (+ cnt 1)) ) )
  )
)

(print (ok '(1 2 3 4 5 6 7) 'M 0))

; b) Write a function to get from a given list the list of all atoms, on any
;level, but reverse order. Example:
;(((A B) C) (D E)) ==> (E D C B A)
; model: 
; sure(l1..ln) = 
; = nil , n == 0 
; = sure(l2..ln) U l1, l1 - atom 
; = sure(l2..ln) U sure(l1) , l1 - list

(defun myapp(a b)
  (cond 
    ((null a) b)
    (t (cons (car a) (myapp (cdr a) b)))
  )
)

(defun sure(l)
  (cond
    ((null l) nil)
    ((atom (car l)) (myapp (sure (cdr l)) (list (car l)) ))
    (t (myapp (sure (cdr l)) (sure (car l))  ))
  )
)

(print (sure '(((A B) C) (D E)) ))


; c) Write a function that returns the greatest common divisor of all numbers in a nonlinear list.
; helper 
; gcd(a,b) =
; = a , a = b 
; = gcd (a%b , a) , otherwise

(defun gcdd(a b)
  (cond
    ((equal a 0) b)
    (t (gcdd (mod b a) a))
  )
)

; model:
; bet(l1..ln) = 
; = l1 , n == 1
; = gcdd( l1 , bet(l2..ln))

(defun bet(l)
  (cond
    ((null (cdr l)) (car l))
    (t (gcdd (car l) (bet (cdr l))))
  )
)



; d) Write a function that determines the number of occurrences of a given atom in a nonlinear list.
; nroc(l1..ln, x) =
; = 0 , n == 0 
; = 1 + nroc(l2..ln , x), l1 == x
; = nroc(l2..ln , x) , otherwise

(defun nroc(l x)
  (cond
    ((null l) 0)
    ((equal (car l) x) (+ 1 (nroc (cdr l) x)))
    (t (nroc (cdr l) x))
  )
)
```


4.
a) Write a function to return the sum of two vectors.
b) Write a function to get from a given list the list of all atoms, on any
level, but on the same order. Example:
(((A B) C) (D E)) ==> (A B C D E)
c) Write a function that, with a list given as parameter, inverts only continuous
sequences of atoms. Example:
(a b c (d (e f) g h i)) ==> (c b a (d (f e) i h g))
d) Write a list to return the maximum value of the numerical atoms from a list, at superficial level.

```

;a) Write a function to return the sum of two vectors.
; i will assume same length - checking it is trivial
(defun s(a b)
  (cond
    ((null a) nil)
    (t (cons (+ (car a) (car b)) (s (cdr a) (cdr b)) ))
  )
)

(print (s '(1 2 3) '(1 2 3)))


;b) Write a function to get from a given list the list of all atoms, on any
;level, but on the same order. Example:
;(((A B) C) (D E)) ==> (A B C D E)
; model:
; penguin(l1..ln) = 
; = nil , n == 0 
; = l1 U penguin(l2..ln), l1 - atom 
; = penguin(l1) U penguin(l2..ln), otherwise

(defun myapp(a b)
  (cond
    ((null a) b)
    (t (cons (car a) (myapp (cdr a) b)  ))
  )
)

(defun penguin(l)
  (cond
    ((null l) nil)
    ((atom (car l)) (myapp (list (car l)) (penguin (cdr l)) ))
    (t (myapp (penguin (car l)) (penguin (cdr l))  ))
  )
)

(print (penguin '(((A B) C) (D E)) ))


; c) Write a function that, with a list given as parameter, inverts only continuous
; sequences of atoms. Example:
; (a b c (d (e f) g h i)) ==> (c b a (d (f e) i h g))
; man(l1..ln) = 
; = nil , n == 0
; = man(l2..ln) U l1 , l1 - atom , with append
; = man(l1) U man(l2..ln) , otherwise , with cons

; helper 1 (inverts a section)

(defun rev(l)
  (cond
    ((null l) nil)
    (t (myapp (rev (cdr l)) (list (car l)) ) )
  )
)

; helper 2 (gets a section of atoms)

(defun gets(l)
  (cond
    ((null l) nil)
    ((atom (car l)) (cons (car l) (gets (cdr l))))
    (t nil)
  )
)

;(print (gets '(1 2 (3 4 (5 (6))) 7 )))

; helper 3 (drops a section of atoms from a fct)

(defun drops(l)
  (cond
    ((null l) nil)
    ((listp (car l)) l)
    (t (drops (cdr l)))
  )
)

;(print (drops '(1 2 (3 4 (5 (6))) 7 )))

; main fct frfr
; man(l1..ln) = 
; = nil , n == 0
; = reverse(get_atoms(l)) U man(list_without_atom_seq(l)) , l1 - atom  
; = man(l1) U man(l2..ln) , otherwise
;

(defun man(l)
  (cond
    ((null l) l)
    ((atom (car l)) (myapp (rev (gets l)) (man (drops l) ) ) )
    (t (cons (man (car l)) (man (cdr l)) ) )
  )
)

(print (man '(a b c (d (e f) g h i))))


; d) Write a list to return the maximum value of the numerical atoms from a list, at superficial level.

(defun ez(l maxi)
  (cond
    ((null l) maxi)
    ((atom (car l)) 
      (cond
        ((> (car l) maxi) (ez (cdr l) (car l)) )
        (t (ez (cdr l) maxi))
      )
    )
    (t (ez (cdr l) maxi))
  )
)

(print (ez '(1 2 3 (7 (8 (9))) 2 4 1) -1))

```

5.
a) Write twice the n-th element of a linear list. Example: for (10 20 30 40 50) and n=3 will produce (10
20 30 30 40 50).
b) Write a function to return an association list with the two lists given as parameters.
Example: (A B C) (X Y Z) --> ((A.X) (B.Y) (C.Z)).
c) Write a function to determine the number of all sublists of a given list, on any level.
A sublist is either the list itself, or any element that is a list, at any level. Example:
(1 2 (3 (4 5) (6 7)) 8 (9 10)) => 5 lists:
(list itself, (3 ...), (4 5), (6 7), (9 10)).
d) Write a function to return the number of all numerical atoms in a list at superficial level.

```

;a) Write twice the n-th element of a linear list. Example: for (10 20 30 40 50) and n=3 will produce (10
;20 30 30 40 50).
;

(defun kay(l n)
  (cond
    ((null l) nil)
    ((equal n 1) (cons (car l) (cons (car l) (cdr l) )  ) )
    (t (cons (car l) (kay (cdr l) (- n 1)) )  ) 
  )
)

(print (kay '(10 20 30 40 50) 5))

; b) Write a function to return an association list with the two lists given as parameters.
;Example: (A B C) (X Y Z) --> ((A.X) (B.Y) (C.Z)).

; i am assuming lists have equal length . also that i need to use cons.

(defun yo(l s)
  (cond
    ((null l) nil)
    (t (cons (cons (car l) (car s)) (yo (cdr l) (cdr s)) ))
  )
)

(print (yo '(A B C) '(X Y Z)))


; c) Write a function to determine the number of all sublists of a given list, on any level.
;A sublist is either the list itself, or any element that is a list, at any level. Example:
;(1 2 (3 (4 5) (6 7)) 8 (9 10)) => 5 lists:
;(list itself, (3 ...), (4 5), (6 7), (9 10)).

(defun surebro(l)
  (cond
    ((null l) 0)
    ((listp (car l)) (+ 1 (+ (surebro (car l)) (surebro (cdr l)) ))  )
    (t (surebro (cdr l)))
  )
)

(print (+ 1 (surebro '(1 2 (3 (4 5) (6 7)) (8) (7) 8 (9 10)))))

; d) Write a function to return the number of all numerical atoms in a list at superficial level.

(defun fish(l)
  (cond
    ((null l) 0)
    ( (numberp (car l)) (+ 1 (fish (cdr l))))
    (t (fish (cdr l)))
  )
)

(print (fish '(1 2 a ( 2 3 4 (5 6)) (5 7) (a))))

```

6.
a) Write a function to test whether a list is linear.
b) Write a function to replace the first occurence of an element E in a given list with an other element
O.
c) Write a function to replace each sublist of a list with its last element.
A sublist is an element from the first level, which is a list.
Example: (a (b c) (d (e (f)))) ==> (a c (e (f))) ==> (a c (f)) ==> (a c f)
(a (b c) (d ((e) f))) ==> (a c ((e) f)) ==> (a c f)
d) Write a function to merge two sorted lists without keeping double values.

```

```

7.
a) Write a function to eliminate the n-th element of a linear list.
b) Write a function to determine the successor of a number represented digit by digit as a list, without
transforming the representation of the number from list to number. Example: (1 9 3 5 9 9) --> (1 9 3 6 0
0)
c) Write a function to return the set of all the atoms of a list.
Exemplu: (1 (2 (1 3 (2 4) 3) 1) (1 4)) ==> (1 2 3 4)
d) Write a function to test whether a linear list is a set.
8.
a) Write a function to return the difference of two sets.
b) Write a function to reverse a list with its all sublists, on all levels.
c) Write a function to return the list of the first elements of all list elements of a given list with an odd
number of elements at superficial level. Example:
(1 2 (3 (4 5) (6 7)) 8 (9 10 11)) => (1 3 9).
d) Write a function to return the sum of all numerical atoms in a list at superficial level.
9.
a) Write a function that merges two sorted linear lists and keeps double values.
b) Write a function to replace an element E by all elements of a list L1 at all levels of a given list L.
c) Write a function to determines the sum of two numbers in list representation, and returns the
corresponding decimal number, without transforming the representation of the number from list to
number.
d) Write a function to return the greatest common divisor of all numbers in a linear list.

10.
a) Write a function to return the product of all the numerical atoms from a list, at superficial level.
b) Write a function to replace the first occurence of an element E in a given list with an other element
O.
c) Write a function to compute the result of an arithmetic expression memorised
in preorder on a stack. Examples:
(+ 1 3) ==> 4 (1 + 3)
(+ * 2 4 3) ==> 11 [((2 * 4) + 3)
(+ * 2 4 - 5 * 2 2) ==> 9 ((2 * 4) + (5 - (2 * 2))
d) Write a function to produce the list of pairs (atom n), where atom appears for n times in the parameter
list. Example:
(A B A B A C A) --> ((A 4) (B 2) (C 1)).
```
; 10.
; b) Write a function to replace the first occurence of an element E in a given list with an other element
; O.
; d) Write a function to produce the list of pairs (atom n), where atom appears for n times in the parameter
; list. Example:
; (A B A B A C A) --> ((A 4) (B 2) (C 1)).

; a) Write a function to return the product of all the numerical atoms from a list, at superficial level.
;
; product(l1..ln) =
; = 1, n == 0 
; = l1 * product(l2..ln) , l1 - numeric atom 
; = product(l2..ln), otherwise

(defun prod(l)
  (cond 
    ((null l) 1)
    ((numberp (car l)) (* (car l) (prod (cdr l))) )
    (t (prod (cdr l)))
  )
)

; (print (prod '(3 2 (3 4 (4)) (5) 6 )))

; c) Write a function to compute the result of an arithmetic expression memorised
; in preorder on a stack. Examples:
; (+ 1 3) ==> 4 (1 + 3)
; (+ * 2 4 3) ==> 11 [((2 * 4) + 3)
; (+ * 2 4 - 5 * 2 2) ==> 9 ((2 * 4) + (5 - (2 * 2))

; helper that finds a operand-operator-operator triplet and reduces the list
; calc(l1..ln) =
; = [] , n == 0  
; = funcall(l1,l2,l3) U (l4..ln),  l1 - operand , l2,l3 - operators
; = l1 U calc(l1..ln) , otherwise


(defun calc(l)
  (cond
    ((null l) nil)
    ( (and (not (numberp (car l))) (and (numberp (cadr l)) (numberp (caddr l)) ) )
      (cons
        (funcall (car l) (cadr l) (caddr l))
        (cdddr l)
      )
    )
    (t (cons (car l) (calc (cdr l))))
  )
)

; (print (calc '(+ - 6 2 + 3 1)))



; res(l1..ln) = 
; = l1 , n == 1 
; = res(calc(l1..ln))

(defun res(l)
  (cond
    ((null (cdr l)) (car l))
    (t (res (calc l)))
  )
)

(print (res '(+ * 2 4 - 5 * 2 2)))
```

11.
a) Determine the least common multiple of the numerical values of a nonlinear list.
b) Write a function to test if a linear list of numbers has a "mountain" aspect (a list has a "mountain"
aspect if the items increase to a certain point and then decreases.
Eg. (10 18 29 17 11 10). The list must have at least 3 atoms to fullfil this criteria.
c) Remove all occurrences of a maximum numerical element from a nonlinear list.
d) Write a function which returns the product of numerical even atoms from a list, to any level.
12.
a) Write a function to return the dot product of two vectors. https://en.wikipedia.org/wiki/Dot_product
b) Write a function to return the maximum value of all the numerical atoms of a list, at any level.
c) All permutations to be replaced by: Write a function to compute the result of an arithmetic expression
memorised
in preorder on a stack. Examples:
(+ 1 3) ==> 4 (1 + 3)
(+ * 2 4 3) ==> 11 [((2 * 4) + 3)
(+ * 2 4 - 5 * 2 2) ==> 9 ((2 * 4) + (5 - (2 * 2))
d) Write a function to return T if a list has an even number of elements on the first level, and NIL on the
contrary case, without counting the elements of the list.
13.
a) A linear list is given. Eliminate from the list all elements from N to N steps, N-given.
b) Write a function to test if a linear list of integer numbers has a "valley" aspect (a list has a valley
aspect if the items decrease to a certain point and then increase. Eg. 10 8 6 17 19 20). A list must have
at least 3 elements to fullfill this condition.
c) Build a function that returns the minimum numeric atom from a list, at any level.
d) Write a function that deletes from a linear list of all occurrences of the maximum element.
14.
a) Write a function to return the union of two sets.
b) Write a function to return the product of all numerical atoms in a list, at any level.
c) Write a function to sort a linear list with keeping the double values.
d) Build a list which contains positions of a minimum numeric element from a given linear list.

15.
a) Write a function to insert an element E on the n-th position of a linear list.
b) Write a function to return the sum of all numerical atoms of a list, at any level.
c) Write a function to return the set of all sublists of a given linear list. Ex. For list ((1 2 3) ((4 5) 6)) =>
((1 2 3) (4 5) ((4 5) 6))
d) Write a function to test the equality of two sets, without using the difference of two sets.