#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct{
	int n;
	int* array;
	int* current;
	pthread_cond_t *condition;
	pthread_mutex_t *mutex;
}thread_args;

void* f1(void *a){
	thread_args *arg=(thread_args*)a;
	pthread_mutex_lock(arg->mutex);
	while(*(arg->current)%2!=0)
		pthread_cond_wait(arg->condition,arg->mutex);

	while(*(arg->current) < arg->n){
		int nr = (random()%42)*2;
		arg->array[*(arg->current)]=nr;
		(*arg->current)++;
		

		printf("T1: ");
		for(int i =0;i<*(arg->current);i++){
			printf("%d ",arg->array[i]);
		}
		printf("\n");
		
		pthread_cond_signal(arg->condition);
		while(*(arg->current)%2!=0 && *(arg->current)<arg->n)
			pthread_cond_wait(arg->condition,arg->mutex);
	}

	pthread_cond_signal(arg->condition);
	pthread_mutex_unlock(arg->mutex);

	return NULL;
}

void* f2(void *a){
        thread_args *v= (thread_args*)a;
	pthread_mutex_lock(v->mutex);
	if(*(v->current)%2==0) pthread_cond_wait(v->condition,v->mutex);

	while(*(v->current) < v->n){
		int nr=(random()%42)*2+1;
		v->array[*(v->current)]=nr;
		*(v->current)+=1;

		printf("T2: ");
		for(int i=0;i<*(v->current);i++){
			printf("%d ",v->array[i]);
		}
		printf("\n");

		pthread_cond_signal(v->condition);
		while(*(v->current)%2==0)
			pthread_cond_wait(v->condition,v->mutex);

	}
	pthread_cond_signal(v->condition);
	pthread_mutex_unlock(v->mutex);
        free(v);
	return NULL;
}

int main(int argc, char** argv){
	if(argc != 2){
		printf("wrong argument\n");
		return 1;
	}
	int n =atoi(argv[1]);
	int index=0;
	pthread_mutex_t mutex;
	pthread_cond_t cond;
	pthread_mutex_init(&mutex,NULL);
	pthread_cond_init(&cond,NULL);
	int *array = malloc(sizeof(int)*n);


	pthread_t t1,t2;
	thread_args *args = malloc(sizeof(thread_args));
	args->n=n;
	args->current = &index;
	args->array = array;
	args->condition = &cond;
	args->mutex = &mutex;
	pthread_create(&t1,NULL,f1,args);
	pthread_create(&t2,NULL,f2,args);

	pthread_join(t1,NULL);
	pthread_join(t2,NULL);

	pthread_mutex_destroy(&mutex);
	pthread_cond_destroy(&cond);

	free(array);

	return 0;
}

