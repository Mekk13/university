#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void* f(void *a){
	char *string = (char*)a;
	for(int i=0;i<strlen(string);i++){
		if(string[i]>='A' && string[i]<='Z'){
			printf("%c",(string[i]-'A')+'a');
		}
		else
			printf("%c",string[i]);
	}
	printf(" ");
	return NULL;
}

int main(int argc, char** argv){

	int n=argc-1;
	pthread_t t[n];
	for(int i=1;i<=n;i++){
		pthread_create(&t[i],NULL,f,argv[i]);
	}
	for(int i=1;i<=n;i++){
		pthread_join(t[i],NULL);
	}
	printf("\n");	
	return 0;

}
