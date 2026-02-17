/* this program creates and frees jobs */
#include "job.h"
#include <stdlib.h>
#include <string.h>
#include <windows.h>

job_t* create_job(int *id, int jP) {
    job_t *job = malloc(sizeof(job_t));

    // fil job info
    job->id = *id;
    if (jP == 1) {
        job->duration = 6;
        job->name = malloc(14 * sizeof(char));
        job->name = "Get groceries";
    }
    else if (jP == 2) {
        job->duration = 2;
        job->name = malloc(13 * sizeof(char));
        job->name = "Clean dishes";
    }
    else if (jP == 3) {
        job->duration = 4.5;
        job->name = malloc(12 * sizeof(char));
        job->name = "Cook dinner";
    }
    else if (jP == 4) {
        job->duration = 7;
        job->name = malloc(12 * sizeof(char));
        job->name = "Go to class";
    }
    else {
        job->duration = 7;
        job->name = malloc(12 * sizeof(char));
        job->name = "Do homework";
    }
    
    job->next = NULL;
    (*id)++;
    return job;
}

void reorder_jobs_id(job_t *j) {
    while(j) {
        j->id--;
        j = j->next;
    }
}

void free_job(job_t *j, int *id) {
    free(j->name);
    free(j);
    (*id)--;
}