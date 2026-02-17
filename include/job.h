#ifndef JOB_H
#define JOB_H

typedef struct job {
    int id;
    float duration;
    char *name;
    struct job *next;
} job_t;

// Allocate a new job
job_t* create_job(int *id, int jP);

// Free a single job
void free_job(job_t *j, int *id);
void reorder_jobs_id(job_t *j);

#endif // JOB_H