#include <pthread.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct{
	int row;
	int columns;
	int* sums;
	int** matrix;
}thread_args;


void* f(void* a){
	thread_args *args=(thread_args* )a;
	args->sums[args->row]=0;
	for( int i=0;i<args->columns;i++){
		args->sums[args->row]+=args->matrix[args->row][i];
	}
	return NULL;
}


int main(int argc, char** argv){
	if ( argc != 2){
		printf("please enter the name of the file\n");
		return 1;
	}

	char* filename=argv[1];
	FILE* file = fopen(filename,"r"); 
	if (!file){
		perror("file error\n");
		return 1;
	}

	int rows,columns;
	fscanf(file,"%d",&rows);
        fscanf(file,"%d",&columns);
	int **matrix=malloc(sizeof(int*)*rows);
	for(int i=0;i<rows;i++){
		matrix[i]=malloc(sizeof(int)*columns);
	}

	for(int i=0;i<rows;i++){
		for(int j=0;j<columns;j++){
			fscanf(file,"%d",&matrix[i][j]);
		}
	}
	fclose(file);
	int *sums = malloc(sizeof(int)*rows);
	pthread_t t[rows];
	


	for(int i=0;i<rows;i++){
		thread_args* a=malloc(sizeof(thread_args));
		a->columns=columns;
		a->row=i;
		a->matrix=matrix;
		a->sums=sums;
		pthread_create(&t[i],NULL,f,a);
	}
	
	for(int i=0;i<rows;i++){
		pthread_join(t[i],NULL);
	}
	for(int i =0;i<rows;i++)
		printf("row %d = %d\n",i,sums[i]);

	return 0;
}
