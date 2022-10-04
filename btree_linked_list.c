/* Program to create and manage binary trees with linked list. */

#include <stdio.h>

typedef struct BTreeNode {
	int data;
	struct BTreeNode *left;
	struct BTreeNode *right;
} BTreeNode;

int main() {
	BTreeNode node0;
	BTreeNode node1;
	BTreeNode node2;

	node0.data = 10;
	node1.data = 20;
	node2.data = 30;

	node0.left = &node1;
	node0.right = &node2;

	printf("\t[%d]\n[%d]\t\t[%d]\n", node0.data, node0.left->data, node0.right->data);
	return 0;
}
