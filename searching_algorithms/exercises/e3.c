#include <stdio.h>
#include <math.h>
/* Find a target value in a
 * sorted array with the jump
 * search algorithm. */

int find(int * array, int size, int target) {
	// Block size to be jumped
	int step = floor(sqrt(size));
	int start = 0;
	int end = step;

	// Search for the block
	while (array[end] <= target && end < size) {
		start = end;
		end += step;
		if (end > size - 1)
			end = size;
	}

	// Linear search in the block
	for (int i = start; i < end; i++) {
		if (array[i] == target) return i;
	}

	return -1; // Not found
}

void main() {
	int array[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	size_t size = sizeof(array) / sizeof(array[0]);

	int pos = find(array, size, 4);

	printf("%d\n", pos);
}

