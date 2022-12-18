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
short getBalancingFactor(Node*);
Node* searchMinNode(Node*);
Node* searchMaxNode(Node*);
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

short getBalancingFactor(Node *t) {
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

Node* rotate(Node *t) {
	Node *tmp = NULL;

	if (t->balancing_factor < -1) {
		if (t->left->right != NULL) {
			t->left->right->right = t;
			t->left->right->left = t->left;
		} else {
		}
	} else {
		if (t->balancing_factor > 1) {
			
		}
	}
}

Node* insert(Node *t, unsigned int key) {
	if (t == NULL) {
		t = (Node*) calloc(1, sizeof(Node));
		t->key = key;
		t->left = NULL;
		t->right = NULL;
	} else {
		if (t->key != key) {
			t = insert( (t->key > key ? t->left : t->right) , key);
			t->balancing_factor = getBalancingFactor(t);
			if (t->balancing_factor > 1 || t->balancing_factor < -1) {
				t = rotate(t);
			}
		}
	}

	return t;
}

int main() {
	return 0;
}
