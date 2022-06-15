/* Sort a randomly generated array. */
#include <stdio.h>
#include <time.h>
#include "../../../util.h"

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void sort(int array[], int size) {
	for (int i = 0; i < size; i++) {
		int least = i;
		for (int j = i + 1; j < size; j++) {
			if (array[least] > array[j]) {
				least = j;
			}
		}
		swap(&array[i], &array[least]);
	}
}

int main() {
	srand(time(NULL));
	
	int size = rand() % 16 + 4;
	int array[size];
	unsortedFill(array, size);
	
	printArray(array, size);
	sort(array, size);
	printArray(array, size);
	
	return 0;
}

