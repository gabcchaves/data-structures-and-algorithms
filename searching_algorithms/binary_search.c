// Binary searching algorithm
#include <stdio.h>

// Implementation
int binarySearch( int * array, int arrayLength, int element ) {
	// Lower and Upper bounds
	int LBound = array[0], UBound = array[arrayLength-1];

	while ( LBound <= UBound ) {
		// The mid point of the current sub-array
		int midPoint = (LBound + UBound) / 2;
		
		// Element is in the mid point?
		if ( element == array[midPoint] ) return midPoint;

		// Element is on the left?
		if ( element < array[midPoint] ) {
			UBound = midPoint;
			continue;
		}
		// Element is on the right?
		if ( element > array[midPoint] ) {
			LBound = midPoint;
			continue;
		}	
	}
	return -1;
}

// Print the array
void printArray( int * , int );

void main() {	
	// Binary search is designed for sorted DS
	int array[] = { 1, 2, 10, 17, 34, 47, 59 };
	int element = 34;
	size_t arrayLength = sizeof(array) / sizeof(array[0]);

	int index = binarySearch( array, arrayLength, element );
	
	if ( index != -1 ) {
		printf("%d está na posição %d.\n", element, index);
		printArray( array, arrayLength );
	} else {
		printf("Elemento não encontrado.\n");
	}
}

void printArray( int * array, int arrayLength ) {
	printf("[ ");
	for ( int i = 0; i < arrayLength; i++ ) {
		printf("%d ", array[i]);
	}
	printf("]\n");
}
