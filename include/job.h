#ifndef JOB_H
#define JOB_H

typedef struct job {
    int id;
    int duration;
    char *name;
    struct job *next;
} job_t;

// Allocate a new job
job_t* create_job(int id, int duration);

// Free a single job
void free_job(job_t *job);

#endif // JOB_H