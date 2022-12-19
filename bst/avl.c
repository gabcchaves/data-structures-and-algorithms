/* Implementation of an AVL tree (balanced binary search tree). */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

struct Node {
	Node *left;
	Node *right;
	int balancing_factor;
	unsigned int key;
};

unsigned int getHeight(Node*);
short computeBalancingFactor(Node*);
Node* searchMinNode(Node*);
Node* searchMaxNode(Node*);
Node* rotateLeft(Node*);
Node* rotateRight(Node*);
Node* swapNodes(Node*, Node*);
Node* rotate(Node*);
Node* insert(Node*, unsigned int);
Node* search(Node*, unsigned int);
Node* delete(Node*, unsigned int);

unsigned int getHeight(Node *t) {
	unsigned int l = 0;

	if (t != NULL) {
		unsigned int left = getHeight(t->left) + 1;
		unsigned int right = getHeight(t->right) + 1;
		l = right >= left ? --right : --left;
	}

	return l;
}

short computeBalancingFactor(Node *t) {
	short height_right = getHeight(t->right);
	short height_left = getHeight(t->left);
	return height_right - height_left;
}

Node* searchMinNode(Node *t) {
	if (t->left != NULL)
		t = searchMinNode(t->left);
	return t;
}

Node* searchMaxNode(Node *t) {
	if (t->right != NULL)
		t = searchMaxNode(t->right);
	return t;
}

Node* rotateLeft(Node *t) {
	Node *u = t->right;
	Node *v = u->left;

	u->left = t;
	t->right = v;

	t->balancing_factor = computeBalancingFactor(t);
	u->balancing_factor = computeBalancingFactor(u);

	free(u);
	free(v);

	return t;
}

Node* rotateRight(Node *t) {
	Node *u = t->left;
	Node *v = u->right;

	u->right = t;
	t->left = v;

	t->balancing_factor = computeBalancingFactor(t);
	u->balancing_factor = computeBalancingFactor(u);

	free(u);
	free(v);

	return t;
}

Node* insert(Node *t, unsigned int key) {
	if (t != NULL && t->key != key) {
		if (t->key > key)
			t->left = insert(t->left, key);
		else
			t->right = insert(t->right, key);

		t->balancing_factor = computeBalancingFactor(t);

		// Left rotation.
		if (t->balancing_factor > 1 && t->right->left == NULL)
			t = rotateLeft(t);

		// Right rotation.
		if (t->balancing_factor < -1 && t->left->right == NULL)
			t = rotateRight(t);

		// Right-Left rotation
		if (t->balancing_factor > 1 && t->right->right == NULL) {
			t->right = rotateRight(t->right);
			t = rotateLeft(t);
		}

		// Left-Right rotation.
		if (t->balancing_factor < -1 && t->left->left == NULL) {
			t->left = rotateLeft(t->left);
			t = rotateRight(t);
		}
	}

	if (t == NULL) {
		t = (Node*) calloc(1, sizeof(Node));
		t->key = key;
		t->left = NULL;
		t->right = NULL;
		t->balancing_factor = 0;
	}

	return t;
}

Node* search(Node *t, unsigned int key) {
	if (t != NULL && t->key != key)
		t = search( (t->key > key ? t->left : t->right), key);
	return t;
}

void traverseInOrder(Node *t) {
	if (t != NULL) {
		traverseInOrder(t->left);
		printf("%u ", t->key);
		traverseInOrder(t->right);
	}
}

int main() {
	Node *tree = NULL;

	tree = insert(tree, 10);
	tree = insert(tree, 5);
	tree = insert(tree, 15);
	tree = insert(tree, 20);
	tree = insert(tree, 25);
	tree = insert(tree, 11);
	tree = insert(tree, 12);

	Node *r = search(tree, 10);

	printf("%d\n", (r != NULL ? r->key : -1) );
	
	r = search(tree, 5);
	printf("%d\n", (r != NULL ? r->key : -1) );

	r = search(tree, 15);
	printf("%d\n", (r != NULL ? r->key : -1) );

	r = search(tree, 20);
	printf("%d\n", (r != NULL ? r->key : -1) );

	printf("\n");
	traverseInOrder(tree);
	printf("\n");

	return 0;
}
