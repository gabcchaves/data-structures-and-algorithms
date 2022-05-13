/* Program algorithm to find the position of a target value
 * within a sorted integer array */
#include <stdio.h>

int find(int * array, int array_length, int element) {
	int lbound = 0, ubound = array_length - 1;
	do {
		int mid_pos = (lbound + ubound) / 2;	

		// Element found
		if (element == array[mid_pos])
			return mid_pos;

		// Element can only be in the right subarray
		if (element < array[mid_pos]) {
			ubound = mid_pos;	
			continue;
		}

		// Element can only be in the left subarray
		if (element > array[mid_pos]) {
			lbound = mid_pos;
			continue;
		}
	} while (lbound != ubound);

	// Element not found
	return -1;
}

void main() {
	int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	size_t array_length = sizeof(array) / sizeof(array[0]);

	int pos = find(array, array_length, 5);
	printf("%d\n", pos);
}
