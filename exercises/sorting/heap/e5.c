/* Sort a random array, given its length. */
#include <stdio.h>
#include "../../../util.h"

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void heapify(int array[], int arraySize, int rootNode) {
	int largestNode = rootNode;
	int leftChildNode = 2 * rootNode + 1;
	int rightChildNode = 2 * rootNode + 2;

	if (leftChildNode < arraySize && array[leftChildNode] > array[largestNode])
		largestNode = leftChildNode;
	if (rightChildNode < arraySize && array[rightChildNode] > array[largestNode])
		largestNode = rightChildNode;

	if (largestNode != rootNode) {
		swap(&array[rootNode], &array[largestNode]);
		heapify(array, arraySize, largestNode);
	}
}

void sort(int array[], int size) {
	for (int i = size / 2 - 1; i >= 0; i--)
		heapify(array, size, i);
	for (int i = size - 1; i >= 0; i--) {
		swap(&array[0], &array[i]);
		heapify(array, i, 0);
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

