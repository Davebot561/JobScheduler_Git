/* This program queues and deques jobs */
#include "job.h"
#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

// initializes queue
void init(Queue *qPtr) {
    qPtr->front = NULL;
    qPtr->back = NULL;
    qPtr->capacity = 10;
}

// adds job to queue
int enqueue(Queue *qPtr, int *id, int jP) {

    // check if Queue is full
    if (*id == qPtr->capacity) {
        printf("The queue is full.\n");
        return FULL;
    }
    
    job_t *tmpPtr = create_job(id, jP);
    // check if Queue is empty
    if (empty(qPtr)) {
        qPtr->front = tmpPtr;
        qPtr->back = tmpPtr;
        return 1;
    }
    
    else { // creates job and adds to the back
        qPtr->back->next = tmpPtr;
        qPtr->back = tmpPtr;
        return 1;
    }
}

// removes jobs from queue
int dequeue(Queue *qPtr, int *id, int pos) {
    if (empty(qPtr))
        return EMPTY;
    
    job_t *tmpPtr;
    job_t *t = qPtr->front;

    if (qPtr->front->id == pos-1) {
        tmpPtr = qPtr->front;
        qPtr->front = qPtr->front->next;
        t = qPtr->front;
        if (t)
            t->id--;
        free_job(tmpPtr, id);
    }
    else {
        for (int i = 0; i < *id; i++) {
            if (t->next->id == pos-1) {
            tmpPtr = t->next;
            t->next = t->next->next; 
            free_job(tmpPtr, id);
            break;
            }
            t = t->next;
        }
    }
    
    if (empty(qPtr)) {
        qPtr->back = NULL;
        return 1;
    }
    else {
        reorder_jobs_id(t->next);
        return 1;
    }
}

// returns true if empty
int empty(Queue *qPtr) {
    return qPtr->front == NULL;
}

// displays queue
void displayQueue(Queue *qPtr) {
    printf("\n");
    if(empty(qPtr)) {
        printf("Queue is empty\n");
        return;
    }

    job_t *t = qPtr->front;
    while(t) {
        printf("Job %d: %s\n", t->id + 1, t->name);
        t = t->next;
    }
}