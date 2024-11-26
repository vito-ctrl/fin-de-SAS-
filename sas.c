#include <stdio.h>
#include <string.h>

struct details {
    char title[100];
    char description[100];
    char date[11];
    int priority;
};

int addTask(struct details tasks[], int tk) {
    int day, month, year;
    printf("\n<<<<<<<<<<<<<<add task>>>>>>>>>>>>>>>\n");
    printf("\nTask title: ");
    scanf(" %[^\n]", tasks[tk].title);
    printf("\nTask description: ");
    scanf(" %[^\n]", tasks[tk].description);

    while (1) {
        printf("\nTask date in this format (MM-DD-YYYY): ");
        scanf("%d-%d-%d", &month, &day, &year);
        if (verify_day(day, month, year)) {
            sprintf(tasks[tk].date, "%02d-%02d-%04d", month, day, year);
            break;
        } else {
            printf("Invalid date. Please enter a valid date in MM-DD-YYYY format.\n");
        }
    }

    printf("\nTask priority (1 for high, 0 for low): ");
    scanf("%d", &tasks[tk].priority);
    if (tasks[tk].priority != 1 && tasks[tk].priority != 0) {
        printf("Invalid number. Please enter a valid number.\n");
    }

    printf("\n<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>\n");
    return tk + 1;
}
void viewTasks(struct details tasks[], int taskCount) { 
    printf("\n<<<<<<<<<<<<<<view tasks>>>>>>>>>>>>>>>\n"); 
    for (int i = 0; i < taskCount; i++) { 
        printf("Task %d:\n", i + 1); 
        printf("Title: %s\n", tasks[i].title); 
        printf("Description: %s\n", tasks[i].description); 
        printf("Date: %s\n", tasks[i].date); 
        printf("Priority: %s\n", tasks[i].priority ? "High" : "Low"); 
        printf("\n"); 
        }
}

int main() {
    struct details tasks[100];
    int tk = 0;
    int capacity = 2;
    int quit = 1;
    int option;

    while (quit == 1) {
    printf("\n<<<<<<<<<<<<<<<<menu>>>>>>>>>>>>>>>>>>>\n");
        printf("\n1 .    add a task      . \n");
        printf("2 .  view all tasks    . \n");
        printf("3 .    edit a task     . \n");
        printf("4 .   delete a task    . \n");
        printf("5 . filter by Priority . \n");
        printf("6 .       Quit         . \n");
        printf("\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
        printf("Enter an number option from 1 to 6: ");
        scanf("%d", &option);
        printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");

        if (option >= 1 && option <= 6) {
            switch (option) {
                case 1:
                    tk = addTask(tasks, tk);
                    break;
                case 2:
                    viewTasks(tasks, tk);
                    break;
                case 3:
                    editTask(tasks, tk);
                    break;
                case 4:
                    tk = deleteTask(tasks, tk);
                    break;
                case 5:
                    int priority;
                    printf("Enter priority to filter by (1 for high, 0 for low): ");
                    scanf("%d", &priority);
                    filterByPriority(tasks, tk, priority);
                    break;
                case 6:
                    quit = 0; // Exit the loop and terminate the program
                    break;
                }
        } else {
            printf("Invalid option. Please enter a number between 1 and 6.\n");
        }
    }

    return 0;
}