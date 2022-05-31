/* Merge sorting algorithm */
#include <stdio.h>

void merge(int *array, int lb, int mid, int ub) {
	int s1 = mid - lb + 1;
	int s2 = ub - mid;

	int l1[s1], l2[s2];
	for (int i = 0; i < s1; i++)
		l1[i] = array[lb + i];
	for (int i = 0; i < s2; i++)
		l2[i] = array[mid + 1 + i];

	int i = 0;  // 1st index of 1st subarray
	int j = 0;  // 1st index of 2nd subarray
	int k = lb; // 1st index of merged subarray
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

void sort(int *array, int lb, int ub) {
	if (lb < ub) {
		int mid = lb + (ub - lb) / 2;
		sort(array, lb, mid);
		sort(array, mid+1, ub);
		merge(array, lb, mid, ub);
	}
}

void printArray(int *array, int size) {
	printf("[ ");
	for (int i = 0; i < size; i++) {
		printf("%d ", array[i]);
	}
	printf("]\n");
}

int main() {
	int array[] = {3, 4, 9, 2, 5, 8, 2, 1, 7, 4, 6, 2, 9, 8, 5, 1};
	int size = sizeof(array) / sizeof(array[0]);
	printArray(array, size);
	sort(array, 0, size-1);
	printArray(array, size);
	return 0;
}
