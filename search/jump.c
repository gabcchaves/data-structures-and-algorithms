/* Jump searching algorithm */
#include <stdio.h>
#include <math.h>
#include "../util.h"

int find(int array[], int size, int key) {
	int bs = sqrt(size);
	for (int i = bs; i < size; i++) {
		/// Check if block boundary index contains the key
		if (array[i] == key) return i;
		// Check if the key is in the past block
		if (array[i] > key) {
			// Do a linear search in the block
			for (int j = i - bs; j < i; j++) {
				if (array[j] == key) return j;
			}
			return -1; // Not found
		}
	}
}

int main() {
	int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int size = sizeof(array) / sizeof(array[0]);

	int i = find(array, size, 5);

	printArray(array, size);
	printf("%d\n", i);
	return 0;
}

