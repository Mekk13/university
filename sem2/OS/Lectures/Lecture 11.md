Cum se poate preveni un deadlock sau rezolva 

Prevention:
1) Mutual exclusion x
2) hold and wait  x
3) No preemption  (wave of hatred)   x
4) Circular wait ✓
We block the resources in the same order ALWAYS

```
i=rand
j=rand
lock(m[i])
lock(m[j])
x=a[i]
incomplete
```

Planificarea proceselor  (scheduling)
Let's (unreasonably) assume that we know the process duration:

(1)
(1)
(      7     )
Turnaround = Tcompletion -Tarrival
we would ideally want to minimize the turnaround time.
(1)(1)(    7    )
1  2      9         => Turnaround = 4

(   7   )(1)( 1 )
  7       8    9     => Turnaround = 8

=> short processes go first 

FCFS (FIFO)
SJF (shortest job first)
STCF (preemption)

Tresponse = T - Tarrival
RR - round robin - preemption

MLFQ -Multi level feedback queue
-> has more priorities
P3
P2
P1

Rules:
1) if Priority(a)>Priority(b) , A runs
2) if they are = , we do RR with a and b 
3) When a job goes in the system (we start a program) it's placed at the end of the maximum (last Priority) queue
4) When a job finishes the time allocated on the processor it's moved to the inferior queue (you go from P3 -> p2 -> P1; all the processes go through all the queues)
5) all the processes are moved to the maximum queue

