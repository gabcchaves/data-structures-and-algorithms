/* Binary seraching algorithm practise */
#include <stdio.h>

int find(int array[], int size, int lbound, int ubound, int target) {

	if (lbound <= ubound) {
		int mid = lbound + (ubound - lbound) / 2;
		if (array[mid] == target) {
			return mid;
		}

		if (array[mid] > target) {
			return find(array, size, lbound, ubound - 1, target);
		} else {
			return find(array, size, lbound + 1, ubound, target);
		}
	}

	return -1;
}
int main() {
	int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	size_t size = sizeof(array) / sizeof(array[0]);
	int target = 5;

	int pos = find(array, size, 0, size-1, target);

	printf("%d está na posição %d.\n", target, pos);

	return 0;
}

