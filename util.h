#ifndef util
#define util

#include <time.h>
#include <stdlib.h>

void printArray(int array[], int size) {
	printf("[ ");
	for (int i = 0; i < size; i++)
		printf("%d ", array[i]);
	printf("]\n");
}

// Fill array with random elements (unsorted)
void unsortedFill(int array[], int size) {
	srand(time(NULL)); // Current time as seed for random generator
	for (int i = 0; i < size; i++)
		array[i] = rand() % 100;
}

// Fill array with random element (sorted)
void sortedFill(int array[], int size) {
	srand(time(NULL)); // Current time as seed for random generator
	for (int i = 0; i < size; i++)
		array[i] = rand() % 100;
	// TODO
}

// Binary search
int binSearch(int array[], int start, int end, int key) {
	if (start <= end) {
		int mid = (start + (end - start) / 2);
		if (array[mid] == key) return mid;
		if (array[mid] > key)
			binSearch(array, start, mid - 1, key);
		binSearch(array, mid + 1, end, key);
	}
	return -1;
}

// Result types for function returns that need to be treated.
typedef struct ResultInt {
	unsigned char status;	// If false (0), then it means error.
	int value;				// The value, which would more likely be read on success.
} ResultInt;

typedef struct ResultFloat {
	unsigned char status;	// If false (0), then it means error.
	float value;			// The value, which would more likely be read on success.
} ResultFloat;

typedef struct ResultGeneric {
	unsigned char status;
	ResultInt value_int;
	ResultFloat value_float;
	char is_float;
} ResultGeneric;

// Parse string number to floating point or to integer.
void parse(char *str_num, ResultGeneric target) {
	unsigned short num_seps = 0;
	for (int i = 0; i < strlen(str_num); i++) {
		if (!isdigit(str_num[i])) {
			if (str_num[i] == '.') {
				num_seps++;
				if (num_seps > 1) {
					target.status = 0;
				}
			} else {
				target.status = 0;
			}
		}
	}
	if (num_seps > 0) {
		target.status = 1;
		target.value_float.value = atof(str_num);
		target.is_float = 1;
	} else {
		target.status = 1;
		target.value_int.value = atoi(str_num);
		target.is_float = 0;
	}
}

#endif
