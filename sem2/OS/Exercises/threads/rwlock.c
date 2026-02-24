#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int n = 0;
pthread_rwlock_t rwlock;

void *w(void *arg){
	for(int i=0;i<1000;i++){
		pthread_rwlock_wrlock(&rwlock);
		n++;
                pthread_mutex_unlock(&mtx);
		usleep(1000);
	}
	return NULL;
}

void *r(void *arg){
	pthread_mutex_lock(&mtx);
	printf("n = %d\n",n);
	pthread_mutex_lock(&mtx);
	return NULL;
}

int main(int argc, char** argv){
	pthread_t rth[1000];
	pthread_t wth[1];
	pthread_rwlock_init(&rwlock,NULL);
}
