#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(int argc, char** argv){

	int a2p[2],p2a[2],a,b,sum,prod;
	pipe(a2p);pipe(p2a);
	if(fork()==0){
		while(1){
			close(p2a[1]);
			close(a2p[0]);
			if(read(p2a[0],&a,sizeof(int))<=0){
					perror("Error reading\n");
					break;
			}
			if(read(p2a[0],&b,sizeof(int))<=0){
					perror("Error reading\n");
					break;
			}
			sum = a+b;
			prod = a*b;
			if(write(a2p[1],&sum,sizeof(int))<=0){
				perror("writing error\n");
				break;
			}
			if(write(a2p[1],&prod,sizeof(int))<=0){
				perror("writing error\n");
				break;
			}
			if(sum==prod){
				break;
			}
		}
		close(p2a[0]); close(a2p[1]);
		exit(0);
		
	}
	

	close(p2a[0]); close(a2p[1]);
	while(1){
		printf("a= "); scanf("%d",&a);
		printf("b= "); scanf("%d",&b);
		if(write(p2a[1],&a,sizeof(int))<=0){
			perror("writing error\n");
			break;
		}
		if(write(p2a[1],&b,sizeof(int))<=0){
			perror("writing error\n");
			break;
		}
		if(read(a2p[0],&sum,sizeof(int))<=0){
			perror("reading error\n");
			break;
		}
		if(read(a2p[0],&prod,sizeof(int))<=0){
			perror("reading error\n");
			break;
		}
		printf("sum: %d  product: %d\n",sum,prod);
		if(sum==prod)
			break;
	}
	close(p2a[1]);close(a2p[0]);
	wait(0);
	return 0;
}
