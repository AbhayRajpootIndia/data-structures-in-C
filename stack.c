#include <stdio.h>
#include <stdlib.h>

#define max 100

int stack[max];

int top = -1;

void push(int element) {
    if (top < max)
        stack[++top] = element;

    return;
}

int pop() {
    if (top > -1)
        return stack[top--];

    return NULL;
}

void newElement() {
    if (top < max) {
        int element = 0;
        printf("Enter the element to push: ");
        scanf("%d", &element);

        push(element);

        printf("\n-> %d pushed to the stack.\n", element);
    }
    else {
        printf("\n-> Stack full.\n");
    }

    return;
}

void deleteElement() {
    if (top > -1)
        printf("\n-> Element deleted: %d\n", pop());
    else
        printf("\n-> Stack is empty.\n");

    return;
}

void display() {
    if (top < 0) {
        printf("\n-> Stack is empty.\n");
    }
    else {
        printf("\n-> Current Stack Status: \n\n");
        for (int i = top; i >= 0; i--) {
            printf("   | %d |\n", stack[i]);
        }
    }
}

void pallindrome() {
    if (top < 1) {
        printf("\n-> Pallindrome can't be checked.\n");
    }
    int rev_stack[100];
    int size = 0;

    for (int i = top; i >= 0; i--) {
        rev_stack[size++] = stack[i];
    }

    for (int i = 0; i < top; i++) {
        if (rev_stack[i] != stack[i]) {
            printf("\n-> Stack is not a pallindrome.\n");
            return;
        }
    }

    printf("\n-> Stack is a pallindrome.\n");
    return;
}

void menu() {
    int choice = 0;

    while (1) {
        printf("\n--- MENU ---\n");
        printf("1. PUSH\n");
        printf("2. POP\n");
        printf("3. CHECK PALLINDROME\n");
        printf("4. DISPLAY\n");
        printf("5. EXIT\n");

        printf("-> Enter your choice: \n");
        scanf("%d", &choice);

        switch (choice) {
            case 1: newElement(); break;

            case 2: deleteElement(); break;

            case 3: pallindrome(); break;

            case 4: display(); break;

            case 5: return;

            default: printf("\n-> Enter a valid choice.\n");
        }
    }

    return;

}

int main() {
    menu();
    return 0;
}





