#include <stdio.h>
#include <stdlib.h>

#define max 100

int array[max];

int size = 0;

void createArray() {
    printf("Enter number of elements: \n");
    scanf("%d", &size);

    printf("\nEnter the elements of array: \n");

    for (int i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }

    printf("\nArray of size %d created.\n", size);

    return;
}

void display() {
    printf("\nArray size - %d\n", size);

    printf("\n=> {");
    for (int i = 0; i < size; i++) {
        printf(" %d,", array[i]);
    }
    printf(" }\n");

    return;
}


void insertElement() {
    if (size == max) {
        printf("Array is full.\n");
        return;
    }

    int pos = 0;
    printf("Enter the position to insert the new element: ");
    scanf("%d", &pos);

    if (pos < 1 || pos > size + 1) {
        printf("Enter a valid position.\n");
        return;
    }

    int newElement = 0;
    printf("Enter the element to insert: ");
    scanf("%d", &newElement);

    for (int i = size; i > pos - 1; i--) {
        array[i] = array[i - 1];
    }

    array[pos - 1] = newElement;
    size++;

    printf("\nOne element added.\n");

    display();
    return;

}

void deleteElement() {
    if (size < 1) {
        printf("Array is empty.\n");
        return;
    }

    int pos = 0;
    printf("Enter the position of element to delete: ");
    scanf("%d", &pos);

    if (pos < 1 || pos > size) {
        printf("Enter a valid position.\n");
        return;
    }

    for (int i = pos - 1; i < size; i++) {
        array[i] = array[i + 1];
    }

    size--;
    printf("\n1 element deleted.\n");

    display();

    return;
}

void menu() {
    while (1) {
        printf("\n--- ARRAY METHODS ---\n");
        printf("1. Create\n");
        printf("2. Display\n");
        printf("3. Insert an element\n");
        printf("4. Delete an element\n");
        printf("5. EXIT\n");

        int choice = 0;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: createArray(); break;

            case 2: display(); break;

            case 3: insertElement(); break;

            case 4: deleteElement(); break;

            case 5: return;

            default: printf("Please enter a valid choice.\n");

        }
    }
}

int main() {
    menu();
    return 0;
}
