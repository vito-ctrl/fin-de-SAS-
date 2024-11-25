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
    int option;
    
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
}