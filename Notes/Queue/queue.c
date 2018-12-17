#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// 2018-08-01

typedef int DATATYPE;
typedef struct queue {
	size_t size;
	int front;
	int rear;
	DATATYPE* data;
} Queue;

Queue* q_create(size_t size) {
	Queue* q = malloc(sizeof(Queue));
	q->front = q->rear = 0;
	q->size = size;
	q->data = malloc(size * sizeof(DATATYPE));
	return q;
}
void q_destroy(Queue* q) {
	if (q) {
		if (q->data) free(q->data);
		free(q);
	}
}
void q_enqueue(Queue* q, DATATYPE val) {
  q->data[q->front] = val;
	q->front = (q->front + 1) % q->size;
}
DATATYPE q_dequeue(Queue* q) {
	DATATYPE val = q->data[q->rear];
	q->rear = (q->rear + 1) % q->size;
	return val;
}
bool q_empty(Queue* q) {
  return q->front == q->rear;
}
bool q_full(Queue* q) {
	return (q->front + 1) % q->size == q->rear;
}
size_t q_size(Queue* q) {
	return (q->front - q->rear + q->size) % q->size;
}

int main() {
	srand(time(NULL));
	Queue* q = q_create(10);

	int t = rand() % 15 + 1;
	while (t--) {
		int r = rand() % 100;
		if (rand() % 3 == 1 && !q_full(q)) {
			q_enqueue(q, r);
		  printf("enqueue %d\n", r);
		}	else if (!q_empty(q))
		  printf("dequeue %d\n", q_dequeue(q));
	}
}