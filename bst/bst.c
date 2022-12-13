#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

struct Node {
	unsigned int key;
	Node *left;
	Node *right;
};

void insert(unsigned int key, Node **root) {
	if ((*root) == NULL) {
		(*root) = (Node*) calloc(1, sizeof(Node));
		(*root)->key = key;
		(*root)->left = NULL;
		(*root)->right = NULL;
	} else {
		if (key < (*root)->key) {
			if ((*root)->left == NULL) {
				(*root)->left = (Node*) calloc(1, sizeof(Node));
				(*root)->left->key = key;
				(*root)->left->left = NULL;
				(*root)->left->right = NULL;
			} else {
				insert(key, &((*root)->left));
			}
		} else if (key > (*root)->key) {
			if ((*root)->right == NULL) {
				(*root)->right = (Node*) calloc(1, sizeof(Node));
				(*root)->right->key = key;
				(*root)->right->left = NULL;
				(*root)->right->right = NULL;
			} else {
				insert(key, &((*root)->right));
			}
		}
	}
}

int search(unsigned int key, Node *root) {
	int ret = -1;

	if (root != NULL) {
		if (key < root->key) {
			ret = search(key, root->left);
		} else if (key > root->key) {
			ret = search(key, root->right);
		} else {
			ret = root->key;
		}
	}

	return ret;
}

char delete(unsigned int key, Node **root) {
	if ((*root) == NULL) return -1;

	// Find target.
	if (key < (*root)->key) {
		delete(key, (*root)->left);
	} else if (key > (*root)->key) {
		delete(key, (*root)->right);
	} else {
		if ((*root)->left != NULL && (*root)->right == NULL) {
			(*root) = (*root)->left;
		} else if ((*root)->left == NULL && (*root)->right != NULL) {
			(*root) = (*root)->right;
		} else if ((*root)->left != NULL && (*root)->right != NULL) {
			Node *curr = (*root);
			while (*root != NUll) {
				if (curr->left != NULL && curr->left && NULL)
					curr = curr->left;
			}
			(*root) = curr->left;
			curr->left = NULL;
		} else {
		}
	}
}

int main() {
	Node *root = NULL;

	insert(10, &root);
	insert(20, &root);

	printf("%d\n", search(10, root));
	printf("%d\n", search(20, root));

	delete(10, &root);
	printf("%d", search(10, root));

	return 0;
}
