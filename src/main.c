
#include "queue.h"
#include "job.h"
#include "scheduler.h"
#include <stdio.h>
#include <stdlib.h>

int main () {
    int choice, data, jobPick;
    int id = 0;

    Queue *jobQueue = malloc(sizeof(Queue));
    init(jobQueue);
    

    while(1) {

        printf("\n---------MENU---------\n");
        printf("1. Add specific job\n");
        printf("2. Add random job\n");
        printf("3. Remove a job\n");
        printf("4. Run Jobs\n");
        printf("5. Exit Software\n");
        printf("----------------------\n");
        
        // get input
        printf("Please select an option: ");
        scanf("%d", &choice);
        while (getchar() != '\n');

        switch(choice) {
            case 1:
                printf("\n---------JOBS---------\n");
                printf("1. Get groceries\n");
                printf("2. Clean the dishes\n");
                printf("3. Cook dinner\n");
                printf("4. Go to class\n");
                printf("5. Do homework\n");
                printf("6. Return to menu\n");
                printf("----------------------\n");   

                do {
                    printf("Please select an option: ");
                    scanf("%d", &jobPick);
                    while (getchar() != '\n');
                } while (jobPick < 1 || jobPick > 6);
                

                printf("\n");
                if (jobPick == 6)
                    break;
                
                data = enqueue(jobQueue, &id, jobPick);
                if(data != FULL)
                    displayQueue(jobQueue);
    
                break;

            case 2:
                int randNum = 1 + rand()%5;
                data = enqueue(jobQueue, &id, randNum);
                if(data != FULL)
                    displayQueue(jobQueue);
                break;

            case 3:

                do {
                    printf("\nEnter 0 to return to menu\n");
                    printf("Select a job to remove: ");
                    scanf("%d", &jobPick);
                    while (getchar() != '\n');
                } while (jobPick < 0 || jobPick > id);

                if (jobPick == 0)
                    break;
                
                data = dequeue(jobQueue, &id, jobPick);
                if (data != EMPTY) {
                    printf("\nJob %d removed successfully\n", jobPick);
                    displayQueue(jobQueue);
                }
                break;

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