/* Program to find the highest prime number in an array
 * using linear search */

#include <stdio.h>

int find(int array[], int size, int target) {
	for (int i = 0; i < size; i++) {
		if (array[i] == target)
			return i;
	}
	return -1;
}

int main() {
	int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};	
	size_t size = sizeof(array) / sizeof(array[0]);
	int target = 4;

	int pos = find(array, size, target);

	printf("[ ");
	for (int i = 0; i < size; i++) {
		printf("%d ", array[i]);
	}
	printf("]");

	if (pos != 1)
		printf("\n%d está na posição %d.\n", target, pos);
	else
		printf("\n%d não está na lista.\n", target);

	return 0;
}
