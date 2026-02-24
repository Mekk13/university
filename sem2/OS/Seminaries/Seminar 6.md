# Barriers

```
int *arr;
int n;
pthread_barrier_t bar;

void *f(void *arg){
	//get index
	int index=*((int *)arg);
	arr[index]=rand()%10;
	free(arg);
	//wait untill all other threads populate their array position

	pthread_barrier_wait(&bar); 
	
	int *rez = malloc(sizeof(int)*n);
	for(int i =0;i<n;i++){
		rez[i]=arr[n-i-1];
	}
	for(int i =0;i<n;i++){
		printf("%3d",rez[i]);
	}
	free(rez);
	return NULL;
}

int maian(int argc, char** argv){
	n=10; //or read from console
	pthread_t th[n];
	pthread_barrier_init(&bar,NULL,n);
	arr = malloc(sizeof(int)*n);
	for(int i=0;i<n;i++){
		int *tmp =malloc(sizeof(int));
		*tmp=i;
		pthread_create(&th[i],NULL,f,(void *)t);
	}
	pthread_barrier_destroy(&bar);
	return 0;
}
```

barrier resets after count reaches 0.
Latch does not.

# Conditional variables
-> a synchronizing mechanism that puts threads 'to sleep' until the condition is met, at which point it 'wakes them up'.

busywait -> CPU works but does noting 

pthread_cond_t cond;
pthread_cond_wait(conditional value , mutex);

Conditional variables work with mutexes;
the mutex must be locked when used!!!!

```
pthread_mutex_t mtx;
pthread_cond_t cond;
void *g(void *arg){
	pthread_mutex_lock(&mtx);
	flag = 1;//critical variable / resource 
	pthread_cond_signal(&cond);//theres a chance this goes straight to the conditional wait and it will then try to lock smth already locked so idk double whammy safety
	pthread_mutex_unlock(&mtx);
	return NULL;
}

void *f(void *arg){
	pthread_mutex_lock(&mtx);
	while(flag!=1 ){
		pthread_cond_wait(&cond,&mtx); //the mutex unlocks here!!!
	}
	//print whatever
	pthread_mutex_unlock(&mtx);
	return NULL;
}

//in main init mutex cond etc
//f starts first
if g starts first 
we use while bc the wait might randomly wake uo hihi

```


rwlock

