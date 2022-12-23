#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

struct Node {
	unsigned short key;
	short bf;
	Node *left;
	Node *right;
};

Node* insert(Node*, unsigned short);
Node* search(Node*, unsigned short);
Node* delete(Node*, unsigned short);
Node* rotateLeft(Node*);
Node* rotateRight(Node*);
Node* searchMinNode(Node*);
unsigned short computeHeight(Node*);

Node* insert(Node *t, unsigned short k) {
	if (t != NULL) {
		if (k < t->key)
			t->left = insert(t->left, k);
		else if (k > t->key)
			t->right = insert(t->right, k);

		t->bf = (short) computeHeight(t->right) - computeHeight(t->left);

		if (t->bf < -1) {
			if (t->left->right == NULL)
				t = rotateRight(t);
			else {
				t->left = rotateLeft(t->left);
				t = rotateRight(t);
			}
		} else if (t->bf > 1) {
			if (t->right->left == NULL)
				t = rotateLeft(t);
			else {
				t->right = rotateRight(t->right);
				t = rotateLeft(t);
			}
		}
	} else {
		t = (Node*) calloc(1, sizeof(Node));
		t->key = k;
		t->bf = 0;
		t->left = NULL;
		t->right = NULL;
	}

	return t;
}

Node* search(Node *t, unsigned short k) {
	if (t != NULL && t->key != k)
		t = search((k < t->key ? t->left : t->right), k);
	return t;
}

Node* delete(Node *t, unsigned short k) {
	if (t != NULL) {
		if (k < t->key)
			t->left = delete(t->left, k);
		else if (k > t->key)
			t->right = delete(t->right, k);
		else {
			if (t->left == NULL) {
				t = t->right;
				if (t != NULL)
					free(t->right);
			} else if (t->right == NULL) {
				t = t->left;
				if (t != NULL)
					free(t->left);
			} else {
				Node *tmp = searchMinNode(t->right);
				t->key = tmp->key;
				t->right = delete(t->right, tmp->key);
				free(tmp);
			}
		}

		if (t != NULL) {
			t->bf = (short) computeHeight(t->right) - computeHeight(t->left);
			if (t->bf < -1) {
				if (t->left->right == NULL)
					t = rotateRight(t);
				else {
					t->left = rotateLeft(t->left);
					t = rotateRight(t);
				}
			} else if (t->bf > 1) {
				if (t->right->left == NULL)
					t = rotateLeft(t);
				else {
					t->right = rotateRight(t->right);
					t = rotateLeft(t);
				}
			}
		}
	}

	return t;
}

Node* rotateLeft(Node *t) {
	Node *pivot = t->right;
	t->right = pivot->left;
	pivot->left = t;
	return pivot;
}

Node* rotateRight(Node *t) {
	Node *pivot = t->left;
	t->left = pivot->right;
	pivot->right = t;
	return pivot;
}

Node* searchMinNode(Node *t) {
	if (t != NULL && t->left != NULL)
		t = searchMinNode(t->left);
	return t;
}

unsigned short computeHeight(Node *t) {
	unsigned short left = 0;
	unsigned short right = 0;

	if (t != NULL) {
		left = computeHeight(t->left) + 1;
		right = computeHeight(t->right) + 1;
	}

	return left >= right ? left : right;
}

void traverseInOrder(Node *t) {
	if (t != NULL) {
		traverseInOrder(t->left);
		printf("%hu ", t->key);
		traverseInOrder(t->right);
	}
}

void traversePostOrder(Node *t) {
	if (t != NULL) {
		traversePostOrder(t->left);
		traversePostOrder(t->right);
		printf("%hu ", t->key);
	}
}

int main() {
	Node *tree = NULL;

	tree = insert(tree, 50);
	tree = insert(tree, 30);
	tree = insert(tree, 20);
	tree = insert(tree, 70);
	tree = insert(tree, 40);

	traversePostOrder(tree);
	printf("\n");

	traverseInOrder(tree);
	printf("\n");

	printf("\n%hu\n", (search(tree, 70))->key);

	tree = delete(tree, 50);

	traversePostOrder(tree);
	printf("\n");

	return 0;
}
