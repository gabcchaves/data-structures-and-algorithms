/* Program to construct a binary search tree from  the preorder
 * traversal. */

// Preorder traversal: left, root, right.
#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

struct Node {
	int data;
	Node *left, *right;
};

Node* create(int preorder[], size_t preorder_length) {
	Node *root = NULL;
	Node *curr_node = NULL;
	for (size_t i = 0; i < preorder_length; i++) {
		if (curr_node == NULL) {
			root = (Node*) calloc(1, sizeof(Node));
			root->data = preorder[i];
			curr_node = root;
		} else if (preorder[i] < curr_node->data) {
			curr_node->left = (Node*) calloc(1, sizeof(Node));
			curr_node = curr_node->left;
			curr_node->data = preorder[i];
		} else {
			curr_node->right = (Node*) calloc(1, sizeof(Node));
			curr_node = curr_node->right;
			curr_node->data = preorder[i];
		}
	}
	return root;
}

void printPreOrder(Node *root) {
	if (root == NULL) return;
	printf("%d ", root->data);
	printPreOrder(root->left);
	printPreOrder(root->right);
}

void printInOrder(Node *root) {
	if (root == NULL) return;
	printInOrder(root->left);
	printf("%d ", root->data);
	printInOrder(root->right);
}

void printPostOrder(Node *root) {
	if (root == NULL) return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	printf("%d ", root->data);
}

int main() {
	int preorder[] = {10, 5, 1, 7, 40, 50};
	int preorder_length = sizeof(preorder) / sizeof(preorder[0]);
	Node *root = create(preorder, preorder_length);

	printf("Pre-order traversal:\t");
	printPreOrder(root);
	printf("\n");

	printf("In-order traversal:\t");
	printInOrder(root);
	printf("\n");

	printf("Post-order traversal:\t");
	printPostOrder(root);
	printf("\n");

	return 0;
}
