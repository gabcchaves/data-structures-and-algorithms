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

// Binary search
int binSearch(int array[], int start, int end, int key) {
	if (start <= end) {
		int mid = start + (end - start) / 2;
		if (array[mid] == key) return mid;
		if (array[mid] > key) binSearch(array, start, mid - 1, key);
		if (array[mid] < key) binSearch(array, mid + 1, end, key);
	}
	return -1;
}

#endif
