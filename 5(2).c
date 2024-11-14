#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int isEmpty(struct Node* top) {
    return (top == NULL);
}

void display(struct Node* top) {
    if (isEmpty(top)) {
        printf("Stack is empty.\n");
        return;
    }

    struct Node* current = top;
    printf("Stack elements: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void push(struct Node** top, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *top;
    *top = newNode;
    printf("%d pushed onto the stack.\n", data);
}

int pop(struct Node** top) {
    if (isEmpty(*top)) {
        printf("Stack is empty. Cannot pop.\n");
        return -1;
    }

    struct Node* temp = *top;
    int poppedValue = temp->data;
    *top = temp->next;
    free(temp);
    return poppedValue;
}

int main() {
    struct Node* top = NULL;
    int choice, element;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Check stack for empty\n");
        printf("2. Display elements\n");
        printf("3. Push\n");
        printf("4. Pop\n");
        printf("5. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (isEmpty(top)) {
                    printf("Stack is empty.\n");
                } else {
                    printf("Stack is not empty.\n");
                }
                break;

            case 2:
                display(top);
                break;

            case 3:
                printf("Enter element to push: ");
                scanf("%d", &element);
                push(&top, element);
                break;

            case 4:
                element = pop(&top);
                if (element != -1) {
                    printf("Popped element: %d\n", element);
                }
                break;

            case 5:
                printf("Quitting program.\n");
                exit(0);

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}