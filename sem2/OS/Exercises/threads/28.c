#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>


typedef struct{
	pthread_mutex_t *m;
	pthread_barrier_t *b;
	int *arr, n , *sorted;
}data;


void* sorter(void *a){
	data *arg = (data*)a;
	int i,j;
	while(1){
		i = random()% (arg->n);
		j = random()% (arg->n);
		int sorted = 1;
		pthread_mutex_lock(arg->m);
		if(*arg->sorted)
			break;
		for(int k=0;k<arg->n-1;k++){
			if(arg->arr[k]>arg->arr[k+1])
				sorted=0;
		}
		if(sorted){
			*arg->sorted = sorted;
			break;
		}

		if((i<j && arg->arr[i] > arg->arr[j]) || (i>j && arg->arr[i] < arg->arr[j])){
			int aux =  arg->arr[i];
			arg->arr[i]=arg->arr[j];
			arg->arr[j]=aux;
		}
		pthread_mutex_unlock(arg->m);
		usleep(10);

	}
	pthread_mutex_unlock(arg->m);
	pthread_barrier_wait(arg->b);
	return NULL;
}


void* printer(void *a){

	data *d = (data*)a;
	
	pthread_barrier_wait(d->b);

	for(int i=0;i<d->n;i++){
		printf("arr[%d] = %d\n",i,d->arr[i]);
	}
	return NULL;
}

int main(int argc, char** argv){

	if(argc!=2){
		printf("one arg required\n");
		return 1;
	}

	int n = atoi(argv[1]);
	int *arr = malloc(sizeof(int)*n);

	for(int i=0;i<n;i++){
		int nr=random()%1000;
		arr[i]=nr;
	}

	pthread_t *t = malloc (sizeof(pthread_t)*(n+1));
	pthread_mutex_t *m = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(m,NULL);
	pthread_barrier_t *b = malloc(sizeof(pthread_barrier_t));
	pthread_barrier_init(b,NULL,n+1);
	data *args = malloc(sizeof(data)*(n+1));

	int *sorted=malloc(sizeof(int));


	for(int i=0;i<n;i++){
		args[i].b=b;
		args[i].m=m;
		args[i].arr = arr;
		args[i].sorted = sorted;
		args[i].n=n;
		pthread_create(&t[i],NULL,sorter,&args[i]);
	}
	
	args[n].b=b;
	args[n].m=m;
	args[n].arr = arr;
	args[n].sorted = sorted;
	args[n].n=n;
	pthread_create(&t[n],NULL,printer,&args[n]);
	
	for(int i=0;i<n+1;i++){
		
		pthread_join(t[i],NULL);
	}
	

	pthread_mutex_destroy(m);
	pthread_barrier_destroy(b);
	free(t);
	free(arr);
	free(m);
	free(b);
	free(sorted);
	free(args);
	return 0;
}
