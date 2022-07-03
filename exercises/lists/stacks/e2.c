/* Stack practise. */
#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
	unsigned top, size, capacity;
	int* array;
} Stack;

Stack* initStack(unsigned capacity) {
	Stack* stack = (Stack*) malloc(sizeof(Stack));
	stack->capacity = capacity;
	stack->top = 0;
	stack->size = 0;
	stack->array = (int*) malloc(stack->capacity * sizeof(int));
	return stack;
}

char isFull(Stack* stack) {
	return (stack->size == stack->capacity);
}

char isEmpty(Stack* stack) {
	return (stack->size == 0);
}

void push(Stack* stack, int item) {
	if (isFull(stack)) return;
	stack->top++;
	stack->array[stack->top] = item;
	stack->size++;
}

char pop(Stack* stack) {
	if (isEmpty(stack)) return -1;
	int item = stack->array[stack->top];
	stack->top--;
	stack->size--;
	return item;
}

void printStack(Stack* stack) {
	printf("[ ");
	for (unsigned i = 0; i < stack->size; i++)
			printf("%d ", stack->array[i]);
	puts("]");
}

int main() {
	Stack* stack = initStack(3);

	printStack(stack);
	push(stack, 1);
	printStack(stack);

	push(stack, 2);
	printStack(stack);

	push(stack, 3);
	printStack(stack);

	printf("%d removido da pilha.\n", pop(stack));
	printStack(stack);

	printf("%d removido da pilha.\n", pop(stack));
	printStack(stack);

	printf("%d removido da pilha.\n", pop(stack));
	printStack(stack);

	return 0;
}
