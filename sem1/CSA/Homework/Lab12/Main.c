//Read a string of signed numbers in base 10 from keyboard. Determine the minimum value of the string and write it in the file min.txt (it will be //created) in 16 base.

#include <stdio.h>
#include <limits.h>

extern int find_minimum(const int *numbers,const int n);

int main() 
{
    int n,minimum;

    // Ask the user how many numbers they want to input
    printf("Enter the number of integers: ");
    scanf("%d", &n);

    // Define an array to hold the numbers
    int numbers[10001];
    
    // Read the numbers from the keyboard
    printf("Enter the integers:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
    }

    minimum=find_minimum(numbers,n);

    // Open the file for writing
    FILE *file = fopen("min.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    // Write the minimum value in hexadecimal format
    fprintf(file, "%X\n", minimum);

    // Close the file
    fclose(file);

    printf("The minimum value in hexadecimal is written to min.txt\n");

    return 0;
}
