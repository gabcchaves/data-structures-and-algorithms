/* Program to create and manage binary trees with linked list. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "util.h"

typedef struct BTreeNode {
	int data;
	struct BTreeNode *left;
	struct BTreeNode *right;
} BTreeNode;

// Create binary tree
void create_btree(BTreeNode root_node) {
}

// Read integer (treated)
void read_number(ResultGeneric target) {
	char c;
	char *str_num;
	size_t str_index = -1;
	while (scanf("%c", c) && c != '\n') {
		if (!isdigit(c)) {
			target.status = 0;
		}
		str_index++;
		str_num = realloc(str_num, str_index);
		str_num[str_index] = c;
	}
	parse(str_num, target);
}

int main() {
	ResultGeneric input_number;
	read_number(input_number);
	printf("%d", input_number.status);
	if (input_number.status) {
		if (input_number.is_float) {
			float n = input_number.value_float.value;
			printf("%.2f", n);
		} else {
			int n = input_number.value_int.value;
			printf("%d", n);
		}
	} else {
		printf("Invalid number entered.\n");
	}
	return 0;
}
