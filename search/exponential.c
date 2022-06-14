/* Exponential searching algorithm */
#include <stdio.h>
#include "../util.h"

/* For some reason it did not work with the binary search function I wrote in
 * the utilities header, so I wrote it again here. */

int bSearch(int array[], int start, int end, int key) {
	if (start <= end) {
		int mid = start + (end - start) / 2;
		if (array[mid] == key) return mid;
		if (array[mid] > key)
			return bSearch(array, start, mid - 1, key);
		return bSearch(array, mid + 1, end, key);
	}
	return -1;
}

int find(int array[], int start, int end, int key) {
	if ((end - start) <= 0) return -1;
	int i = 1;
	while (i < (end - start)) {
		if (array[i] < key) i *= 2;
		else break;
	}
	return bSearch(array, i/2, i, key);
}

int main() {
	int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int size = sizeof(array) / sizeof(array[0]);

	int i = find(array, 0, size - 1, 5);

	printArray(array, size);
	printf("%d", i);

	return 0;
}

