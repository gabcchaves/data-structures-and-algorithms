#include <stdio.h>
/* Selection sorting algorithm
 * */

int sort(int * array, int size) {
	for (int i = 0; i < size; i++) {
		// Do a linear search
		int least = array[i];
		int least_index = i;
		for (int j = i+1; j < size; j++) {
			if (array[j] < least) {
				least = array[j];
				least_index = j;
			}
		}
		int swap_aux = array[i];
		array[i] = array[least_index];
		array[least_index] = swap_aux;
	}
}

void main() {
	int array[] = {14, 33, 27, 10, 35, 19, 42, 44};
	size_t size = sizeof(array) / sizeof(array[0]);
	
	for (int i = 0; i < size; i++)
		printf("%d ", array[i]);

	sort(array, size);

	printf("\n");
	for (int i = 0; i < size; i++)
		printf("%d ", array[i]);
	printf("\n");
}
