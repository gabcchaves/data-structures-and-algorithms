/* Binary search algorithm */
#include <stdio.h>
#include "../util.h"

int find(int array[], int start, int end, int key) {
	if (start <= end) {
		int mid = start + (end - start) / 2;
		if (array[mid] == key) return mid;
		if (array[mid] > key) find(array, mid + 1, end, key);
		if (array[mid] < key) find(array, start, mid - 1, key);
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

