/* Program to create a binary tree from a string representation of it. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node Node;

struct Node {
	char data;
	Node *left, *right;
};

char isAlpha(char character) {
	unsigned int code = (char) character;
	char result = 0;
	if (code >= 65 && code <= 90 || code >= 97 && code <= 122) {
		result = 1;
	}
	return result;
}

void fromString(Node *root, char *string) {
	static size_t i = 0;
	// printf("%c - %ld\n", string[i], i);
	if (i < strlen(string)) {
		if (isAlpha(string[i])) {
			root->data = string[i];
			root->left = (Node*) calloc(1, sizeof(Node));
			root->right = (Node*) calloc(1, sizeof(Node));
			i++;
			fromString(root->left, string);
			i++;
			fromString(root->right, string);
		} else {
			root = NULL;
		}
	}
	return;
}

void printInOrder(Node *root) {
	if (root == NULL) return;
	printInOrder(root->left);
	printf("%c ", root->data);
	printInOrder(root->right);
}

int main() {
	Node *root = (Node*) calloc(1, sizeof(Node));
	char string[] = "ABD..EH...CFI..J..G..K..";

	fromString(root, string);

	printInOrder(root);
	printf("\n");

	return 0;
}
