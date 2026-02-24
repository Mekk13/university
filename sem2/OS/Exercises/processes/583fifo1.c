#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(int argc, char** argv){
	int p2a, a2p, a,b,s,p;
    a2p = open("a2p",O_RDONLY);
    p2a = open("p2a",O_WRONLY);
	while(1){
        //a2p = open("a2p",O_RDONLY);
		//p2a = open("p2a",O_WRONLY);
		printf("a= "); scanf("%d",&a);
		printf("b= ");scanf("%d",&b);
		write(p2a,&a,sizeof(int));
		write(p2a,&b,sizeof(int));
		read(a2p,&s,sizeof(int));
		read(a2p,&p,sizeof(int));
		printf("sum = %d   product= %d\n",s,p);
		if(s==p)
			break;
	}
	close(p2a);close(a2p);
	unlink("p2a"); unlink("a2p");
	return 0;

}
