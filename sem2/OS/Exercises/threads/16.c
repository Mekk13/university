#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	int* array;
	pthread_mutex_t *mutex;
	int number;
}thread_args;

void* f(void* a){
	thread_args *args=(thread_args*)a;
	int nr=args->number;
	do{
		int digit = nr%10;
		pthread_mutex_lock(&args->mutex[digit]);
		(args->array[nr%10])++;
		nr/=10;
		pthread_mutex_unlock(&args->mutex[digit]);
	}while(nr);
	free(args);
	return NULL;
}

int main(int argc, char** argv){
	if(argc<2){
		perror("pls introduce at least 1(one) number\n");
		return 1;
	}

	pthread_mutex_t *mutex= malloc(sizeof(pthread_mutex_t)*10);
	for(int i =0 ;i<=9;i++){
		pthread_mutex_init(&mutex[i],NULL);
	}
	int n = argc -1;
	pthread_t t[n];

	int array[10]={0};
	
	for(int i =1 ;i<=n;i++){
		thread_args *args = malloc(sizeof(thread_args));
		args->array = array;
		args->number = atoi(argv[i]);
		args->mutex = mutex;
		pthread_create(&t[i],NULL,f,args);
	}

	for(int i =1;i<=n;i++){
		pthread_join(t[i],NULL);
	}
	for(int i=0;i<=9;i++){
		pthread_mutex_destroy(&mutex[i]);
	}
	free(mutex);
	for(int i=0;i<=9;i++){
		printf("arr[%d]= %d\n",i,array[i]);
	}

	return 0;
}
