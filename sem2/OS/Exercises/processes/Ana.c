#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>

int main(int argc, char** argv){
	
	//with pipes
	int a2b[2],b2p[2];
	char c[40];
	pipe(a2b);pipe(b2p);
	
	if(argc != 2){
		perror("invalid nr of args\n");
		return 0;
	}

	//child A
	if(fork()==0){
		close(a2b[0]);close(b2p[1]);close(b2p[0]);
		while(1){
			printf("> ");scanf("%s",c);
			int s=strlen(c)+1;
			if(write(a2b[1],&s,sizeof(int))<=0){
				perror("error 1\n");
				break;
			}
			if(write(a2b[1],c,strlen(c)+1)<=0){
				perror("error 2\n");
				break;
			}
			if(strcmp(c,argv[1])==0){
					break;
			}
		}
		close(a2b[1]);
		exit(0);
	}

	//child B
	int a[27]={0};
	if(fork()==0){
		close(a2b[1]);close(b2p[0]);
		int sz;
		char* c1;
		while(1){
			if(read(a2b[0],&sz,sizeof(int))<=0){
				perror("error 3\n");
				break;
			}
			c1=(char*)malloc(sz);
			read(a2b[0],c1,sz);
			for(int i=0;i<sz-1;i++){
				a[c1[i]-'a']++;
			}
			if(strcmp(c1,argv[1])==0){
				free(c1);
				break;
			}
			free(c1);
		}
		for(int i=0;i<26;i++){
			write(b2p[1],&a[i],sizeof(int));
		}
		close(a2b[0]);close(b2p[1]);
		exit(0);
	} 

	//parent
	
	close(a2b[0]);close(a2b[1]),close(b2p[1]);
	int total=0,num;
	for(int i=0;i<26;i++){
		read(b2p[0],&num,sizeof(int));
		total+=num;
	}
	wait(0);wait(0);
	printf("total characters: %d\n",total);
	close(b2p[0]);
	return 0;
}
