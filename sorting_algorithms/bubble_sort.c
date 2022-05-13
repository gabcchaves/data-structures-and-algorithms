#include <stdio.h>
#include <stdbool.h>
/* Bubble sort algorithm */

void sort(int * array, int size) {
	bool all_sorted = false;

	while (!all_sorted) {
		all_sorted = true;

		for (int i = 0; i < size-1; i++) {
			if (array[i] > array[i+1]) {
				int aux = array[i];
				array[i] = array[i+1];
				array[i+1] = aux;
				all_sorted = false;
			}
		}
	}
}

void main() {
	int array[] = {14, 33, 27, 35, 10};
	size_t size = sizeof(array) / sizeof(array[0]);

	for (int i = 0; i < size; i++)
		printf("%d ", array[i]);
	
	sort(array, size);

	printf("\n");
	for (int i = 0; i < size; i++)
		printf("%d ", array[i]);

	printf("\n");
}
