#include <stdio.h>
#include <stdlib.h>

int main()
{

	// holds base address of the pointer
	int *reallocPointer;
	int n, i;

	// Get the number of elements for the array
	printf("Enter number of elements: ");
	scanf("%d", &n);

	reallocPointer = (int*)calloc(n, sizeof(int));

	if (reallocPointer == NULL) {
		printf("Memory not allocated.\n");
		exit(0);
	}
	else {

		printf("Memory successfully allocated using calloc\n");

		for (i = 0; i < n; ++i) {
			reallocPointer[i] = i + 1;
		}

		printf("The elements of the array are: ");
		for (i = 0; i < n; ++i) {
			printf("%d \t ", reallocPointer[i]);
		}

		// Get the new size for the array
		printf("\n\nEnter the new size of the array: ");
		scanf("%d", &n);

		// Dynamically re-allocate memory using realloc()
		reallocPointer = realloc(reallocPointer, n * sizeof(int)); // n blocks, each of size 4 bytes ( i.e. size of int);

		// Memory has been successfully allocated
		printf("Memory successfully re-allocated using realloc.\n");

		// Get the new elements of the array
		for (i = 0; i < n; i++) {
			reallocPointer[i] = i+1;
		}

		// Print the elements of the array
		printf("The elements of the array are: ");
		for (i = 0; i < n; i++) {
			printf("%d \t ", reallocPointer[i]);
		}

		printf("\nFreeing the allocated space");
		free(reallocPointer);
		printf("\nFreed the allocated space");
	}

	return 0;
}
