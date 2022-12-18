#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

struct Node {
	unsigned int key;
	Node *left;
	Node *right;
};

Node* insert(Node*, unsigned int);
Node* search(Node*, unsigned int);
Node* delete(Node*, unsigned int);
Node* searchMinNode(Node*);

Node* insert(Node *t, unsigned int key) {
	if (t != NULL) {
		if (t->key > key)
			t->left = insert(t->left, key);
		else if (t->key < key)
			t->right = insert(t->right, key);
	} else {
		t = (Node*) calloc(1, sizeof(Node));
		t->key = key;
		t->left = NULL;
		t->right = NULL;
	}
	return t;
}

Node* search(Node *t, unsigned int key) {

	if (t != NULL && t->key != key)
		if (t->key > key)
			t = search(t->left, key);
		else if (t->key < key)
			t = search(t->right, key);

	return t;
}

Node* delete(Node *t, unsigned int key) {
	Node *ret = NULL;

	if (t->key != key && t != NULL) {
		t = delete( (t->key > key ? t->left : t->right), key);
	} else {
		if (t->left == NULL) {
			ret = t->right;
			free(t);
		} else if (t->right == NULL) {
			ret = t->left;
			free(t);
		} else {
			ret = searchMinNode(t->right);
			ret->left = t->left;
			if (ret != t->right) ret->right = t->right;
			free(t);
		}
	}

	return ret;
}

Node* searchMinNode(Node *t) {
	if (t->left != NULL)
		t = searchMinNode(t->left);
	return t;
}

int main() {
	Node *tree = NULL;
	tree = insert(tree, 10);
	tree = insert(tree, 15);
	tree = insert(tree, 5);

	Node *r = search(tree, 5);
	printf("%d\n", r != NULL ? r->key : -1);

	r = search(tree, 10);
	printf("%d\n", r != NULL ? r->key : -1);

	r = search(tree, 15);
	printf("%d\n", r != NULL ? r->key : -1);


	printf("\n");

	tree = delete(tree, 10);
	tree = delete(tree, 15);

	r = search(tree, 10);
	printf("%d\n", r != NULL ? r->key : -1);

	r = search(tree, 15);
	printf("%d\n", r != NULL ? r->key : -1);

	r = search(tree, 5);
	printf("%d\n", r != NULL ? r->key : -1);

	return 0;
}
