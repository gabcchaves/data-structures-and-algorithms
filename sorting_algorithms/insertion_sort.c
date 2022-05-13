#include <stdio.h>
/* Insertion sort algorithm */

void sort(int * array, int size) {
	int hole_pos, value_to_insert;

	for (int i = 1; i <= size; i++) {
		value_to_insert = array[i];
		hole_pos = i;

		// Swap if unsorted
		while (array[hole_pos-1] > value_to_insert) {
			array[hole_pos] = array[hole_pos-1];
			hole_pos--;
		}

		// Place value on right
		// place
		array[hole_pos] = value_to_insert;
	}
}

void main() {
	int array[] = {14, 33, 27, 10, 35, 19, 42, 44};
	size_t size = sizeof(array) / sizeof(array[0]);

	for (int i = 0; i < size; i++)
		printf("%d ", array[i]);

	sort(array, size);	

	printf("\n");
	for (int i = 0; i < size; i++)
		printf("%d ", array[i]);

	printf("\n");
}
