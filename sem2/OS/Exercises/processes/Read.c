#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char** argv){
	int r,n;
	char* s;
	r = open("w2r",O_RDONLY);
	
	read(r,&n,sizeof(int));
	s = (char*)malloc(n);
	read(r,s,n);
	printf("%s", s);
	free(s);
	close(r);
	return 0;
}
