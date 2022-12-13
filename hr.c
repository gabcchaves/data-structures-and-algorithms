/* Human resources system. This is a college task solution sketch. It is
 * supposed to allow employee insertion, parameterized search, and removal. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Employee Employee;		// Type to store an employee data.
typedef struct BTNode BTNode;			// Binary tree node.
typedef struct ListNode ListNode;		// Doubly linked list node.
typedef struct List List;				// Doubly linked list wrapper.

struct Employee {
	int id;
	char *name;
	char *profession;
};

struct BTNode {
	Employee *data;
	BTNode *left;
	BTNode *right;
};

struct ListNode {
	Employee data;
	ListNode *next;
	ListNode *previous;
};

struct List {
	ListNode *first;
	ListNode *last;
};

void freeList(List);
Employee newEmployee(int, char*, char*);
void insertEmployee(Employee, List);
void refById(Employee*, BTNode*);
void refByName(Employee*, BTNode*);
Employee fetchById(int, BTNode*);
Employee fetchByName(char*, BTNode*);

void freeList(List list) {
	ListNode *first = list.first;
	while (first != NULL) {
		ListNode *tmp = first;
		first = first->next;
		free(tmp);
	}
}

Employee newEmployee(int id, char *name, char *profession) {
	Employee employee = { id, name, profession };
	return employee;
}

void insertEmployee(Employee employee, List employee_list) {
	if (employee_list.first == NULL) {
		employee_list.first->data = employee;
		employee_list.last->data = employee;
	} else {
		employee_list.last->next = (ListNode*) calloc(1, sizeof(ListNode));
		employee_list.last = employee_list.last->next;
		employee_list.last->next = NULL;
		employee_list.last->data = employee;
	}
}

// Reference the employee from the binary search tree to the employee storage
// structure.
void refById(Employee *employee, BTNode *root) {
	if (root == NULL) {
		root = (BTNode*) calloc(1, sizeof(BTNode));
		root->data = employee;
		root->left = NULL;
		root->right = NULL;
	} else {
		if (employee->id < root->data->id) {
			if (root->left != NULL) {
				refById(employee, root->left);
			} else {
				root->left = (BTNode*) calloc(1, sizeof(BTNode));
				root->data = employee;
				root->left->left = NULL;
				root->left->right = NULL;
			}

		} else if (employee->id > root->data->id) {
			if (root->right != NULL) {
				refById(employee, root->right);
			} else {
				root->right = (BTNode*) calloc(1, sizeof(BTNode));
				root->data = employee;
				root->right->left = NULL;
				root->right->right = NULL;
			}
		}
	}
}

void refByName(Employee *employee, BTNode *root) {
	if (root == NULL) {
		root = (BTNode*) calloc(1, sizeof(BTNode));
		root->data = employee;
		root->left = NULL;
		root->right = NULL;
	} else {
		if (strcmp(employee->name, root->data->name) < 0) {
			refByName(employee, root->left);
		} else if (strcmp(employee->name, root->data->name) > 0) {
			refByName(employee, root->right);
		}
	}
}

Employee fetchById(int id, BTNode *root) {
	if (root != NULL) {
		if (id < root->data->id) {
			fetchById(id, root->left);
		} else if (id > root->data->id) {
			fetchById(id, root->right);
		}

		return *(root->data);
	}
}

int main() {
	List employee_list;
	BTNode *bst_id;

	insertEmployee(newEmployee(1, "Teste", "Teste"), employee_list);
	//refById(&employee_list.last->data, bst_id);

	//freeList(employee_list);

	return 0;
}
