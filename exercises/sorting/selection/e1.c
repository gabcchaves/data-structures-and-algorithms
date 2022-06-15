/* Read the number of elements and sort a random array with the entered number
 * of elements. */
#include <stdio.h>
#include "../../../util.h"

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void sort(int array[], int size) {
	for (int i = 0; i < size-1; i++) {
		int least = i;
		for (int j = i + 1; j < size; j++) {
			if (array[i] > array[j]) {
				least = j;
			}
		}
		swap(&array[i], &array[least]);
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

