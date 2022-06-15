/* Sort a random array, given the number of elements. */
#include <stdio.h>
#include "../../../util.h"

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void sort(int array[], int size) {
	char swapped = 0;
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

int main() {
	unsigned int size;
	scanf("%u", &size);
	int array[size];
	unsortedFill(array, size);
	printArray(array, size);
	sort(array, size);
	printArray(array, size);
	return 0;
}

