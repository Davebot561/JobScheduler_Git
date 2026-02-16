Job Scheduler Project — Complete Overview
1️⃣ Project Goal

Simulate a small bounded job scheduler in C that uses queues, linked lists, recursion, and dynamic memory — a mini-system-level challenge.

2️⃣ Features
Core Features (Phase 1)

Linked-list-backed queue

enqueue(job*)

dequeue()

bounded capacity

Recursive free_all_jobs

Memory-safe dynamic allocation for jobs

Job struct:

typedef struct job {
    int id;
    int duration;
    struct job *next;
} job_t;

Advanced Features (Phase 2)

Circular queue (array-based) option

Priority jobs

Job cancellation

Basic stats: average wait time, max depth

Optional Stretch (Phase 3)

Thread-safe queue with pthread_mutex

Deterministic behavior for defense-system-style code

Zero memory leaks (valgrind clean)

3️⃣ Project Structure
job-scheduler/
├── src/
│   ├── job.c          # job struct & helpers
│   ├── queue.c        # queue implementation
│   ├── scheduler.c    # scheduling logic
│   └── main.c         # test / CLI interface
├── include/
│   ├── job.h
│   ├── queue.h
│   └── scheduler.h
├── tests/             # optional test files
├── Makefile
└── README.md

4️⃣ Git Strategy

Initialize repo locally (git init)

Commit small logical units:

init project structure

add job struct

implement enqueue

implement dequeue

add recursive free

Use branches for features/experiments:

feature/recursive-free

feature/circular-queue

Push to GitHub for access anywhere.

job.c/.h 
- Defines a job struct and functions to create/free jobs

queue.c/.h
- Implements the queue (linked list or circular array) that holds jobs

scheduler.c/.h
- Logic that manages the flow: enqueue jobs, pick jobs to process, optionally compute stats

main.c
- Entry point: sets up the scheduler, creates jobs, runs them, tests functionality

What a Job Scheduler Is

A job scheduler is a system that manages a list (queue) of jobs/tasks and decides when and in what order they are executed.

Job → a unit of work, e.g., “process data for 5 seconds”

Queue → where jobs wait until they are executed

Scheduler → the logic that picks which job to run next and handles completion

High-level flow

1. Jobs arrive

- New jobs are created (think create_job(id, duration)).

2. Jobs wait in a queue

- If there’s space in the queue, the job is added (enqueue)

- If the queue is full, the job is rejected or retried later

3. Scheduler processes jobs

- Takes jobs from the front of the queue (dequeue)

- Simulates doing the work (duration, etc.)

- Frees memory after completion

4. Statistics / monitoring (optional)

- Track average wait time, max queue depth, total jobs processed