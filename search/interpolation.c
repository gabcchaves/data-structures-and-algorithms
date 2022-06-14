/* Interpolation searching algorithm */
#include <stdio.h>
#include "../util.h"

int find(int array[], int lo, int hi, int key) {
	while (lo <= hi) {
		// Compute the estimated position
		int pos = lo + (key - array[lo]) * (hi - lo) / (array[hi] - array[lo]);

		// Check if it matches
		if (array[pos] == key) {
			return pos;
		} else if (array[pos] > key) {
			hi = pos - 1;
		} else {
			lo = pos + 1;
		}
	}
	return -1;
}

int main() {
	int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int size = sizeof(array) / sizeof(array[0]);

	int i = find(array, 0, size - 1, 5);

	printArray(array, size);
	printf("%d\n", i);

	return 0;
}

