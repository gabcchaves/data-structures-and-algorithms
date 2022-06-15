/* Sort a random array, given its number of elements. */
#include <stdio.h>
#include "../../../util.h"

void sort(int array[], int size) {
	for (int i = 1; i < size; i++) {
		int key = array[i];
		int j = i - 1;
		while (j >= 0 && array[j] > key) {
			array[j+1] = array[j];
			j = j - 1;
		}
		array[j+1] = key;
	}
}

int main() {
	unsigned int size;
	scanf("%u", &size);
	int array[size];
	unsortedFill(array, size);
	printArray(array, size);
	sort(array, size);
	printArray(array, size);
	return 0;
}

