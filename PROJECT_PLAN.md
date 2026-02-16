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