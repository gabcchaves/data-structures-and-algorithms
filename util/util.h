// Shared procedures/functions
#ifndef util
#define util 

#include <stdio.h>

// Print one-dimensional array
void printArray( int * array, int arrayLength ) {
	printf("[ ");
	for ( int i = 0; i < arrayLength; i++ ) {
		printf("%d ", array[i]);
	}
	printf("]\n");
}
	
#endif
