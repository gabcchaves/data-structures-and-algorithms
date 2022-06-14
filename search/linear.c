/* Linear searchinig algorithm */
// Time complexity: O(n)
// Space complexity: O(1)
#include <stdio.h>
#include "../util.h"

int find(int array[], int size, int target) {
	for (int i = 0; i < size; i++)
		if (array[i] == target) return i;
	return -1;
}

int main() {
	int array[] = {2, 1, 3, 5, 1, 2, 5, 6, 8};
	int size = sizeof(array) / sizeof(array[0]);

	printArray(array, size);

	int i = find(array, size, 3);

	printf("%d\n", i);

	return 0;
}

