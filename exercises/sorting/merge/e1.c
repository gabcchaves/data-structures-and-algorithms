/* Sort an array, given its number of elements. */
#include <stdio.h>
#include "../../../util.h"

void merge(int array[], int l, int m, int r) {
	int s1 = m - l + 1;
	int s2 = r - m;

	int l1[s1], l2[s2];
	for (int i = 0; i < s1; i++)
		l1[i] = array[l + i];
	for (int i = 0; i < s2; i++)
		l2[i] = array[m + 1 + i];

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

void sort(int array[], int l, int r) {
	if (l < r) {
		int m = l + (r - l) / 2;

		sort(array, l, m);
		sort(array, m+1, r);

		merge(array, l, m, r);
	}
}

int main() {
	unsigned int size;
	scanf("%u", &size);
	int array[size];
	unsortedFill(array, size);
	printArray(array, size);
	sort(array, 0, size-1);
	printArray(array, size);
	return 0;
}

