/* Simple hash table of positive integers, without zero as value. */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// List.
typedef struct ListNode ListNode;
typedef struct List List;

struct ListNode {
	unsigned int data;
	ListNode *next;
};

struct List {
	ListNode *first;
	ListNode *last;
};

// Create a new list.
List* newList(size_t length) {
	List *list = (List*) malloc(length * sizeof(NULL));
	list->first = NULL;
	list->last = NULL;
	return list;
}

// Add element to list.
void addToList(List *list, unsigned int data) {
	ListNode *new_node = (ListNode*) malloc(sizeof(ListNode));
	new_node->data = data;
	new_node->next = NULL;
	
	if (list->first != NULL) {
		list->last->next = new_node;
		list->last = new_node;
	} else {
		list->first = new_node;
		list->last = new_node;
	}
}

// Remove element from the list.
void rm(List *list, unsigned int data) {
	ListNode *curr = list->first;
	ListNode *next = curr->next;
	while (next != NULL) {
		if (next->data == data) {
			curr->next = next->next;
		}
		curr = curr->next;
		next = curr->next;
	}
}

// Print list.
void printList(List *list) {
	ListNode *curr = list->first;
	while (curr != NULL) {
		printf("%u ", curr->data);
		curr = curr->next;
	}
	printf("\b");
}

// Create a new hash table.
List** newHashTable(size_t length) {
	List** ht = (List**) malloc(length * sizeof(List*));
	for (size_t i = 0; i < length; i++) {
		ht[i] = NULL;
	}
	return ht;
}

// Hash function.
size_t indexOf(size_t length, unsigned int key) {
	return key % length;
}

// Add element to hash table.
void addToHashTable(List* hash_table[], size_t length, unsigned int key) {
	size_t i = indexOf(length, key);
	if (hash_table[i] == NULL) {
		hash_table[i] = newList(1);
		addToList(hash_table[i], key);
	} else {
		addToList(hash_table[i], key);
	}
}

int main() {
	size_t length = 10;
	List *list = newList(length);
	
	addToList(list, 10);
	addToList(list, 20);
	addToList(list, 30);
	
	printList(list);
	printf("\n");
	
	List** hash_table = newHashTable(length);
	
	addToHashTable(hash_table, length, 10);
	
	printf("%u\n", hash_table[0]->first->data);

	return 0;
}