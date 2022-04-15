#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char name[20];
    char usn[10];
    int marks;
    struct node* link;
};

typedef struct node NODE;

NODE* start = NULL;

NODE* createNode() {
    NODE* newNode = (NODE*) malloc(sizeof(NODE));
    return newNode;
}

NODE* getData() {
    NODE* temp = createNode();

    printf("Enter the name:\n");
    scanf("%s", temp -> name);

    printf("Enter the USN:\n");
    scanf("%s", temp -> usn);

    printf("Enter the marks:\n");
    scanf("%d", &temp -> marks);

    return temp;
}

void create() {
    int numberOfNodes = 0 ;
    printf("Enter the number of nodes: ");
    scanf("%d", &numberOfNodes);

    for (int i = 0; i < numberOfNodes; i++) {
        printf("\nEntry %d\n", i + 1);
        insertRear();
    }

    return ;
}

void insertRear()
{
    NODE* newNode;
    newNode = getData();

    if (start == NULL) {
        start = newNode;
        newNode -> link = NULL;
    }
    else {
        NODE* temp = start;

        while(temp -> link != NULL) {
            temp = temp -> link;
        }

        temp -> link = newNode;
        newNode -> link = NULL;
    }

    return;
}

void insertFront() {
    NODE* newNode;
    newNode = getData();

    newNode -> link = start;
    start = newNode;
}

void deleteRear() {
    if (start == NULL) {
        printf("\n-> The list is empty.\n");
    }
    else if(start -> link == NULL) {
        free(start);
        start = NULL;
    }
    else {
        NODE* temp = start;
        NODE* prev = start;

        while (temp -> link != NULL) {
            prev = temp;
            temp = temp -> link;
        }

        prev -> link = NULL;
        free(temp);
    }
}

void deleteFront()
{
    NODE* temp = start;
    start = start -> link;
    free(temp);
}


void display()
{
    if (start == NULL) {
        printf("\n-> List is empty.\n");
    }
    else {
        int n = 1;
        NODE* temp = start;

        printf("\n-> The list status is:\n");

        while (temp != NULL) {
            printf("\n--Entry %d--\n", n++);

            printf("Name: %s\n", temp -> name);
            printf("USN: %s\n", temp -> usn);
            printf("Marks: %d\n\n", temp -> marks);

            temp = temp -> link;
        }
    }
}

void stack() {
    int ch = 0;

    while(1) {
        printf("\n- - - STACK OPERATIONS - - -\n");
        printf("1. Push an element\n");
        printf("2. Pop an element\n");
        printf("3. Display\n");
        printf("4. Back to main menu\n");

        printf("\n-> Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1: insertFront(); break;

            case 2: deleteFront(); break;

            case 3: display(); break;

            case 4: return;

            default: printf("\nEnter a valid option.\n");
        }
    }

    return;
}

void queue() {
    int ch = 0;

    while(1) {
        printf("\n- - - QUEUE OPERATIONS - - -\n");
        printf("1. Add an element\n");
        printf("2. Delete an element\n");
        printf("3. Display\n");
        printf("4. Back to main menu\n");

        printf("\n-> Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1: insertRear(); break;

            case 2: deleteFront(); break;

            case 3: display(); break;

            case 4: return;

            default: printf("\nEnter a valid option.\n");
        }
    }

    return;
}


void menu()
{
    int choice = 0;

    while(1) {
        printf("\n- - - MAIN MENU - - -\n");
        printf("1. Create Singly Linked List\n");
        printf("2. Stack operation\n");
        printf("3. Queue Operation\n");
        printf("4. Delete from rear\n");
        printf("5. Display\n");
        printf("6. Exit\n");

        printf("\n-> Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: create(); break;

            case 2: stack(); break;

            case 3: queue(); break;

            case 4: deleteRear(); break;

            case 5: display(start); break;

            case 6: return;

            default: printf("\nEnter a valid choice.\n");


        }
    }

    return;
}



int main () {
    menu();
    printf("\nDONE\n");
    return 0;
}
