/* Implementação de uma fila com vetor. */
#include <stdio.h>
#include <stdlib.h>

// Estrutura que representa a fila
typedef struct Queue {
	unsigned front, rear, size;
	unsigned capacity;
	int *array;
} Queue;

// Inicializa a fila
Queue* initQueue(unsigned capacity) {
	Queue* queue = (Queue*) malloc(sizeof(Queue));
	queue->capacity = capacity;
	queue->front = queue->size = 0;
	queue->rear = capacity - 1;
	queue->array = (int*) malloc(queue->capacity * sizeof(int));
	return queue;
}

// Verifica se a fila está cheia
char isFull(Queue* queue) {
	return (queue->size == queue->capacity);
}

// Verifica se a fila está vazia
char isEmpty(Queue *queue) {
	return (queue->size == 0);
}

// Adicionar item à fila
void enqueue(Queue *queue, int item) {
	if (isFull(queue)) return;

	queue->rear = (queue->rear + 1) % queue->capacity;
	queue->array[queue->rear] = item;
	queue->size = queue->size + 1;
}

// Remover item da fila
int dequeue(Queue *queue) {
	if (isEmpty(queue)) return -1;

	int item = queue->array[queue->front];
	queue->front = (queue->front + 1) % queue->capacity;
	queue->size = queue->size - 1;
	return item;
}

// Imprimir fila
void printQueue(Queue *queue) {
	printf("[ ");
	for (unsigned i = 0; i < queue->size; i++)
		printf("%d ", queue->array[i]);
	puts("]");
}

int main() {
	Queue* queue = initQueue(7);

	printQueue(queue);
	enqueue(queue, 10);

	printQueue(queue);
	enqueue(queue, 20);

	printQueue(queue);
	enqueue(queue, 30);

	printQueue(queue);
	enqueue(queue, 40);

	printQueue(queue);
	dequeue(queue);

	printQueue(queue);
	dequeue(queue);

	printQueue(queue);
	dequeue(queue);

	printQueue(queue);
	dequeue(queue);

	printQueue(queue);
	dequeue(queue);

	return 0;
}
