#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	int *digits;
	int *letters;
	int *characters;
	char* string;
	pthread_mutex_t *mutex_c, *mutex_l,*mutex_d;

}thread_args;

void* f(void* a){
	thread_args* args = (thread_args*)a;
	for(int i=0;i<strlen(args->string);i++){
		if(args->string[i]>='0' && args->string[i]<='9'){
			pthread_mutex_lock(args->mutex_d);
			(*args->digits)++;
			pthread_mutex_unlock(args->mutex_d);
		}
		else if(  ( args->string[i]>='a' &&  args->string[i]<='z' ) ||  ( args->string[i]>='A' &&  args->string[i]<= 'Z')){
				pthread_mutex_lock(args->mutex_l);
				(*args->letters)++;
				pthread_mutex_unlock(args->mutex_l);
		}
		else{
			pthread_mutex_lock(args->mutex_c);
			(*args->characters)++;
			pthread_mutex_unlock(args->mutex_c);
		}
	}
	free(args->string);
	free(args);
	return NULL;
}

int main(int argc, char** argv){
	
	if(argc<2){
		printf("Please enter at least 1 string\n");
		return 1;
	}
	
	int n=argc-1;
	pthread_t t[n];
	pthread_mutex_t mutex_c;
	pthread_mutex_t mutex_l;
	pthread_mutex_t mutex_d;
	pthread_mutex_init(&mutex_c,NULL);
	pthread_mutex_init(&mutex_l,NULL);
	pthread_mutex_init(&mutex_d,NULL);

	int digits=0;
	int letters=0;
	int characters=0;

	for(int i=1;i<=n;i++){
		thread_args *a = malloc(sizeof(thread_args));
		a->mutex_c=&mutex_c;
		a->mutex_l=&mutex_l;
		a->mutex_d=&mutex_d;

		a->digits=&digits;
		a->letters=&letters;
		a->characters=&characters;
		a->string= malloc(sizeof(char)*(1+strlen(argv[i])));
		strcpy(a->string,argv[i]);
		pthread_create(&t[i],NULL,f,a);
	}
	
	for(int i=1;i<=n;i++){
		pthread_join(t[i],NULL);
	}

	printf("digits: %d\nletters: %d\ncharacters: %d\n",digits,letters,characters);
	pthread_mutex_destroy(&mutex_c);
	pthread_mutex_destroy(&mutex_l);
	pthread_mutex_destroy(&mutex_d);
	return 0;
}
