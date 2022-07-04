/* Stack implementation using linked list. */
#include <stdio.h>
#include <stdlib.h>

// Structure that represents a node
typedef struct Node {
	int data;
	struct Node *next;
} Node;

Node *top;

// Initialize stack
void initialize() {
	top = NULL;
}

// Add item onto the stack
void push(int item) {
	Node *tmp = malloc(sizeof(Node));
	tmp->data = item;
	tmp->next = top;
	top = tmp;
}

// Print all stack
void printStack(Node *top) {
	if (top == NULL) puts("NULL");
	else {
		printf("%d ", top->data);
		printStack(top->next);
	}
}

// Driver
int main() {
	initialize();
	printStack(top);

	push(1);
	printStack(top);

	push(2);
	printStack(top);

	push(3);
	printStack(top);
	return 0;
}
