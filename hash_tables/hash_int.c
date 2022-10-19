/* Simple hash table of positive integers, without zero as value. */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../lib/util.h"

// Initialize hash table.
unsigned short* newHashTable(const size_t HT_LENGTH) {
	unsigned short *array = (unsigned short*) malloc(HT_LENGTH * sizeof(unsigned short));
	memset(array, 0, HT_LENGTH);
	return array;
}

// Hash function.
unsigned short get(unsigned int key, unsigned int table_length) {
	return key % table_length;
}

// Add element to the hash table.
char insert(unsigned short hash_table[], const size_t HT_LENGTH, unsigned short key) {
	unsigned short value = get(key, HT_LENGTH);
	if (value < HT_LENGTH) {
		
	}
}

int main() {
	const size_t HT_LENGTH = 10;
	unsigned short *hash_table = newHashTable(HT_LENGTH);

	printUshortArray(hash_table, HT_LENGTH);
	printf("\n");

	//unsigned short hash_values[] = {
	//};

	//size_t length_hash_values = sizeof(hash_values) / sizeof(hash_values[0]);

	//printUshortArray(hash_values, length_hash_values);
	//printf("\n");

	//printf("%u\n", hash_table[hash_values[0]]);
	return 0;
}

