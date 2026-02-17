#ifndef QUEUE_H
#define QUEUE_H

#define EMPTY -1

typedef struct queue {
    job_t *front;
    job_t *back;
    int capacity;
} Queue;

void init(Queue *qPtr);
int enqueue(Queue *qPtr, int *id, int jP);
int dequeue(Queue *qPtr, int pos, int *id);
void displayQueue(Queue *qPtr);
int empty(Queue *qPtr);



#endif // QUEUE.H