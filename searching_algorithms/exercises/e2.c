#include <stdio.h>
/* Find the position of a target
 * value in a sorted array with
 * the interpolation searching
 * algorithm. */

int find(int * array, int size, int target) {
	int lo = 0, mid = -1, hi = size - 1;	
	
	while (array[mid] != target) {
		// Target not found
		if (lo == hi || array[lo] == array[hi])
			return -1;

		// Set mid of [sub]array
		mid = lo + ((hi - lo) / (array[hi] - array[lo])) * (target - array[lo]);

		// If found
		if (array[mid] == target)
			return mid;
		
		// Either subarray
		if (target < array[mid])
			hi = mid - 1;
		else
			lo = mid + 1;
	}
}

void main() {
	int array[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	size_t size = sizeof(array) / sizeof(array[0]);

	int pos = find(array, size, 3);
	
	printf("%d\n", pos);
}

