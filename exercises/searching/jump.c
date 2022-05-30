/* Jump searching algorithm practise */
#include <stdio.h>
#include <math.h>

int find(int * array, int size, int target) {
	int blockSize = sqrt(size);
	for (int i = blockSize; i < size - 1; i += blockSize) {
		if (target == array[i]) {
			return i;
		}
		if (target < array[i]) {
			for (int j = i - blockSize; j < i; j++) {
				if (array[j] == target) {
					return j;
				}
			}
		}
	}
	return -1;
}

int main() {
	int array[] = {1, 2, 3, 4, 5, 6, 7};
	int size = sizeof(array) / sizeof(array[0]);
	int target = 5;
	int pos = find(array, size, target);
	if (pos >= 0) {
		printf("%d está na posição %d.\n", target, pos);
	}
	return 0;
}

