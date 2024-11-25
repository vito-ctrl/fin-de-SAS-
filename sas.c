#include <stdio.h>
#include <string.h>

struct details {
    char title[100];
    char description[100];
    char date[11];
    int priority;
};

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