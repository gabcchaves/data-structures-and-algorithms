#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

struct Node {
	int bf;
	Node *left;
	Node *right;
	unsigned int key;
};

unsigned int computeHeight(Node*);
int computeBF(Node*);
Node* rotateLeft(Node*);
Node* rotateRight(Node*);
Node* insert(Node*, unsigned int);
Node* search(Node*, unsigned int);
Node* delete(Node*, unsigned int);
Node* getMinNode(Node*);
void traverseInOrder(Node*);

unsigned int computeHeight(Node *t) {
	unsigned int left = t != NULL ? computeHeight(t->left) + 1 : 1;
	unsigned int right = t != NULL ? computeHeight(t->right) + 1 : 1;
	return left >= right ? --left : --right;
}

int computeBF(Node *t) {
	unsigned int left = computeHeight(t->left);
	unsigned int right = computeHeight(t->right);
	return right - left;
}

Node* rotateLeft(Node *t) {
	Node *u = t->right;
	Node *v = u->left;

	u->left = t;
	t->right = v;

	t->bf = computeBF(t);
	u->bf = computeBF(u);

	return u;
}

Node* rotateRight(Node *t) {
	Node *u = t->left;
	Node *v = u->right;

	u->right = t;
	t->left = v;

	t->bf = computeBF(t);
	u->bf = computeBF(u);

	return u;
}

Node* insert(Node *t, unsigned int k) {
	if (t == NULL) {
		t = (Node*) calloc(1, sizeof(Node));
		t->key = k;
		t->left = NULL;
		t->right = NULL;
		t->bf = 0;
	} else {
		if (t->key != k) {
			if (k < t->key)
				t->left = insert(t->left, k);
			else
				t->right = insert(t->right, k);

			t->bf = computeBF(t);

			if (t->bf < -1 && t->left->right == NULL)
				t = rotateLeft(t);
			else if (t->bf < -1) {
				t->left	= rotateLeft(t->left);
				t = rotateRight(t);
			}

			if (t->bf > 1 && t->right->left == NULL)
				t = rotateRight(t);
			else if (t->bf > 1) {
				t->right = rotateRight(t->right);
				t = rotateLeft(t);
			}
		}
	}

	return t;
}

Node* search(Node *t, unsigned int k) {
	if (t != NULL && k != t->key)
		t = search( (k < t->key ? t->left : t->right), k);
	return t;
}

Node* delete(Node *t, unsigned int k) {
	if (t != NULL) {
		// Perform deletion.
		if (k < t->key)
			t->left = delete(t->left, k);
		else if (k > t->key)
			t->right = delete(t->right, k);
		else {
			if (t->left == NULL)
				t = t->right;
			else if (t->right == NULL)
				t = t->left;
			else {
				Node *tmp = getMinNode(t->right);
				t->key = tmp->key;
				t->right = delete(t->right, tmp->key);
			}
		}

		// Perform balancing, if necessary.
		t->bf = computeBF(t);
		if (t->bf < -1 && t->left->right == NULL)
			t = rotateLeft(t);
		else if (t->bf < -1) {
			t->left	= rotateLeft(t->left);
			t = rotateRight(t);
		}

		if (t->bf > 1 && t->right->left == NULL)
			t = rotateRight(t);
		else if (t->bf > 1) {
			t->right = rotateRight(t->right);
			t = rotateLeft(t);
		}
	}

	return t;
}

Node* getMinNode(Node *t) {
	return t->left != NULL ? getMinNode(t->left) : t;
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
	tree = insert(tree, 20);
	tree = insert(tree, 30);

	traverseInOrder(tree);
	printf("\n");

	Node *r = search(tree, 20);
	printf("%d\n", r != NULL ? r->key : -1);

	tree = delete(tree, 20);

	traverseInOrder(tree);
	printf("\n");

	return 0;
}
