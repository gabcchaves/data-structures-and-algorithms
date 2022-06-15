/* Sort a randomly generated array. */
#include <stdio.h>
#include <time.h>
#include "../../../util.h"

void sort(int array[], int size) {
	for (int i = 1; i < size; i++) {
		int key = array[i];
		int j = i - 1;
		while (j >= 0 && array[j] > key) {
			array[j+1] = array[j];
			j--;
		}
		array[j+1] = key;
	}
}

int main() {
	srand(time(NULL));
	unsigned int size = rand() % 8 + 4;
	int array[size];
	unsortedFill(array, size);
	printArray(array, size);
	sort(array, size);
	printArray(array, size);
	return 0;
}

