#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <time.h>

int main(int argc, char** argv){
	int p2c[2],c2p[2];
	pipe(p2c);pipe(c2p);
	if(argc != 2){
		perror("Please insert exactly one n value");
	}
	int n;
	if(fork()==0){
		//we are in the child
		close(p2c[1]); close(c2p[0]);
		if(read(p2c[0],&n,sizeof(int))<=0){
			perror("error reading n\n");
			close(p2c[0]);close(c2p[1]);
			exit(1);
		}
		double sum=0;
		int k;
		for(int i=0;i<n;i++){
			if(read(p2c[0],&k,sizeof(int))<=0){
				perror("error reading a number\n");
				close(p2c[0]);close(c2p[1]);
				exit(1);
			}
			sum += k;
		}
		sum /= (double)n;
		if(write(c2p[1],&sum,sizeof(double))<=0){
			perror("error writing result\n");
			close(p2c[0]);close(c2p[1]);
			exit(1);		
		}
		close(p2c[0]);close(c2p[1]);
		exit(0);

	}

	//parent:
	close(p2c[0]);close(c2p[1]);
	n= atoi(argv[1]);
	srandom(time(NULL));
	if(write(p2c[1],&n,sizeof(int))<=0){
		perror("error writing n\n");
		close(p2c[1]);close(c2p[0]);
		exit(1);	
	}
	int nr;
	for(int i=0;i<n;i++){
		nr = random()%100;
		printf("Parent generated: %d\n",nr);
		if(write(p2c[1],&nr,sizeof(int))<=0){
			perror("error writing generated number\n");
			close(p2c[1]);close(c2p[0]);
			exit(1);	
		}
	}
	wait(0);
	double res;
	if(read(c2p[0],&res,sizeof(double))<=0){
		perror("error reading result\n");
		close(p2c[1]);close(c2p[0]);
		exit(1);	
	}
	printf("Average is: %f\n", res);
	close(p2c[1]);close(c2p[0]);
	return 0;
}
