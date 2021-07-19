#include <stdio.h>
#include <stdlib.h>

int main()
{

	int *mallocPointer;
	int noOfElements, i;

	// 1 Get number of elements to be stored
	printf("Enter number of elements:");
	scanf("%d",&noOfElements);
	printf("Number of elements: %d\n", noOfElements);

	// 2 Dynamically allocate memory using malloc pointer function
	mallocPointer = (int*)malloc(noOfElements * sizeof(int));

	// 3 Check if the memory has been successfully allocated
	// malloc pointer function returns NULL if memory is not allocated
	if (mallocPointer == NULL) {
		printf("Memory is not allocated.\n");
		exit(0); // exits from the allocation.
	}
	else {

		printf("Memory successfully allocated using malloc \n");

		// 4 Get the elements of the array
		for (i = 0; i < noOfElements; i++) {
			mallocPointer[i] = i;
		}

		// Print the elements of the array
		printf("The elements of the array are: ");
		for (i = 0; i < noOfElements; i++) {
			printf("%d \t", mallocPointer[i]);
		}
	}

	return 0;
}
