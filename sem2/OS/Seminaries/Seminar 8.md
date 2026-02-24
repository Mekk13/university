
```handdrawn-ink
{
	"versionAtEmbed": "0.3.4",
	"filepath": "Ink/Drawing/2025.5.28 - 8.29am.drawing",
	"width": 838,
	"aspectRatio": 2.1432225063938617
}
```

1st -> 3 barriers n1,n2,n3 and an n for loop with threads. what's n

2nd -> forks with semaphores is pretty useless

# shared memory:
1) shmget(key, size, flag) (kinda like malloc )
-> returns an id 
-> id == -1 => error
-> after i have that id i can do shmat 
-> basically you get the id and then you try to attach  it to a pointer 
-> IPC_CREAT returns existing or newly created 

2) shmat  ( like the second part of malloc )
-> tells you where in memory you align your stuff
-> first parameter is an id returned by shmget
-> you can use a parameter to tell it where to put it or leave the second parameter NULL and let it be
-> last parameter is a flag 
-> if you want no restrictions on that piece of memory you set the flag to 0
-> returns a void pointer and it will be the actual object

3) shmdt (pointer to whatever) 
-> detaches the memory  the shared memory

4) shmctl 
-> can also be used for deletion by sending the id and delete command and a NULL parameter ( which would be extra information about the shared memory)


sys ipc.h
we generate a unique key to create a pathname that is uniquely identified. 
we also use a proj id (a nr.) to use the same path while generating different keys.

ex:
```

sem_t *sem;
key_t key = ftok("./sem_p.c",223);
int shmid= shmget(key, sizeof(semaphore),0600 | IPC_CREAT) //read write permissions
if(shmid == -1){
	//error
}
sem = (sem_t*) shmat(shmid,NULL,0);
if(sem==-1){
	//error
}
sem_init(sem,1,5);
struct timeval start,stop;
for(int i =0;i<n;i++){
	int f=fork();
	if(f==0){
		sem_wait(sem);
		sleep(5);
		sem_post(sem);
		exit(0);
	}
}

for(int i=0;i<10;i++){
	wait(NULL);
}

//so child copies the shared memory even though the pointer is copied it will point towards the same place in memory . Similar to pipes.

//to clean up:
shmdt(sem); //shared memory detach
shmctl(shmid, IPC_RNID, NULL); //technically this is sufficient but you will have a dangling pointer 
```

To delete shared memory from cmd:
ipcrm  -M key

```
typedef struct{
	int *a;
	char c;
	double d;
}data;
int main(){

	data d;
	d.a=
	key_t key = ftok("./whatever.c",223);
	int shmid= shmget(key, sizeof(data),0600 | IPC_CREAT);
	if(shmid == -1){
		//error
	}
	d = (data*) shmat(shmid,NULL,0);
	
	d->a = 7;
	d->c='b';
	d->d = 3.141593;
	shmdt(d);
	return 0;
}
```