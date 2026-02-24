Next time: L3 ex 4

L2 ex 1:

Write recursive Lisp functions for the following problems (optionally, you may use MAP functions):
A binary tree is memorized in the following two ways:
(node no -subtrees list- subtree-1 list-subtree-2 ...) (1)
(node (list-subtree-1) (list-subtree-2) ...) (2)
As an example, the tree:

```handdrawn-ink
{
	"versionAtEmbed": "0.3.4",
	"filepath": "Ink/Drawing/2025.12.9 - 7.01am.drawing",
	"width": 350,
	"aspectRatio": 2.12292641318951
}
```


is represented as follows:
(A 2 B 0 C 2 D 0 E 0)          (1)

```
post:
l: 
c: A 1
rez: B 0 D 0 E 0 C A
```

(A (B) (C (D) (E)))                (2)

(1 (2 (4) (5)) (3 (6)) )

 1. For a given tree of type (1) return the path from the root node to a certain given node X.


```handdrawn-ink
{
	"versionAtEmbed": "0.3.4",
	"filepath": "Ink/Drawing/2025.12.11 - 0.52am.drawing",
	"width": 392,
	"aspectRatio": 1.8671885953286473
}
```


( A 2 B 1 D 0 C 2 E 1 I 0 F 2 J 0 K 0 )
(A (B (D))   (C (E (I)) (F (J) (K)) ))

```
; in(l1..ln,c1..ck) =
; = null , n = 0 
; = l1 U in( l3...ln, c1..ck ),l2 = 0 and  k = 0
; = l1 U in( c1 U 0 U l3..ln, c3..ck) , l2 = 0 and c2 = 1 
; = l1 U c1 U in( l3..ln, c3..ck ), l2 = 0 and c2 = 2
; = in ( l3..ln, l1 U l2 U c1..ck), otherwise
```

```
c: 
l: 
rez: D B A I E C J F K 
```




```

; left_traversal (l1..ln, nr_nodes , child_count) =  
; = null , n = 0 
; = null , nr_nodes = child_count + 1
; = l1 U l2 U left_traversal( l3..ln, nr_nodes + 1 , child_count + l2)

(defun left_traversal(l nr_nodes child_count)
    (
        cond
        ((null l) nil)
        ((= nr_nodes (+ 1 child_count)) nil)
        (t (cons (car l) (cons (cadr l) (left_traversal (cddr l) (+ 1 nr_nodes) (+ (cadr l) child_count)))))
    )
)

;left(l1..ln) = > returns the left tree of l
; = left_traversal( cddr (l) 0 0)

(defun left(l)
  (left_traversal (cddr l) 0 0)
)

; basically the same except when we find nr_nodes = child_count + 1
; right_traversal(l1..ln, nr_nodes, child_count) =
; = null , n = 0
; = l1..ln , nr_nodes = child_count + 1 
; = right_traversal(l3..ln, nr_nodes+1 , child_count+l2)


(defun right_traversal(l nr_nodes child_count)
  (
    cond
    ((null l) nil)
    ((= nr_nodes (+ 1 child_count)) l)
    (T (right_traversal (cddr l) (+ 1 nr_nodes) (+ (cadr l) child_count) ))
  )
)

(defun right(l)
  (right_traversal (cddr l) 0 0)
)

; check if the node exists
; check_node_exists( l1..ln , X) =
; = false, n = 0
; = true, l1 = X 
; = check_node_exists(l3..ln, X ), otherwise

(defun check_node_exists(l X)
  (cond
    ((null l) nil)
    ((equal (car l ) X ) T)
    (T (check_node_exists (cddr l) X))
  )
)

;(print (check_node_exists '(A 2 B 1 D 0 C 2 E 1 I 0 F 2 J 1 K 0) 'E))


; find_path(l1..ln, X) =
; = null , n = 0 or X is not in the tree
; = ( l1 ) , l1 = X 
; = l1 U find_path ( left(l1..ln ), X ) , if X is in left tree
; = l1 U find_path ( right(l1..ln ), X ), if X is in the right tree

(defun find_path (l X)
  (cond
    ((or (null l) (not (check_node_exists l X))) nil)
    ( (equal (car l) X ) (list X))
    (
      (check_node_exists (left l) X)
      (cons (car l) (find_path  (left l) X ) )
    )
    
    (
      (check_node_exists (right l) X)
      (cons (car l) (find_path  (right l) X ) )
    )
    (T nil)
  )
)

(print (find_path '(A 2 B 1 D 0 C 2 E 1 I 0 F 2 J 0 K 0) 'K))

```




