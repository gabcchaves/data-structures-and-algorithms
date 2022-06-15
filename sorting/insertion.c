/* Insertion sorting algorithm */
#include <stdio.h>
#include "../util.h"

void sort(int array[], int size) {
	for (int i = 1; i < size; i++) {
		int key = array[i]; // Save the current element
		int prevI = i - 1;  // Previous index

		// Compare previous elements
		while (prevI >= 0 && array[prevI] > key) {
			array[prevI + 1] = array[prevI];
			prevI = prevI - 1;
		}
		array[prevI + 1] = key;
	}
}

int main() {
	int size = 5;
	int array[size];
	unsortedFill(array, size);

	printArray(array, size);
	sort(array, size);
	printArray(array, size);
	
	return 0;
}
