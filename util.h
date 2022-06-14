#ifndef util
#define util

#include <time.h>
#include <stdlib.h>

void printArray(int array[], int size) {
	printf("[ ");
	for (int i = 0; i < size; i++)
		printf("%d ", array[i]);
	printf("]\n");
}

// Fill array with random elements (unsorted)
void unsortedFill(int array[], int size) {
	srand(time(NULL)); // Current time as seed for random generator
	for (int i = 0; i < size; i++)
		array[i] = rand() % 100;
}

// Fill array with random element (sorted)
void sortedFill(int array[], int size) {
	srand(time(NULL)); // Current time as seed for random generator
	for (int i = 0; i < size; i++)
		array[i] = rand() % 100;
	// TODO
}

#endif
