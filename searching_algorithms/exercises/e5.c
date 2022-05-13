#include <stdio.h>
/* Find a target value in array
 * using ternary search
 * algorithm. */

int find(int * array, int size, int target) {
	int lo = 0, hi = size - 1;
	
	do {
		int mid1 = lo + (hi - lo) / 3;
		int mid2 = hi - (hi - lo) / 3;

		if (array[mid1] == target) return mid1;
		if (array[mid2] == target) return mid2;

		if (target < array[mid1]) {
			hi = mid1 - 1;
		} else if (target > array[mid2]) {
			lo = mid2 + 1;
		} else {
			lo = mid1 + 1;
			hi = mid2 - 1;
		}
	} while (lo != hi && array[lo] != array[hi]);

	return -1;
}
void main() {
	int array[] = {10, 12, 19, 23, 27, 30, 80};
	size_t size = sizeof(array) / sizeof(array[0]);

	int pos = find(array, size, 19);

	printf("%d\n", pos);
}
