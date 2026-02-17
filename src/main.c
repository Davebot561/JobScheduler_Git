
#include "queue.h"
#include "job.h"
#include "scheduler.h"
#include <stdio.h>

int main () {
    int choice, data;
    int id = 0;

    Queue *jobQueue;
    init(jobQueue);
    

    while(1) {

        printf("---------MENU---------\n");
        printf("1. Add specific job\n");
        printf("2. Add random job\n");
        printf("3. Remove a job\n");
        printf("4. Run Jobs\n");
        printf("5. Exit Software\n");
        printf("----------------------\n");
        
        // get input
        printf("Please select an option: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                int jobPick;
                printf("---------JOBS---------\n");
                printf("1. Get groceries\n");
                printf("2. Clean the dishes\n");
                printf("3. Cook dinner\n");
                printf("4. Go to class\n");
                printf("5. Do homework");
                printf("6. Return to menu");
                printf("----------------------\n");   

                do {
                    printf("Please select an option: ");
                    scanf("%d", &jobPick);
                } while (jobPick < 1 || jobPick > 6);

                if (jobPick == 6)
                    break;
                
                data = enqueue(jobQueue, &id, jobPick);
                if(data != FULL)
                    displayQueue(jobQueue);
                break;

            case 2:
                int randNum = 1 + rand()%5;
                enqueue(jobQueue, &id, randNum);
                displayQueue(jobQueue);
                break;

            case 3:
                int jobPick;

                do {
                    printf("Enter 0 to return to menu\n");
                    printf("Select a job to remove: ");
                    scanf("%d", &jobPick);
                } while (jobPick >= 0 || jobPick <= id+1); 

                if (jobPick == 0)
                    break;

                data = dequeue(jobQueue, &id, jobPick);
                if (data != EMPTY) {
                    printf("Job %d removed successfully", jobPick);
                    displayQueue(jobQueue);
                }
            case 4:
                printf("Work in progress\n");
                break;
            case 5:
                exit(1);
            default:
                printf("Invalid input\n");
                
        }
    }
    return 0;
}