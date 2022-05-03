// Sequential searching algorithm
#include <stdio.h>
#include "../util/util.h"

// Implementation
int search(int * array, int arrayLength, int element) {
	for (int i = 0; i < arrayLength; i++) {
		if (array[i] == element) {
			return i;	// Returns the index, if found the element
		}
	}
	return -1;
}

void main() {
	int array[] = {1, 32, 43, 21, 2, 4, 7};	
	int element = 21;
	size_t arrayLength = sizeof(array) / sizeof(array[0]);
	
	int index = search(array, arrayLength, element);
	if ( index != -1 ) {
		printf("%d está na posição %d.\n", element, index);
		printArray(array, arrayLength);
	} else {
		printf("Elemento não encontrado.\n");
	}
}
