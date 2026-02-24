#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct{

	pthread_mutex_t *m;
	pthread_barrier_t *b;
	int *i_par, *i_impar;
	int *par, *impar;
	int *arr;
	int n;
	int id;
	int *sum;
}data;

void* f(void *a){

	data *d = (data*)a;

	pthread_barrier_wait(d->b);

	int nr = d->arr[d->id];
	while(nr>9){
		nr/=10;
	}
	if(nr%2==0){
		pthread_mutex_lock(d->m);
		d->par[*d->i_par] = d->arr[d->id];
		(*d->i_par)++;
		(*d->sum) += d->arr[d->id];
		pthread_mutex_unlock(d->m);
	}
	else{
		pthread_mutex_lock(d->m);
		d->impar[*d->i_impar] = d->arr[d->id];
		(*d->i_impar)++;
		(*d->sum) += d->arr[d->id];
		pthread_mutex_unlock(d->m);
	}
	return NULL;
}

int main(){
	int n;
	printf("n= ");
	scanf("%d",&n);
	
	int* arr = malloc(sizeof(int)*n);

	for(int i=0;i<n;i++){
		printf("Nr %d =",i);
		scanf("%d",&arr[i]);
	}

	int *par = malloc(sizeof(int)*n), *impar=malloc(sizeof(int)*n);
	pthread_t *t=malloc(sizeof(pthread_t)*n);
	pthread_mutex_t *m = malloc(sizeof(pthread_mutex_t));
	pthread_barrier_t *b = malloc(sizeof(pthread_barrier_t));
	pthread_mutex_init(m,NULL);
	pthread_barrier_init(b,NULL,n);
	
	data *args = malloc(sizeof(data)*n);
	int *i1 = malloc(sizeof(int));
	*i1=0;
	int *i2 = malloc(sizeof(int));
	*i2=0;
	int *sum = malloc(sizeof(int));
	*sum =0;

	for(int i=0;i<n;i++){
		args[i].n=n;
		args[i].m=m;
		args[i].b=b;
		args[i].i_par = i1;
		args[i].i_impar = i2;
		args[i].par = par;
		args[i].impar = impar;
		args[i].arr = arr;
		args[i].id = i;
		args[i].sum = sum ;
		pthread_create(&t[i],NULL,f,&args[i]);
	}
	

	for(int i=0;i<n;i++){
		pthread_join(t[i],NULL);
	}

	printf("Total sum: %d\n",*sum);
	printf("Even array: \n");
	for(int i=0;i<*i1;i++){
		printf("par[%d]= %d\n",i,par[i]);
	}
	printf("Odd array: \n");
	for(int i=0;i<*i2;i++){
		printf("par[%d]= %d\n",i,impar[i]);
	}

	pthread_mutex_destroy(m);
	pthread_barrier_destroy(b);

	free(par);
	free(impar);
	free(args);
	free(sum);
	free(m);
	free(b);
	free(i1);
	free(i2);

	return 0;
}
