/* Sort an array, given its number of elements and its elements. */
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
		array[j+1] = key; // Unstable
	}
}

int main() {
	unsigned int size;
	scanf("%u", &size);
	int array[size];

	for (int i = 0; i < size; i++)
		scanf("%d", &array[i]);

	printArray(array, size);
	sort(array, size);
	printArray(array, size);
	return 0;
}

