
#include "queue.h"
#include "job.h"
#include "scheduler.h"
#include <stdio.h>

int main () {
    int choice, jobPick = 0;
    int id = 0;

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
                printf("---------JOBS---------\n");
                printf("1. Get groceries\n");
                printf("2. Clean the dishes\n");
                printf("3. Cook dinner\n");
                printf("4. Go to class\n");
                printf("5. Do homework");
                printf("----------------------\n");   

                do {
                    printf("Please select an option: ");
                    scanf("%d", &jobPick);
                } while (jobPick < 1 || jobPick > 5);

                create_job(&id, jobPick);
        }
    }
}