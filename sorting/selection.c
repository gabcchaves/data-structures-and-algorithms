/* Selection sorting algorithm */
#include <stdio.h>
#include "../util.h"

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void sort(int array[], int size) {
	// Traverse the array, selecting the position to be occuppied by the least
	// element of the unsorted subarray
	for (int i = 0; i < size-1; i++) {
		// Search for the least element in the unsorted subarray
		int least = i;
		for (int j = i + 1; j < size; j++) {
			if (array[j] < array[least])
				least = j;
		}
		swap(&array[i], &array[least]);
	}
}

int main() {
	int array[] = {2, 1, 5, 3, 4, 6, 7};
	int size = sizeof(array) / sizeof(array[0]);
	printArray(array, size);
	sort(array, size);
	printArray(array, size);
	return 0;
}

