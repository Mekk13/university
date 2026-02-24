#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(int argc, char**argv){

	int n;
	if(argc <2){
		printf("not enough variables.\n");
		return 1;
	}
	n=atoi(argv[1]);
	for(int i=0;i<n;i++){
		int pid = fork();
		if(pid == 0){
			printf("child %d: PID:%d  PPID:%d\n",i,getpid(),getppid());
			exit(0);
		}
		else{
			printf("Parent %d - Child: %d\n",getpid(),pid);
		}
	}
	for(int i=0;i<n;i++){
		wait(0);
	}
	return 0;
}
