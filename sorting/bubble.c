/* Bubble sorting algorithm */
#include <stdio.h>
#include "../util.h"

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void sort(int array[], int size) {
	char sorted = 0;
	while (!sorted) {
		sorted = 1;
		for (int i = 0; i < size-1; i++) {
			if (array[i] > array[i+1]) {
				swap(&array[i], &array[i+1]);
				sorted = 0;
			}
		}
	}
}

int main() {
	int array[] = {2, 1, 4, 5, 3, 6, 7};
	int size = sizeof(array) / sizeof(array[0]);
	printArray(array, size);
	sort(array, size);
	printArray(array, size);
	return 0;
}

