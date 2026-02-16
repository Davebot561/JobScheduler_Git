
#include "job.h"
#include <stdlib.h>
#include <string.h>

job_t* create_job(int id, int duration, char *name) {
    job_t *job = malloc(sizeof(job_t));

    // fil job info
    job->id = id;
    job->duration = duration;
    job->name = malloc((strlen(name) + 1) * sizeof(char));
    strcpy(job->name, name);
    job->next = NULL;

    return job;
}

void free_job(job_t *job) {
    free(job->name);
    free(job);
}