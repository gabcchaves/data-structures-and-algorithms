/* Binary searching algorithm exercise */
// Return the position of a number in the array, if found
#include <stdio.h>

int find(int array[], int size, int target) {
	int lbound = 0, ubound = size - 1;
	int mid;

	do {
		mid = lbound + (ubound - lbound) / 2;
		if (array[mid] == target) {
			return mid;
		} else if (array[mid] > target) {
			ubound = mid - 1;
		} else {
			lbound = mid + 1;
		}
	} while (lbound <= ubound);
	return -1;
}

int main() {
	int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	size_t size = sizeof(array) / sizeof(array[0]);
	int target = 7;

	int pos = find(array, size, target);

	printf("%d está na posição %d\n", target, pos);
	return 0;
}

