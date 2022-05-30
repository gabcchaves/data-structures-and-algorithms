/* Selection sorting algorithm practise */
#include <stdio.h>

void sort( int *array, int size ) {
	for ( int i = 0; i < size; i++ ) {
		int smPos = i;
		for ( int j = i+1; j < size; j++ ) {
			if ( array[smPos] > array[j] ) {
				smPos = j;
			}
		}
		if ( array[i] > array[smPos] ) {
			int temp = array[i];
			array[i] = array[smPos];
			array[smPos] = temp;
		}
	}
}
int main() {
	int array[] = {2, 4, 1, 5, 6 ,7, 3};
	int size = sizeof( array ) / sizeof ( array[0] );
	
	sort( array, size );
	
	printf("[ ");
	for ( int i = 0; i < size; i++ ) {
		printf("%d ", array[i]);
	}
	printf("]\n");

	return 0;
}

