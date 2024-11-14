#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int cqueue_arr[MAX];
int front = -1;
int rear = -1;
void enqueue(int item)
{
    if (isFull())
    {
        printf("\nQueue Overflow\n");
        return;
    }
    if (front == -1)
        front = 0;

    if (rear == MAX - 1)
        rear = 0;
    else
        rear = rear + 1;
    cqueue_arr[rear] = item;
}
int dequeue()
{
    int item;
    if (isEmpty())
    {
        printf("\nQueue Underflow\n");
        exit(1);
    }
    item = cqueue_arr[front];
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else if (front == MAX - 1)
        front = 0;
    else
        front = front + 1;
    return item;
}
int isEmpty()
{
    if (front == -1)
        return 1;
    else
        return 0;
}
int isFull()
{
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1))
        return 1;
    else
        return 0;
}
int peek()
{
    if (isEmpty())
    {
        printf("\nQueue Underflow\n");
        exit(1);
    }
    return cqueue_arr[front];
}
void display()
{
    int i;
    if (isEmpty())
    {
        printf("\nQueue is empty\n");
        return;
    }
    printf("\nQueue elements :\n");
    i = front;
    if (front <= rear)
    {
        while (i <= rear)
            printf("%d ", cqueue_arr[i++]);
    }
    else
    {
        while (i <= MAX - 1)
            printf("%d ", cqueue_arr[i++]);
        i = 0;
        while (i <= rear)
            printf("%d ", cqueue_arr[i++]);
    }
    printf("\n");
}
int main()
{
    int choice, item;
    printf("\n1.Enqueue\n");
    printf("2.Dequeue\n");
    printf("3.Peek\n");
    printf("4.Display\n");
    printf("5.Empty\n");
    printf("6.Full\n");
    printf("7.Quit\n");
    while (1)
    {
        printf("\nEnter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nInput the element for insertion : ");
            scanf("%d", &item);
            enqueue(item);
            break;
        case 2:
            printf("\nElement deleted is : %d\n", dequeue());
            break;
        case 3:
            printf("\nElement at the front is  : %d\n", peek());
            break;
        case 4:
            display();
            break;
        case 5:
            if (isEmpty())
                printf("\nQueue is Empty.\n");
            else
                printf("\nQueue is not empty.\n");
            break;
        case 6:
            if (isFull())
                printf("\nQueue is Full.\n");
            else
                printf("\nQueue is not full.\n");
            break;
        case 7:
            exit(1);
        default:
            printf("\nInvalid choice\n");
        }
    }
}