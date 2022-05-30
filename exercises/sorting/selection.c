#include <stdio.h>

void swap( int *a, int *b ) {
	int temp = *b;
	*b = *a;
	*a = temp;
}

void sort( int array[], int size ) {
	// Set min to location 0
	int min;
	for (int i = 0; i < size; i++) {
		min = i;
		for (int j = i+1; j < size; j++) {
			if (array[j] < array[min]) {
				min = j;
			}
		}
		swap(&array[min], &array[i]);
	}
}

int main() {
	int array[] = {2, 3, 4, 5, 6, 1, 4, 8, 10, 2, 7};
	size_t size = sizeof(array)/sizeof(array[0]);
	sort(array, size);
	for (int i = 0; i < size; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
	return 0;
}
