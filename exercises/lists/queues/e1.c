/* Queue exercise using array. */
#include <stdio.h>
#include <stdlib.h>

typedef struct Queue {
	unsigned front, rear, size, capacity;
	int* array;
} Queue;

Queue* initQueue(unsigned capacity) {
	Queue* queue = (Queue*) malloc(sizeof(Queue));
	queue->capacity = capacity;
	queue->front = 0;
	queue->size = 0;
	queue->rear = capacity - 1;
	queue->array = (int*) malloc(queue->capacity * sizeof(int));
	return queue;
}

char isFull(Queue* queue) {
	return (queue->size == queue->capacity);
}

char isEmpty(Queue* queue) {
	return (queue->size == 0);
}

void enqueue(Queue* queue, int item) {
	if (isFull(queue)) return;
	queue->rear = (queue->rear + 1) % queue->capacity;
	queue->array[queue->rear] = item;
	queue->size++;
}

int dequeue(Queue* queue) {
	if (isEmpty(queue)) return -1;
	int item = queue->array[queue->front];
	queue->front = (queue->front + 1) % queue->capacity;
	queue->size--;
	return item;
}

void printQueue(Queue* queue) {
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

	printQueue(queue);
	dequeue(queue);

	printQueue(queue);
	dequeue(queue);

	printQueue(queue);
	dequeue(queue);
	printQueue(queue);

	return 0;
}
