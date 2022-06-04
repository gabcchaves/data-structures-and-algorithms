#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int array[], int lo, int hi) {
    // Pivot
    int pivot = array[lo];
    int leftWall = lo;
	// Check for left item
	for (int i = lo; i <= hi; i++) {
    	if (array[i] < pivot) {
        	swap(&array[i], &array[leftWall]);
        	leftWall++;
    	}
	}

	swap(&pivot, &array[leftWall]);
	return leftWall;
}

void quickSort(int array[], int lo, int hi) {
    if (lo < hi) {
        int pivotLocation = partition(array, lo, hi);
		quickSort(array, lo, pivotLocation);
		quickSort(array, pivotLocation+1, hi);
    }
}

void printArray(int array[], int size) {
    printf("[ ");
    for (int i = 0; i < size; i++)
        printf("%d ", array[i]);
    printf("]\n");
}

void fillArrayRandomly(int array[], int size) {
    time_t t;
    srand((unsigned) time(&t));
    for (int i = 0; i < size; i++)
        array[i] = rand() % 20;
}

int main() {
    time_t t;
    srand((unsigned) time(&t));

    int array[rand() % 7 + 7];
    int size = sizeof(array) / sizeof(array[0]);
    fillArrayRandomly(array, size);

	printArray(array, size);
	quickSort(array, 0, size-1);
	printArray(array, size);

    return 0;
}
