#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

int main(int argc, char** argv){

	int a2p,p2a,a,b,s,p;
    a2p = open("a2p",O_WRONLY);
	p2a = open("p2a",O_RDONLY);
	while(1){
		read(p2a,&a,sizeof(int));
		read(p2a,&b,sizeof(int));
		s=a+b;
		p=a*b;
		write(a2p,&s,sizeof(int));
		write(a2p,&p,sizeof(int));
		if(s==p)
			break;
	}
	close(a2p);close(p2a);
    return 0;
}
