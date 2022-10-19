/* Some utilities frequently used in this repository. */
#ifndef UTIL_H
#define UTIL_H

// Print a short integer array.
void printShortArray(short array[], size_t length) {
	for (size_t i = 0; i < length; i++) {
		printf("%hd ", array[i]);
	}
	printf("\b");
}

// Print an "word size" integer array.
void printIntArray(int array[], size_t length) {
	for (size_t i = 0; i < length; i++) {
		printf("%d ", array[i]);
	}
	printf("\b");
}

// Print a long integer array.
void printLongArray(long array[], size_t length) {
	for (size_t i = 0; i < length; i++) {
		printf("%ld ", array[i]);
	}
	printf("\b");
}

// Print an unsigned short integer array.
void printUshortArray(unsigned short array[], size_t length) {
	for (size_t i = 0; i < length; i++) {
		printf("%hu ", array[i]);
	}
	printf("\b");
}

// Print an unsigned integer array.
void printUintArray(unsigned int array[], size_t length) {
	for (size_t i = 0; i < length; i++) {
		printf("%u ", array[i]);
	}
	printf("\b");
}

// Print an unsigned long integer array.
void printUlongArray(unsigned long array[], size_t length) {
	for (size_t i = 0; i < length; i++) {
		printf("%lu ", array[i]);
	}
	printf("\b");
}

#endif
