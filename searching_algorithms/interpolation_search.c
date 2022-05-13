#include <stdio.h>

int interpolation(int * array, int size, int target) {
	int lo = 0;					// Lower bound of [sub]array
	int mid = -1;				// Mid of [sub]array
	int hi = size - 1;	// Higher bound of [sub]array
	
	while (array[mid] != target) {
		// If not found target
		if (lo == hi || array[lo] == array[hi])
			return -1;

		// Set mid of [sub]array
		mid = lo + ((hi - lo) / (array[hi] - array[lo])) * (target - array[lo]);

		// If target found
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

	int pos = interpolation(array, size, 5);
	
	printf("%d\n", pos);
}

