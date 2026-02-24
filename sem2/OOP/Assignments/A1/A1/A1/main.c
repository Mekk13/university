#define _CRT_SECURE_NO_WARNINGS //foor scanf to work
#include <stdio.h>
#include <stdlib.h>
/*
Menu entries are expected for:
reading a vector of numbers from the console,
solving each of the 2 required functionalities,
exiting the program.
Each requirement must be resolved using at least one function. Functions communicate via input/output parameters and the return statement.
Provide specifications for all functions.

1.
a. Generate all the prime numbers smaller than a given natural number n.
b. Given a vector of numbers, find the longest increasing contiguous subsequence, such the sum of that any 
2 consecutive elements is a prime number.
*/

void menu() {

	printf("Menu:\n");
	printf("1. Read a vector of numbers\n");
	printf("2. Generate all the prime nrs. smaller than a given natural number n\n");
	printf("3. Find the longest increasing contiguous subsequence with the sum of each consec. nrs. = prime from the given vector\n");
	printf("4. Exit\n");

}

void read_array(int v[],int *n) {
	/// *n - pointer because in c we can't use &n to pass parameter by reference
	printf("Enter the number of elements in your array: ");
	(void) scanf("%d", n);  ///normally it would be &n but here we have int *n which is already an address :)
	printf("Enter each element separated by a space: ");
	for(int i = 0; i < *n; i++) { ///*n since n is a pointer! so we dereference it <3
		(void) scanf("%d", &v[i]);
	}
}

void prime_nrs() {

	///Erasthotene's sieve <3
	int n;
	printf("Enter the natural number n:");
	(void)scanf("%d",&n);

	if (n < 2) {
		printf("No primes below 2.\n");
		return;
	}


	int *is_prime = (int*)malloc(n * sizeof(int)); ///pointer to the beginning of a size n free segment on the heap 
	/// is_prime[i] will work like a normal aray. We use char because it's more efficient
	
	if (!is_prime)//check if memory allocation failed
	{
		printf("Memory allocation failed!");
		return;
	}

	memset(is_prime, 1, n); ///make them all 1:)
	
	for (int i = 2; i * i < n; i++)
	{
		if (is_prime[i])
		{
			for (int j = i * i; j < n; j += i)
				is_prime[j] = 0;
		}
	}
	for (int i = 2; i < n; i++) {
		if (is_prime[i]) printf("%d ", i);
	}
	printf("\n");
	free(is_prime);
}

void print_array(int v[], int n) {
	for (int i = 0; i < n; i++)
		printf("%d ", v[i]);
	printf("\n");
}

int main() {
	int v[101],n;
	
	return 0;
}