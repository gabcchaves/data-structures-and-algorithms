#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort(int array[], int size) {
    for (int i = 0; i < size; i++) {
        char swapped = 0;
        for (int j = 0; j < size-1; j++) {
            if (array[j] > array[j+1]) {
                swap(&array[j], &array[j+1]);
                swapped = 1;
            }
        }
        if (!swapped) return;
    }
}

void fillArrayRandomly(int array[], int size) {
	time_t t;
	srand((unsigned) time(&t));

	for (int i = 0; i < size; i++)
    	array[i] = rand() % 20;
}

void printArray(int array[], int size) {
    printf("[ ");
    for (int i = 0; i < size; i++)
        printf("%d ", array[i]);
    printf("]\n");
}

int main() {
    // Random array length
    time_t t;
    srand((unsigned) time(&t));

	// Max 12, min 6
	int array[rand() % 6 + 6];
	int size = sizeof(array) / sizeof(array[0]);

	// Fill array with random integers
	fillArrayRandomly(array, size);

	// Print array
	printArray(array, size);

	// Sort array
	sort(array, size);

	// Print array
	printArray(array, size);

	return 0;
}
