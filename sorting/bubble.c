/* Bubble sorting algorithm */
#include <stdio.h>
#include "../util.h"

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void sortIterative(int array[], int size) {
	char swapped;
	do {
		swapped = 0;
		for (int i = 0; i < size-1; i++) {
			if (array[i] > array[i+1]) {
				swap(&array[i], &array[i+1]);
				swapped = 1;
			}
		}
	} while (swapped);
}

void sortRecursive(int array[], int size) {
	if (size == 1) return;

	char swapped = 0;
	for (int i = 0; i < size; i++) {
		if (array[i] > array[i+1]) {
			swap(&array[i], &array[i+1]);
			swapped = 1;
		}
	}
	if (!swapped) return;

	sortRecursive(array, size - 1);
}

int main() {
	int array[] = {2, 1, 4, 5, 3, 6, 7};
	int size = sizeof(array) / sizeof(array[0]);

	printArray(array, size);

	puts("Iterativo:");
	sortIterative(array, size);
	printArray(array, size);

	puts("Recursivo:");
	sortRecursive(array, size);
	printArray(array, size);

	return 0;
}

