#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct{
	int n,m;
	int id;
	pthread_mutex_t *mutex;
	pthread_barrier_t *barrier;
}arg;

void* f(void *argument){

	arg* a=(arg*)argument;
	pthread_barrier_wait(a->barrier);

	for(int i=1;i<=a->m;i++){
		pthread_mutex_lock(&a->mutex[i]);
		printf("Thread %d passed the checkpoint %d\n",a->id,i);
		usleep(100000);
		pthread_mutex_unlock(&a->mutex[i]);
	}
	free(a);
	return NULL;
}

int main(int argc, char** argv){
	
	if(argc!=3){
		perror("no\n");
		return 1;
	}
	int n,m;
	n=atoi(argv[1]);
	m=atoi(argv[2]);

	pthread_t *t =malloc(sizeof(pthread_t)*(n+1));

	pthread_mutex_t *mutex= malloc(sizeof(pthread_mutex_t)*(m+1));
	pthread_barrier_t barrier;
	pthread_barrier_init(&barrier,NULL,n);
	
	for(int i=1;i<=m;i++){
		pthread_mutex_init(&mutex[i],NULL);
	}
 
	for(int i=1;i<=n;i++){
		arg *a = malloc(sizeof(arg));
		a->n=n;
		a->m=m;
		a->id=i;
		a->mutex = mutex;
		a->barrier = &barrier;
		pthread_create(&t[i],NULL,f,a);
	}

	for(int i=1;i<=n;i++){
		pthread_join(t[i],NULL);
	}
	
	for(int i=1;i<=m;i++){
		pthread_mutex_destroy(&mutex[i]);
	}

	free(mutex);
	free(t);
	return 0;
}
