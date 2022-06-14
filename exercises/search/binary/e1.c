/* Given a sorted array of n integers and a target value, determine if the
 * target exists in the array in logarithmic time using the binary search
 * algorithm. If target exists in the array, print the index of it. */
#include <stdio.h>
#include "../../../util.h"

// Recursive implementation
int findRecursive(int array[], int start, int end, int key) {
	if (start <= end) {
		int mid = start + (end - start) / 2;
		if (array[mid] == key) return mid;
		if (array[mid] > key) findRecursive(array, start, mid - 1, key);
		if (array[mid] < key) findRecursive(array, mid + 1, end, key);
	}
	return -1;
}

// Iterative
int findIterative(int array[], int size, int key) {
	int start = 0, end = size - 1, mid;
	do {
		mid = start + (end - start) / 2;
		if (array[mid] == key) return mid;
		if (array[mid] > key) {
			end = mid - 1;
		} else if (array[mid] < key) {
			start = mid + 1;
		}
	} while (start <= end);
	return -1;
}

int main() {
	int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int size = sizeof(array) / sizeof(array[0]);

	printArray(array, size);

	puts("Recursivo:");
	int i = findRecursive(array, 0, size - 1, 5);
	printf("%d\n", i);

	puts("Iterativo:");
	i = findIterative(array, size, 5);
	printf("%d\n", i);

	return 0;
}
