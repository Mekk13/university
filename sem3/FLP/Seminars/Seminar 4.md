# LISP 

(print "Hello, World!")
(print (+ 2 3))
(print (< 2 3))

(print '(1 2 3))

(print (car '(1 2 3)))
(print (cdr '(1 2 3)))
(print (car (cdr'(1 2 3))))
(print (cadr '(1 2 3)))
(print (caddr '(1 2 3)))
(print (cadddr '(1 2 3 4)))
; (print (caddddr '(1 2 3 4 5 6 7 ))) - error 

(print (cons 100 '(2 3))) 
(print (cons '(100 1) '(1 2 3)))
(print (append '(100) '(2 3))) ; can't use this in assignments

; mathematical model:
; my_append(l1..ln, m1..mk) = 
; = m1..mk , n == 0 
; = l1..ln , k == 0 
; l1 U my_append(l2..ln,m1..mk) , otherwise

; (cond 
;    (condition1 action1)
;    (condition2 action2)
;    ... 
;    (condition_n action_n)
;    (T default_action)
;  )

; nil - false but also empty list

(defun my_append (l1 l2) 
 (cond
    ((null l1) l2)
    ((null l2) l1)
    (T (cons (car l1) (my_append (cdr l1) l2)))
 )
)

(print (my_append '(100) '(2 3)))

; make a fct that given a heterogeneous list of lists and atoms and a level will return
; only the atoms on that level

; mathematical model:
; get_atoms(l1..ln,a) =
; = [] , n = 0 or a = 0 
; = l1 U get_atoms(l2..ln,a) , a = 1 and l1 is numeric
; = get_atoms(l2..ln, a), a = 1 and l1 is NOT numeric (is list)
; = get_atoms(l1, a-1) U get_atoms(l2..ln,a) , a > 1 and l1 is list 
; = get_atoms(l2..ln, a), a>1 and l1 is numeric 

(defun get_atoms (l level)
  (cond 
    ((or (null l) (= level 0 )) nil )
    ((and (= level 1) (not(listp (car l) )))
      (cons (car l) (get_atoms(cdr l) level))
    )
    ((and(> level 1) (listp (car l)))
      (my_append 
      (get_atoms (car l ) (- level 1))
      (get_atoms (cdr l ) level)
    )
  )
  (T (get_atoms (cdr l) level))
)
)


(print(get_atoms '(1 2 (3 (4) 5 (((6))))) 2))


; get_last(l1..ln) =
; = [] , n = 0 
; = l1 , n = 1 and l1 is atom 
; = get_last(l1), n = 1 and l1 is list
; = get_last(l2..ln), otherwise

(defun get_last (l)
  (cond
    ((null l) nil)
    ((and (atom (car l)) (null (cdr l))) (car l))
    ((null (cdr l)) (get_last( car l)))
    (T (get_last (cdr l)))
  )
)

; function(l1..ln) = 
; = [], n = 0 
; = l1 U function(l2..ln), is_atom(l1)
; = get_last(l1) U function(l2..ln), is_list(l1)


(defun func(l)
  (cond
    ((null l) nil)
    ((atom (car l)) (cons (car l) (func(cdr l))))
    (T (cons (get_last (car l)) (func (cdr l))))
  
  )
)


























