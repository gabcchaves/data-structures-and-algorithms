/* Implementação de pilha. */
#include <stdio.h>
#include <stdlib.h>

/* Estrutura para representar uma pilha. */
typedef struct Stack {
	unsigned top, size, capacity;
	int* array;
} Stack;

// Inicializar pilha
Stack* initStack(unsigned capacity) {
	Stack* stack = (Stack*) malloc(sizeof(Stack));
	stack->capacity = capacity;
	stack->top = stack->size = 0;
	stack->array = (int*) malloc(stack->capacity * sizeof(int));
	return stack;
}

// Verificar se pilha está cheia
char isFull(Stack* stack) {
	return (stack->size == stack->capacity);
}

// Verificar se pilha está vazia
char isEmpty(Stack* stack) {
	return (stack->size == 0);
}

// Adicionar item à pilha
void push(Stack* stack, int item) {
	if (isFull(stack)) return;
	stack->top++;
	stack->array[stack->top] = item;
	stack->size++;
}

// Remover último item da pilha
int pop(Stack* stack) {
	if (isEmpty(stack)) return -1;
	int item = stack->array[stack->top];
	stack->top--;
	stack->size--;
	return item;
}

// Imprimir pilha inteira
void printStack(Stack* stack) {
	printf("[ ");
	for (unsigned i = 0; i < stack->size; i++)
		printf("%d ", stack->array[i]);
	puts("]");
}

// Controlador
int main() {
	Stack* stack = initStack(3);
	
	printStack(stack);
	push(stack, 10);
	printStack(stack);

	push(stack, 20);
	printStack(stack);

	push(stack, 30);
	printStack(stack);

	pop(stack);
	printStack(stack);

	pop(stack);
	printStack(stack);
	pop(stack);
	printStack(stack);

	return 0;
}
