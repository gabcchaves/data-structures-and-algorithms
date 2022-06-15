/* Merge sorting algorithm. */
#include <stdio.h>
#include "../util.h"

void merge(int array[], int left, int mid, int right) {
	/* Compute lengths of temporary arrays */
	int s1 = mid - left + 1;
	int s2 = right - mid;

	/* Create temporary arrays */
	int a1[s1], a2[s2];

	/* Copy data to temporary arrays */
	for (int i = 0; i < s1; i++)
		a1[i] = array[left + i];
	for (int i = 0; i < s2; i++)
		a2[i] = array[mid + 1 + i];

	/* Merge arrays */
	int a1I = 0, a2I = 0, a3I = left;
	while (a1I < s1 && a2I < s2) {
		if (a1[a1I] <= a2[a2I]) {
			array[a3I] = a1[a1I];
			a1I++;
		} else {
			array[a3I] = a2[a2I];
			a2I++;
		}
		a3I++;
	}

	/* Copy remaining elements to array */
	while (a1I < s1) {
		array[a3I] = a2[a1I];
		a1I++;
		a3I++;
	}
	while (a2I < s2) {
		array[a3I] = a2[a2I];
		a2I++;
		a3I++;
	}
}

void sort(int array[], int left, int right) {
	if (left >= right) return;

	int mid = (left + right) / 2;
	sort(array, left, mid);
	sort(array, mid+1, right);
	merge(array, left, mid, right);
}

int main() {
	int size = 5;
	int array[size];
	unsortedFill(array, size);
	printArray(array, size);
	sort(array, 0, size-1);
	printArray(array, size);
	return 0;
}
