/* Merge sorting algorithm. */
#include <stdio.h>
#include <time.h>
#include "../util.h"

void merge(int array[], int left, int mid, int right) {
	int s1 = mid - left + 1;
	int s2 = right - mid;

	int l1[s1],  l2[s2];


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
	int array[] = {3, 1, 2};
	printArray(array, 3);
	sort(array, 0, 2);
	printArray(array, 3);
	return 0;
}
