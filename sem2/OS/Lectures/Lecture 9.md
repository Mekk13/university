w ->wait:
-> this needs to check if the condition is still true (i.e. if there's still more than 1k requests) because the problem may "right itself".

```
while(1){
	lock(&m);
	while(n<=1000){
		wait(&c,&m); //while you wait the other things execute due to the unlock           //inside
		//the wait unlocks and locks the mutex inside
     }
	... -> here is the place where i should clean or do whatever, b4 unlock
	unlock(&m);
	...
	//basically it waits while we dont exceed 1k and it keeps checking, and if that
	//happens it does whatever it needs to do and loops again (while(1))
}
```


s -> signal:

```
lock(&m) ;
n++ ;
if(n>1000) 
	signal(&c); 
unlock(&m); 
//do stuff
lock(&m);
n--;
unlock(&m);
```

pthread_cond_t (type)
pthread_cond_init 
pthread_cond_destroy
pthread_cond_wait
pthread_cond_signal
pthread_cond_broadcast -> like signal but it flags all the current waiting threads 

the nr. of requests is critical variable 


# Children going to bathroom stalls
->they can't go in the same one at the same time!
```handdrawn-ink
{
	"versionAtEmbed": "0.3.4",
	"filepath": "Ink/Drawing/2025.5.7 - 22.56pm.drawing",
	"width": 574,
	"aspectRatio": 2.1259259259259258
}
```

```
sem_wait
for(i=0;i<3;i++){
	lock(&m);
	//do stuff
	unlock(&m);
}
//this is nto good because they wait one after another
```

```
sem_wait
for(i=0;i<3;i++){
	if(trylock(&m)==0){
		//do stuff
		unlock
		break;
	}
}
//this is the solution
```


# Elevator:
-> it is conditioned by the "weight" of the people inside. 
-> each thread will have to have a weight 
-> we use a semaphore initialized with the maximum weight
-> the weight of the semaphore will decrement for each thread by that thread's weight
```
for(i=0;i<weight;i++){
	sem_wait //sem_wait decrements by 1 unit
}
```

->we can get stuck - if multiple people start 'reserving' weight on the elevator using weight and they all manage to get around 40kg yet they don't reach their full weight, the program gets stuck.
How to avoid this?
->Reserving weight is NOT atomic. sem_wait IS atomic but several of them, however, are NOT. So , we need to use a mutex and lock it ('People' go in the elevator one by one).
->Still, if the weight of the first thread is bigger than the elevator capacity it will still stop. 

# Trampoline:
->also has a weight limit
->a number of people limit (so they don't bump into each other!)

# Problem that may be in the written exam
The producer - consumer problem.
Analogy: Bake-off day at the kindergarten. Some children bring cookies, some children just eat the cookies. 
You have them place the cookies on the table. You don't want 2 children to place a cookie in the same spot. You don't want 2 hungry children grab the same cookie. No 2 hungry children at the same table and children with cookies at the same table (so it doesn't overflow with cookies)

It's kinda like pipe communication. 
You have a bunch of producers producing data and writing it to a buffer, and consumers reading from it. 

How do we implement this? 

We simulate the mechanism of read and write form a pipe. 
To make it simpler we will have producers produce only one unit at a time and consumers consume only 1 unit at a time (1 byte of data will be written / read at one time).

(Semaphores allow you to do this with multiple bytes at the same time)

having a lock for each byte is possible but a bit too complicated.

It can also be done with conditional variables. 

Discussed solution:

```handdrawn-ink
{
	"versionAtEmbed": "0.3.4",
	"filepath": "Ink/Drawing/2025.5.7 - 23.30pm.drawing",
	"width": 356,
	"aspectRatio": 1.4015748031496063
}
```

<u>Producer</u>
wait(E)
lock(X)
produce
unlock(X)
post(F)

<u>Consumer</u>
wait(F)
lock(X)
consume
unlock(X)
post(F) //post on full

these are atomic variables.


# Thread safety 
let's say we want to implement a linked list by using threads. It's a risk because in a linked list you cannot add or remove simultaneously. 

you have:
add:
-> it changes the list 
-> you lock the mutex, add, unlock

remove
->changes the list 
-> lock the mutex, remove, unlock

search
-> changes nothing
-> but if anyone messes with the list , it damages it 

update
-> does not change the list, changes 1 value from the list
-> you need to protect yourself from someone starting a deletion or something that locks the list while you are actively changing the element.
-> you can have multiple updates as long as they are not on the same element.

So : you can use a read - write lock . 
Add , remove need a write lock
Search and update need a read lock

it's more complicated than this ୨୧ 
