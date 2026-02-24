#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char** argv){

        int i;
        FILE* fp;

        fp=popen("less","w");
        for(i=99;i>0;i--){
                fprintf(fp,"%d bottles of beer on the wall\n",i);
        }
        pclose(fp);
        return 0;
}
