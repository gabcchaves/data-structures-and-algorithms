/* Binary searching algorithm practise */
#include <stdio.h>

int find(int * array, int size, int target) {
	int l = 0, u = size - 1, m;
	do {
		m = l + (u - l) / 2;
		if (array[m] == target) {
			return m;
		} else if (array[m] > target) {
			u = m--;
		} else {
			l = m++;
		}
	} while (l <= u);
	return -1;
}
int main() {
	int array[] = {1, 2, 3, 4, 5, 6, 7};
	int size = sizeof(array) / sizeof(array[0]);
	int target = 4;
	int pos = find(array, size, target);
	printf("%d está na posição %d.\n", target, pos);
	return 0;
}

