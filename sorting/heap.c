/* Heap sorting algorithm. */
#include <stdio.h>
#include "../util.h"

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void heapify(int array[], int size, int i) {
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < size && array[left] > array[largest])
		largest = left;

	if (right < size && array[right] > array[largest])
		largest = right;

	if (largest != i) {
		swap(&array[i], &array[largest]);
		heapify(array, size, largest);
	}
}

void sort(int array[], int size) {
	for (int i = size / 2 - 1; i >= 0; i--)
		heapify(array, size, i);

	for (int i = size - 1; i >= 0; i--) {
		swap(&array[0], &array[i]);
		heapify(array, i, 0);
	}
}

int main() {
	int array[] = {2, 1, 4, 5, 3};
	int size = sizeof(array) / sizeof(array[0]);

	unsortedFill(array, size);
	printArray(array, size);
	sort(array, size);
	printArray(array, size);
	return 0;
}

