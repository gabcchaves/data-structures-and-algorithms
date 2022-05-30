/* Selection sorting algorithm practise */
#include <stdio.h>

void sort( int * array, int size ) {
	// Run through array
	for ( int i = 0; i < size; i++ ) {
		// Find smallest number in unsorted subarray
		int smPos = i;
		for ( int j = i + 1; j < size; j++ ) {
			if ( array[j] < array[smPos] ) {
				smPos = j;
			} 
		}

		// Swap, if smaller than current position
		if ( array[i] > array[smPos] ) {
			int temp = array[i];
			array[i] = array[smPos];
			array[smPos] = temp;
		}
	}
}
int main() {
	int array[] = {12, 43, 54, 6, 2, 3, 4, 1, 5, 6, 7};
	int size = sizeof(array) / sizeof(array[0]);

	sort(array, size);

	printf("[ ");
	for ( int i = 0; i < size; i++ ) {
		printf("%d ", array[i]);
	}
	printf("]\n");
	
	return 0;
}

