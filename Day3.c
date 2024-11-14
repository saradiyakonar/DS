#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    int key;
    struct node *next;
};
struct node *head = NULL;
struct node *ptr;
void isEmpty()
{
    if (head == NULL)
    {
        printf("The linked list is empty: \n");
    }
    else
    {
        printf("Linked list is not empty: \n");
    }
}
void insert_begin(int value)
{
    struct node *temp;
    int key;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter the key: ");
    scanf("%d", &key);
    temp->key = key;
    temp->data = value;
    temp->next = NULL;
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        temp->next = head;
        head = temp;
    }
}
void insert_end(int value)
{
    struct node *temp;
    int key;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = value;
    printf("Enter the key: ");
    scanf("%d", &key);
    temp->key = key;
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        ptr = head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
        temp->next = NULL;
    }
}
void insertAtpos(int value, int pos)
{
    struct node *temp;
    int key;
    // printf("Enter the position: ");
    // scanf("%d", &pos);
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = value;
    printf("Enter the key: ");
    scanf("%d", &key);
    temp->key = key;
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        ptr = head;
        while (pos != 1)
        {
            ptr = ptr->next;
            pos--;
        }
        temp->next = ptr->next;
        ptr->next = temp;
    }
}
void deleteAtbeginning()
{
    if (head == NULL)
    {
        printf("List if Empty, Deletion is not Possible");
    }
    else
    {
        ptr = head;
        head = head->next;
        ptr->next = NULL;
        free(ptr);
    }
}
void deleteFromEnd()
{
    if (head == NULL)
    {
        printf("List if Empty, Deletion is not Possible");
    }
    else
    {
        struct node *p;
        ptr = head;
        while (ptr->next != NULL)
        {
            p = ptr;
            ptr = ptr->next;
        }
        p->next = NULL;
        free(ptr);
    }
}
void display()
{
    if (head == NULL)
    {
        printf("The linked list is empty");
    }
    else
    {
        ptr = head;
        while (ptr != NULL)
        {
            printf("%d->", ptr->data);
            ptr = ptr->next;
        }
        printf("\n");
    }
}
void deleteAtPosition(int pos)
{
    // printf("Enter position: ");
    // scanf("%d", &pos);
    struct node *next;
    int i = 1;
    ptr = head;
    while (i < pos - 1)
    {
        ptr = ptr->next;
        i++;
    }
    next = ptr->next;
    ptr->next = next->next;
    free(next);
    next = NULL;
}
void numberOfNodes()
{
    int count = 0;
    if (head == NULL)
    {
        printf("The linked list is empty");
    }
    else
    {
        ptr = head;
        while (ptr != NULL)
        {
            count++;
            ptr = ptr->next;
        }
        printf("The total number of nodes is %d\n", count);
    }
}
void search()
{
    ptr = head;
    int value;
    printf("Enter the value you want to be searched: ");
    scanf("%d", &value);
    int count = 1;
    while (ptr != NULL)
    {
        if (ptr->data == value)
        {
            printf("Element found at pos %d\n", count);
        }
        ptr = ptr->next;
        count++;
    }
}
void deleteFromKey()
{
    struct node *current = head;
    int key;
    printf("Enter key you want to be deleted: ");
    scanf("%d", &key);
    if (head && head->key == key)
        head = head->next;
    while (current && current->next)
    {
        if (current->next->key == key)
            current->next = current->next->next;
        else
            current = current->next;
    }
    display();
}
int main()
{
    int value, ele, ch;
    printf("1.Check whether empty \n");
    printf("2. Insert at begin \n");
    printf("3. Insert at end \n");
    printf("4. Insert After specified position \n");
    printf("5. Delete from begin \n");
    printf("6. Delete from end \n");
    printf("7. Delete from position \n");
    printf("8. Count the number of nodes \n");
    printf("9. Search the specific element \n");
    printf("10. Delete for a key\n");
    printf("11. Exit \n");
    while (1)
    {
        printf("Enter the Choice \n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
        {
            isEmpty();
            break;
        }
        case 2:
        {
            printf("Enter the value: ");
            scanf("%d", &value);
            insert_begin(value);
            display();
            break;
        }
        case 3:
        {
            printf("Enter the value: ");
            scanf("%d", &value);
            insert_end(value);
            display();
            break;
        }
        case 4:
        {
            int pos;
            printf("Enter the value: ");
            scanf("%d", &value);
            printf("After which position u want to insert: ");
            scanf("%d", &pos);
            insertAtpos(value, pos);
            display();
            break;
        }
        case 5:
        {
            deleteAtbeginning();
            display();
            break;
        }
        case 6:
        {
            deleteFromEnd();
            display();
            break;
        }
        case 7:
        {
            int pos;
            printf("Enter the position you want to delete: ");
            scanf("%d", &pos);
            deleteAtPosition(pos);
            display();
            break;
        }
        case 8:
        {
            numberOfNodes();
            break;
        }
        case 9:
        {
            search();
            break;
        }
        case 10:
        {
            deleteFromKey();
            break;
        }
        case 11:
        {
            exit(0);
            break;
        }
        }
    }
}