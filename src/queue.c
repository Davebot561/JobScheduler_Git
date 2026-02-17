/* This program queues and deques jobs */
#include "job.h"
#include "queue.h"
#include <stdio.h>

// initializes queue
void init(Queue *qPtr) {
    qPtr->front = NULL;
    qPtr->back = NULL;
    qPtr->capacity = 10;
}

// adds job to queue
int enqueue(Queue *qPtr, int *id, int jP) {

    // check if Queue is empty
    if (empty(qPtr)) {
        job_t *jPtr = create_job(&id, jP);
        qPtr->front = jPtr; 
    }
    
    // check if Queue is full
    if (id == qPtr->capacity) {
        printf("The queue is full.\n");
        return 1;
    }

    // creates job and adds to the back
    job_t *tmpPtr = create_job(&id, jP);
    qPtr->back->next = tmpPtr;
    qPtr->back = tmpPtr;
    return 1;
}

// removes jobs from queue
int dequeue(Queue *qPtr, int pos, int *id) {
    if (empty(qPtr))
        return EMPTY;

    job_t *tmpPtr;

    for (int i = 0; i < *id; i++) {
        if (qPtr->front->next->id == pos) {
            tmpPtr = qPtr->front->next;
            qPtr->front->next = qPtr->front->next->next;
            free_job(tmpPtr, &id);
            reorder_jobs_id(qPtr->front->next);
            return 1;
        }
        qPtr->front = qPtr->front->next;
    }
}

// returns true if empty
int empty(Queue *qPtr) {
    return qPtr->front == NULL;
}

// displays queue
void displayQueue(Queue *qPtr) {
    while(qPtr) {
        printf("Job %d: %s\n", qPtr->front->id + 1, qPtr->front->name);
        qPtr->front = qPtr->front->next;
    }
}