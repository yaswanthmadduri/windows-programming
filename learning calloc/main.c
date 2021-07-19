#include <stdio.h>
#include <stdlib.h>

int main()
{
    // malloc --> garbage value, calloc --> initializes values to zero
    // both are dynamic allocations

    //  pointer = (cast-type*)calloc(number_of_elements, each_element_size);


    int* callocPointer; // base address of the array or block
    int noOfElements;
    int i;

    printf("Enter number of elements for memory allocation : ");
    scanf("%d", &noOfElements);
    printf("\nNumber of elements for memory allocation by calloc: %d\n", noOfElements);

    // Dynamically allocate memory using calloc()
    callocPointer = (int*)calloc(noOfElements, sizeof(int));

    // returns null if not allocated.
    if (callocPointer == NULL) {
        printf("Memory not allocated.\n");
        exit(0);
    }
    else {

        printf("Memory successfully allocated using calloc\n");

        for (i = 0; i < noOfElements; i++) {
            callocPointer[i] = i;
        }

        printf("The elements of the array are: ");

        for (i = 0; i < noOfElements;  i++) {
            printf(" \n %d", callocPointer[i]);
        }
    }

    free(callocPointer); // freeing the frozen memory of calloc


            for (i = 0; i < noOfElements;  i++) {
            printf("\n %d ", callocPointer[i]);
        }

    printf("\n\n\nMemory allocated through calloc is freed\n");

    return 0;
}
