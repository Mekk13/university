#define _CRT_SECURE_NO_WARNINGS //foor scanf to work
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Menu entries are expected for:
reading a vector of numbers from the console,
solving each of the 2 required functionalities,
exiting the program.
Each requirement must be resolved using at least one function. Functions communicate via input/output parameters and the return statement.
Provide specifications for all functions.

3.
a. Print the Pascal triangle of dimension n of all combinations C(m,k) of m objects taken by k, k = 0, 1, ..., m, for line m, where m = 1, 2, ..., n.
b. Given a vector of numbers, find the longest contiguous subsequence of prime numbers.
*/

void menu() {

	printf("Menu:\n");
	printf("1. Read a vector of numbers\n");
	printf("2. Print the pascal triangle of dimension n\n");
	printf("3. Given a vector of numbers, find the longest contiguous subsequence of prime numbers.\n");
	printf("4. Extra implementation: Generate the first n prime numbers (n is a given natural number).\n");
	printf("5. Exit\n");

}

int prime(int n) {
	//function that returns 1 if the given nr is prime and 0 otherwise
	if (n < 2)
		return 0;
	if (n == 2) return 1;
	for (int i = 2; i <= n / 2; i++)
	{
		if (n % i == 0)
			return 0;
	}
	return 1;
}

void generate_primes(int n,int primes[]) {
	//function that generates n primes and places them in the given array
	int nr=0,start=2,i=0;
	while (nr < n) {
		if (prime(start)) {
			primes[i] = start;
			nr++;
			i++;
		}
		start++;
	}
}

void read_array(int v[], int* n) {
	///function that reads an array with a given size
	/// *n - pointer because in c we can't use &n to pass parameter by reference
	printf("Enter the number of elements in your array: ");
	(void)scanf("%d", n);  ///normally it would be &n but here we have int *n which is already an address :)
	memset(v, 0, (*n) * sizeof(int));
	printf("Enter each element separated by a space: ");
	for (int i = 0; i < *n; i++) { ///*n since n is a pointer! so we dereference it <3
		(void)scanf("%d", &v[i]);
	}
}

long long combination(int n, int k) {
	///function that returns combination of n taken by k
	long long res = 1;
	if (k < n - k)
		k = n - k; // because Cmk=Cm,m-k
	for (int i = 0; i < k; i++) {
		res = res * (n - i) / (i + 1);
	}
	return res;
}

void pascal_triangle() {
	///function that creates and prints the pascal triangle of a given size n
	int n;
	printf("Enter pascal triangle size: ");
	(void) scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			printf("%lld ", combination(i, j));
		}
		printf("\n");
	}
}


void contiguous(int v[], int n) {
	///function that finds the longest contiguous subsequence of prime numbers and prints it 
	int max = 0;
	int start = -1, end = -1;
	int crrstart, crrend;
	int crrsum = 0;
	for (int i = 0; i < n; i++) {
		if (prime(v[i])) {
			if (crrsum == 0) {
				crrstart = i;
				crrend = i;
			}
			else {
				crrend++;
			}
			crrsum++;
		}
		else {
			if (crrsum > max) {
				max = crrsum;
				start = crrstart;
				end = crrend;
			}
			crrsum = 0;
		}
	}
	if (crrsum > max) {
		start = crrstart;
		end = crrend;
	}
	for (int i = start; i <= end; i++) {
		printf("%d ", v[i]);
	}
	printf("\n");
}

void print_array(int v[], int n){
	///simple function that prints a given array (given its size)
	for (int i = 0; i < n; i++)
		printf("%d ", v[i]);
	printf("\n");
}

int main() {
	int v[101],n=0,nr;
	int loop1 = 1;
	
	while (loop1) {
		menu();
		int choice;
		printf("Enter your choice (1-4): ");
		(void)scanf("%d", &choice);
		switch (choice) {
			case 1:
				read_array(v, &n);
				break;
			case 2:
				pascal_triangle();
				break;
			case 3:
				if (n == 0) {
					printf("Firstly, read an array!\n");
					break;
				}
				contiguous(v, n);
				break;
			case 4:
				printf("Give the n: ");
				(void)scanf("%d", &nr);
				int* primes = (int*)malloc(sizeof(int) * nr);
				int nr_primes;
				generate_primes(nr,primes);
				print_array(primes, nr);
				break;
			case 5:
				return 0;
			default:
				printf("\nInvalid option!\n\n");

		}
	}
	return 0;
}