#include <stdio.h>
/* Ternary search algorithm */

int ternary(int * array, int size, int target) {
	// Lower and higher bounds
	int lo = 0, hi = size - 1;

	do {
		// Two mid points
		int mid1 = lo + (hi - lo) / 3;
		int mid2 = hi - (hi - lo) / 3;

		// If found target
		if (target == array[mid1]) return mid1;
		if (target == array[mid2]) return mid2;

		// Recur to blocks else
		if (target < array[mid1]) {
			hi = mid1 - 1;
		} else if (target > array[mid2]) {
			lo = mid2 + 1;
		} else {
			lo = mid1 + 1;
			hi = mid2 - 1;
		}
	} while (lo != hi || array[lo] != array[hi]);

	return -1; // Not found
}
void main() {
	int array[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	size_t size = sizeof(array) / sizeof(array[0]);

	int pos = ternary(array, size, 3);

	printf("%d\n", pos);
}

