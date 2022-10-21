/* Implementation of a hash table using open addressing. */
#include <stdio.h>
#include <stdlib.h>

// Hash function.
size_t indexOf(size_t length, unsigned int key) {
  return key % length;
}

// Add element to hash table.
int addToHashTable(unsigned int hash_table[], size_t length, unsigned int key) {
  size_t i = indexOf(length, key);
  unsigned int num_cmps = 0;

  while (hash_table[i] != 0 && num_cmps != length) {
    i = (i + 1) % length;
    num_cmps++;
  }
  
  if (num_cmps != length) {
    hash_table[i] = key;
  }

  return num_cmps != length ? i : -1;
}

// Print hash table.
void printHashTable(unsigned int hash_table[], size_t length) {
  for (size_t i = 0; i < length; i++) {
    if (hash_table[i] != 0) {
      printf("%u ", hash_table[i]);
    }
  }
  printf("\b");
}

// Initialize hash table.
void initHashTable(unsigned int hash_table[], size_t length) {
  for (size_t i = 0; i < length; i++) {
    hash_table[i] = 0;
  }
}

int main() {
  size_t length = 10;
  unsigned int hash_table[10] = { 0 };
  addToHashTable(hash_table, length, 10);
  addToHashTable(hash_table, length, 11);
  addToHashTable(hash_table, length, 12);
  addToHashTable(hash_table, length, 10);
  
  printHashTable(hash_table, length);
  printf("\n");

  return 0;
}
