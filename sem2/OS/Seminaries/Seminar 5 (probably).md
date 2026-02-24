Proces = program aflat in executie
when we create a process it gets a new PID, for a new thread we get a Thread id . A thread has common things with the process that created it.

When we create a process thru fork everything is copied. When we create a thread :

Process   --------------------> TH 

| Ds   |
| ---- |
| CS   |
| heap |
| ss   |
TH:

|     |
| --- |
it can look at the segments from the process and use those things from the heap.

A child process can not access that directly . 

Threads= lightweight processes

for very small programs a thread will have more overhead than a process.

# Everything is POSIX reliant

void *  v -> points to an address that can point to any amount of bytes
stone age polymorphism 


How  to create a thread:
```
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *f(void *arg
{
	banana *b = (banana) arg; //this is important because w/o cast idk how to dereference the object 
	printf("This thread received a %s of size %llu \n",b->arr , b->k);
	int *ret = malloc(sizeof(int));
	*ret =0;
	return ret;
}

typedef struct{
	char arr[8];
	unsigned long long k;
	
}banana;

int main(int argc , char *argv[]){

	pthread_t th;
	banana b;
	strcpy(b.arr,"banana");
	b.k=3;
	pthread_create(&th,NULL,f,&b);
	/*
	1. pointer to a structure that stores the thread id
	2. attributes (size of stack, priority, basically thread settings) . if NULL, it uses the default values.
	3. an argument that tells the thread its 'entrypoint'.
	4. the argument for the thread <3
	*/

	//pthread_join(th,NULL); // second is like the exit status into the location if we give an arg <3
	int *i;
	pthread_join(th,(void **)&i);
	printf("from the thread he comes: %d", *i);
	free(i);
	return 0;
}
```

# <3

threads overlapping:

```
thread 1             thread 2         
1. read n            3. read n
2. local n++         4. local n++
5 . write n          6. write n
```
expected: 17
got: 16 

mutex -> mutual exclusion for threads not to overlap
OR semaphores

```
pthread_muutex_mutex(&m,NULL);

```

critical resource -> a resource thats used by multiple threads -> critical code areas that MUST be protected

only THOSE lines need to be protected by mutex. Less is bad. More -> risk of having less threads work simultaneously. 

