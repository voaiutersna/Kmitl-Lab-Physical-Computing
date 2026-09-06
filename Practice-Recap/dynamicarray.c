#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    int size, i;
    int *arr;

    scanf("%d", &size);

    // Allocate memory for the array
    arr = (int*) malloc(sizeof(int)*size);

    // Populate the array
    for (i = 0; i < size; i++)
        *(arr+i) = i + 1;

    int *ptr = arr;  // Point to the first element of the array

    // Print the array in order using pointers
    printf("Array elements in order: ");
    i = 0;
    while (i<size){
        printf("%d ", *(ptr+i));
        i++;
    }
    printf("\n");

    // Print the array in reverse using pointers
    printf("Array elements in reverse: ");
    i = size-1;
    while (i>=0){
        printf("%d ", *(ptr+i));  // Move the pointer to the previous element
        i--;
    }
    printf("\n");

    // Free the allocated memory
    free(ptr);

    return 0;
}