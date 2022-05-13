#include <stdio.h>
/* Find a target value in an
 * array using the linear search
 * algorithm. */

int find(int * array, int size, int target) {
	for (int i = 0; i < size; i++) {
		if (array[i] == target) return i;
	}
	return -1;
}

void main() {
	int array[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	size_t size = sizeof(array) / sizeof(array[0]);
	
	int pos = find(array, size, 4);
	
	printf("%d\n", pos);
}

