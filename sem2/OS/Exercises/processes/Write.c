#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char** argv){
	int f,n;
	char* s;
	s = "Hello!";
	f = open("w2r",O_WRONLY);
	n = strlen(s) + 1;
	write(f,&n,sizeof(int));
	write(f,s,n);
	close(f);
	return 0;
}
