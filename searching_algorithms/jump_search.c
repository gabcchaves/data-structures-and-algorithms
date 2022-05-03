// Jump searching algorithm
#include <stdio.h>
#include <math.h>
#include "../util/util.h"

// Implementation
int jumpSearch( int * array, int arrayLength, int element ) {
	// In the best case, the block size
	// is sqrt(n)
	int blockSize = sqrt( arrayLength );
	int LBound = 0, UBound = blockSize;
	
	// Search for the block where the element is
	while ( array[UBound] <= element &&  UBound < arrayLength ) {
		LBound = UBound;
		UBound += blockSize;
		if ( UBound > arrayLength-1 )
			UBound = arrayLength;
	}

	for ( int i = LBound; i < UBound; i++ )
		if ( array[i] == element ) return i;

	return -1;
}

void main() {
	int array[] = { 1, 2, 4, 7, 10, 28, 34 };
	int element = 28;
	size_t arrayLength = sizeof(array) / sizeof(array[0]);

	int index = jumpSearch( array, arrayLength, element );
	if ( index != -1 ) {
		printf("%d está na posição %d.\n", element, index);
		printArray( array, arrayLength );
	} else {
		printf("Elemento não encontrado.\n");
	}
}
