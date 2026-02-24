9.
a) Write a function that merges two sorted linear lists and keeps double values.
b) Write a function to replace an element E by all elements of a list L1 at all levels of a given list L.
c) Write a function to determines the sum of two numbers in list representation, and returns the 
corresponding decimal number, without transforming the representation of the number from list to number.
d) Write a function to return the greatest common divisor of all numbers in a linear list.

Next time: L2 ex 1

a)
```
; mathematical model
; merge-sorted(l1..ln, s1..sm) = 
;   = s1..sm , n = 0 
;   = l1..ln, m = 0
;   = l1 U merge-sorted(l2..ln,s1..sm) , l1 < s1
;   = s1 U merge-sorted(l1..ln, s2..sm) , otherwise

(defun merge-sorted (a b)
  (cond
    ((null a) b)
    ((null b) a)
    ((<= (car a) (car b))
     (cons (car a)
           (merge-sorted (cdr a) b)))
    (t
     (cons (car b)
           (merge-sorted a (cdr b))))))

(print (merge-sorted '(1 5 7 9) '(2 3 4 5)))
```

b) 
```
; Write a function to replace an element E by all elements of a list L1 at all levels of a given list L.
; mathematical model:

; function for appending 2 lists:
; my_append(l1..ln, s1..sm) = 
; = l1..ln , m = 0 
; = s1..sm , n = 0 
; = l1 U my_append(l2..ln,s1..sm) , otherwise

(defun my_append(l1 l2)
  (cond
    ((null l1) l2)
    ((null l2) l1)
    (T (cons (car l1) (my_append (cdr l1) l2 )))
  )
)

 ; (print (my_append '(1 2 3) '(2 3 4) ))
 
; my_replace(l1..ln, elem , r1..rm) = 
; = [] , n = 0 
; = l1 U replace(l2..ln, elem, r1..rm) , l1 != elem and l1 atom
; = (r1..rm) U (l2..ln, elem , r1..rm) , l1 == elem and l1 atom
; = replace(l1, elem , r1..rm) U replace(l2..ln,elem,r1..r,) , l1 is a list

(defun my_replace(l1 elem l2)
  (cond
    ((null l1) nil)
    
    ((and (not(equal (car l1) elem)) (atom(car l1))  ) 
      (cons 
        (car l1)
        (my_replace (cdr l1) elem l2)
      )
    )
    
    ((and (= (car l1) elem) (atom(car l1))  ) 
      (my_append
        l2
        (my_replace (cdr l1) elem l2)
      )
    )
    
    (T (my_append (my_replace (car l1) elem l2) (my_replace (cdr l1) elem l2 ) ) )
    
  )
)

(print (my_replace '(1 2 1 3 4 1) 1 '(7 7 7)))

```

c)
```
; Write a function to determine the sum of two numbers in list representation, and returns the 
; corresponding decimal number, without transforming the representation of the number from list to number.


; reverse_list(l1..ln)
; = [] , n = 0 
; = reverse_list(l2..ln) U l1 


(defun my_append(l1 l2)
  (cond
    ((null l1) l2)
    ((null l2) l1)
    (T (cons (car l1) (my_append (cdr l1) l2 )))
  )
)

(defun reverse_list(l)
  (cond
    ((null l) nil)
    (T(my_append
      (reverse_list (cdr l) )
      (list(car l))
    ))
  )
)
;(print (reverse_list '(1 2 3 4 5 6 7)))

; mathematical model:
; my_sum(l1..ln, s1..sm , carry) =
; = [] , n = 0 and m = 0 and carry = 0 
; = [1] , n = 0 and m = 0 and carry = 1 
; = (l1+carry)%10 U my_sum(l2..ln,[],(l1+carry)/10 ) , m = 0 and carry != 0 
; = (s1+carry)%10 U my_sum([],s2..sm,(s1+carry)/10 ) , n = 0 and carry != 0
; = l1..ln , m = 0 and carry = 0 
; = s1..sm , n = 0 and carry = 0 
; = (l1 + s1 + carry )%10 U my_sum (l2..ln, s2..sn, (s1+l1+carry/10)), otherwise

(defun my_sum (l1 l2 carry) 
  (cond
    ((and (null l1) (null l2) (equal carry 0)) nil)
    ((and (null l1) (null l2) ) (list 1))
    
    ((and (null l2) (not(equal carry 0))) 
      (my_append
        (list (mod (+ carry (car l1)) 10 ) )
        (my_sum (cdr l1) '() (floor (/ (+ carry (car l1)) 10)) )
      )
    )
    
    ((and (null l1) (not(equal carry 0))) 
      (my_append
        (list (mod (+ carry (car l2)) 10 ) )
        (my_sum '() (cdr l2) (floor (/ (+ carry (car l2)) 10))  )
      )
    )
    
    ((and (null l2) (equal carry 0)) 
      l1
    )
    
    ((and (null l1) (equal carry 0)) 
      l2
    )
    
    (T 
       (my_append
       (list (mod (+ (car l1) (car l2) carry) 10))  
       (my_sum (cdr l1) (cdr l2) (floor (/ (+ (car l1) (car l2) carry) 10)))  
      )
    )
  )
)

(setq l1 '(1 9 8 7) )
(setq l2 '(4 3 3))

(print (reverse_list (my_sum (reverse_list l1) (reverse_list l2) 0) ) ) 
```

d)
```
; Write a function to return the greatest common divisor of all numbers in a linear list.

;mathematical moodel:

; my_gcd(a , b) =
; = a , b = 0 
; = gcd(a, a%b) , otherwise

(defun my_gcd (a b)
  (cond
    ((equal b 0) a)
    (T (gcd b (mod a b)))  
  )  
)

;(print (my_gcd 12 24))

; gcd_list(l1..ln)=
; = 0 , n = 0 
; = l1 , n = 1
; = my_gcd(l1,gcd_list(l2..ln))

(defun gcd_list (l)
  (cond
    ((null l) 0)
    ((null (cdr l)) (car l))
    (T
      (my_gcd (car l)  (gcd_list (cdr l))
    ))
  )
)

(print (gcd_list '(12 24 36)))
```



























6.
c) Write a function to replace each sublist of a list with its last element.
 A sublist is an element from the first level, which is a list.
 Example: (a (b c) (d (e (f)))) ==> (a c (e (f))) ==> (a c (f)) ==> (a c f)
 (a (b c) (d ((e) f))) ==> (a c ((e) f)) ==> (a c f)

```

```

