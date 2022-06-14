/* Given a sorted array of n integers and a target value, determine if the
 * target exists in the array in logarithmic time using the binary search
 * algorithm. If target exists in the array, print the index of it. */
#include <stdio.h>
#include "../../../util.h"

// Recursive implementation
int find(int array[], int start, int end, int key) {
	if (start <= end) {
		int mid = start + (end - start) / 2;
		if (array[mid] == key) return mid;
		if (array[mid] > key) find(array, start, mid - 1, key);
		if (array[mid] < key) find(array, mid + 1, end, key);
	}
	return -1;
}

int main() {
	int array[9];
	int size = sizeof(array) / sizeof(array[0]);
	unsortedFill(array, size);

	int i = find(array, 0, size - 1, 10);
	printArray(array, size);
	printf("%d\n", i);
	return 0;
}
