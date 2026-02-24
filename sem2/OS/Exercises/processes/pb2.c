#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(int argc, char** argv){
	int n = atoi(argv[1]);
	for(int i =0;i<n;i++){
		int f=fork();
		if(f==-1){
			perror("fork error");
		}
		else if(f==0){
			printf("Child %d : PID: %d PPID: %d\n",i,getpid(),getppid());
		}
		else{
			printf("Parent: %d - Child: %d\n",getpid(),f);
			wait(0);
			exit(0);
		}
	}
	return 0;
}
