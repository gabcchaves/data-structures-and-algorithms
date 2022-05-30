/* Binary searching algorithm practise */
#include <stdio.h>

int find(int * array, int size, int target) {
	int l = 0, r = size - 1, mid;
	do {
		mid = l + (r - l) / 2;

		if (array[mid] == target) {
			return mid;
		} else if (array[mid] > target) {
			r = mid--;
		} else {
			l = mid++;
		}
	} while (l <= r);

	return -1;
}

int main() {
	int array[] = {1, 2, 3, 4, 5, 6, 7};
	int size = sizeof(array) / sizeof(array[0]);
	int target = 4;
	int pos = find(array, size, target);
	printf("%d está na posição %d.\n", target, pos);
	return 0;
}

