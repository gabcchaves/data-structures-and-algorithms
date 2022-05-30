/* Jump searching algorithm practise */
#include <stdio.h>
#include <math.h>

// Implementation
int find(int * array, int size, int target) {
	int bs = sqrt(size); // Block size
	int bfloor = 0;		 // Block lower bound
	// Try to find possible block
	for ( int i = bfloor; i < size; i++ ) {
		if ( array[i] == target ) {
			return i;
		} else if (array[i] > target) {
			break;
		}
		bfloor = i;
	}
	// Do a linear search on possible block
	for ( int i = bfloor; i < bfloor + bs; i++ ) {
		if ( array[i] == target ) {
			return i;
		}
	}
	return -1; /* Not found */
}
int main() {
	int array[] = {1, 2, 3, 4, 5, 6, 7};
	int size = sizeof(array) / sizeof(array[0]);
	int target = 6;
	int pos = find(array, size, target);
	if (pos >= 0) {
		printf("%d está na posição %d.\n", target, pos);
	} else {
		printf("%d ausente do vetor.\n", target);
	}
	return 0;
}

