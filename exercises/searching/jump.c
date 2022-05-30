/* Jump searching algorithm practise */
#include <stdio.h>
#include <math.h>

int find(int * array, int size, int target) {
	int blockSize = sqrt(size);
	int blockLBound = 0;
	// Find the possible block
	for (int i = 0; i < size; i += blockSize) {
		if (array[i] == target) {
			return i;
		} else if (array[i] > target) {
			break;
		}
		blockLBound = i;
	}
	// Do linear search on block
	for (int i = blockLBound; i < blockLBound + blockSize; i++) {
		if (array[i] == target) {
			return i;
		}
	}
	return -1;
}

int main() {
	int array[] = {1, 2, 3, 4, 5, 6, 7};
	int size = sizeof(array) / sizeof(array[0]);
	int target = 7;
	int pos = find(array, size, target);
	if (pos >= 0) {
		printf("%d está na posição %d.\n", target, pos);
	}
	return 0;
}

