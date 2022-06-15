/* Sort an array, given its number of elements and its elements. */
#include <stdio.h>
#include "../../../util.h"

void merge(int array[], int left, int mid, int right) {
	int s1 = mid - left + 1; // First half length
	int s2 = right - mid;	 // Second half length
	
	int l1[s1], l2[s2];
	for (int i = 0; i < s1; i++)
		l1[i] = array[left + i];
	for (int i = 0; i < s2; i++)
		l2[i] = array[mid + 1 + i];

	int i = 0, j = 0, k = 0;
	while (i < s1 && j < s2) {
		if (l1[i] <= l2[j]) {
			array[k] = l1[i];
			i++;
		} else {
			array[k] = l2[j];
			j++;
		}
		k++;
	}

	while (i < s1) {
		array[k] = l1[i];
		i++;
		k++;
	}

	while (j < s2) {
		array[k] = l2[j];
		j++;
		k++;
	}
}

void sort(int array[], int left, int right) {
	if (left < right) {
		int mid = left + (right - left) / 2;

		sort(array, left, mid);
		sort(array, mid + 1, right);

		merge(array, left, mid, right);
	}
}

int main() {
	unsigned int size;
	scanf("%u", &size);
	int array[size];
	for (unsigned int i = 0; i < size; i++)
		scanf("%d", &array[i]);

	printArray(array, size);
	sort(array, 0, size-1);
	printArray(array, size);

	return 0;
}
