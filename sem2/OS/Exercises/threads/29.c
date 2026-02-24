#include <pthread.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

typedef struct{
     int id;
     int* array;
     int number;
     int n;
}thread_args;

pthread_barrier_t barrier;
pthread_mutex_t mutex;

void* f(void* a){
      thread_args *args = (thread_args*)a;
      int id = args->id;
      int* array = args->array;
      int number=args->number;
      array[id]=number;
      printf("Thread %d placed the number %d\n",id, number);
      pthread_barrier_wait(&barrier);
      int size = args->n;
 
      int stop;
      while(1){
      	stop = -1;
	pthread_mutex_lock(&mutex);
	if(array[id]<=0)
		break;
	stop = 1;
	for(int i=0;i<size;i++){
		if(i!=id){
			array[i]--;
			if(array[i]>0)
				stop=0;
		}
	}
	if(stop == 1 ){
		break;
	}
	pthread_mutex_unlock(&mutex);
	usleep(100);
      }
      if(stop == -1)
	      printf("Thread %d has been eliminated\n",id);
      else
	      printf("Thread %d has won\n", id);
      pthread_mutex_unlock(&mutex);
      return NULL;
}

 
int main(int argc, char** argv){
      int n;
      if(argc !=2){
          printf("Please enter an argument!\n");
          exit(1);
      }
      n=atoi(argv[1]);
 
      pthread_barrier_init(&barrier,NULL,n);
      pthread_mutex_init(&mutex,NULL);
 
      pthread_t t[n];
      int *array = malloc(sizeof(int)*n);
 
      for(int i =0;i<n;i++){
          thread_args *args = malloc(sizeof(thread_args));
          args->id = i;
          args->array = array;
          args->number = rand()%11+10;
          args->n = n;
          pthread_create(&t[i],NULL,f,args);
      }
 
      for(int i=0;i<n;i++){
          pthread_join(t[i],NULL);
      }
      pthread_mutex_destroy(&mutex);
      pthread_barrier_destroy(&barrier);
 
      for(int i=0;i<n;i++){
          printf("array[%d]=%d\n",i,array[i]);
      }
 
      free(array);
 
	return 0;
 }
                             
