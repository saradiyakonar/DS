#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *prev;
    int data;
    int key;
    struct node *next;
};
struct node *head, *tail = NULL;
struct node *ptr;
void traverse_forward(struct node *dl)
{
    ptr = head;
    if (head == NULL)
    {
        printf("The linked list is empty");
    }
    else
    {
        while (ptr != NULL)
        {
            printf("%d<=>", ptr->data);
            ptr = ptr->next;
        }
        printf("\n");
    }
}
void traverse_backward(struct node *dl)
{
    ptr = tail;
    if (tail == NULL)
    {
        printf("The linked list is empty");
    }
    else
    {
        while (ptr != NULL)
        {
            printf("%d<=>", ptr->data);
            ptr = ptr->prev;
        }
        printf("\n");
    }
}
void insert_beg(struct node *dl, int value, int key)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->key = key;
    temp->data = value;
    temp->next = NULL;
    temp->prev = NULL;
    if (head == NULL)
    {
        head = tail = temp;
    }
    else
    {
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}
void insert_end(struct node *dl, int value, int key)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->key = key;
    temp->data = value;
    temp->next = NULL;
    temp->prev = NULL;
    if (head == NULL)
    {
        head = tail = temp;
    }
    else
    {
        temp->prev = tail;
        tail->next = temp;
        tail = temp;
    }
}
void insertAtpos(struct node *dl, int value, int pos, int key)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->key = key;
    temp->data = value;
    temp->next = NULL;
    temp->prev = NULL;
    if (head == NULL)
    {
        head = tail = temp;
    }
    else
    {
        ptr = head;
        while (pos != 1)
        {
            ptr = ptr->next;
            pos--;
        }
        temp->prev = ptr;
        temp->next = ptr->next;
        ptr->next->prev = temp;
        ptr->next = temp;
    }
}
void deleteFromBeg(struct node *dl)
{
    if (head == NULL)
    {
        printf("The linked list is empty: \n");
    }
    else
    {
        ptr = head;
        head = head->next;
        ptr->next = NULL;
        free(ptr);
    }
}
void deleteFromEnd(struct node *dl)
{
    if (tail == NULL)
    {
        printf("The linked list is empty: \n");
    }
    else
    {
        ptr = tail;
        tail = tail->prev;
        tail->next = NULL;
        ptr->prev = NULL;
        free(ptr);
    }
}
void search(struct node *dl)
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
            return;
        }
        else
        {
            printf("Element not found");
        }
        ptr = ptr->next;
        count++;
    };
}
void numberOfNodes(struct node *dl)
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
void deletefromPos(struct node *dl, int pos)
{
    ptr = head;
    while (pos != 1)
    {
        ptr = ptr->next;
        pos--;
    }
    struct node *temp = ptr;
    ptr->prev->next = ptr->next;
    ptr->next->prev = ptr->prev;
    temp->prev = temp->next = NULL;
    free(temp);
}
void deleteFromKey(struct node *dl)
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
}
void isEmpty(struct node *dl)
{
    if (head == NULL)
    {
        printf("The linked list is empty:");
        return;
    }
    printf("The linked list is not empty");
}
int main()
{
    struct node *dl = NULL;
    insert_end(dl, 2, 1);
    insert_end(dl, 3, 2);
    insert_end(dl, 4, 3);
    insert_end(dl, 8, 4);
    insert_end(dl, 1, 5);
    insert_end(dl, 10, 6);
    int value, ele, ch, key;
    printf("1. Traverse forward \n");
    printf("2. Traverse backward \n");
    printf("3. Insert the node at begining \n");
    printf("4. Insert the node at end \n");
    printf("5. Insert the node at a position \n");
    printf("6. Delete the node from begining \n");
    printf("7. Delete the node from end \n");
    printf("8. Delete the node from position \n");
    printf("9. Delete the node for the key\n");
    printf("10. Total number of nodes \n");
    printf("11. Search the element \n");
    printf("12. Empty checking \n");
    printf("13. Quit\n");
    while (1)
    {
        printf("Enter the Choice \n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
        {
            traverse_forward(dl);
            break;
        }
        case 2:
        {
            traverse_backward(dl);
            break;
        }
        case 3:
        {
            printf("Enter the value: ");
            scanf("%d", &value);
            printf("Enter the key: ");
            scanf("%d", &key);
            insert_beg(dl, value, key);
            traverse_forward(dl);
            break;
        }
        case 4:
        {
            printf("Enter the value: ");
            scanf("%d", &value);
            printf("Enter the key: ");
            scanf("%d", &key);
            insert_end(dl, value, key);
            traverse_forward(dl);
            break;
        }
        case 5:
        {
            int pos;
            printf("Enter the value: ");
            scanf("%d", &value);
            printf("Enter the key: ");
            scanf("%d", &key);
            printf("After which position u want to insert: ");
            scanf("%d", &pos);
            if (pos == 1)
            {
                insert_beg(dl, value, key);
            }
            else
            {
                insertAtpos(dl, value, pos, key);
            };
            traverse_forward(dl);
            break;
        }
        case 6:
        {
            deleteFromBeg(dl);
            traverse_forward(dl);
            break;
        }
        case 7:
        {
            deleteFromEnd(dl);
            traverse_forward(dl);
            break;
        }
        case 8:
        {
            int pos;
            printf("Enter the position you want to delete: ");
            scanf("%d", &pos);
            if (pos == 1)
            {
                deleteFromBeg(dl);
            }
            else
            {
                deletefromPos(dl, pos);
            }
            traverse_forward(dl);
            break;
        }
        case 9:
        {
            deleteFromKey(dl);
            traverse_forward(dl);
            break;
        }
        case 10:
        {
            numberOfNodes(dl);
            break;
        }
        case 11:
        {
            search(dl);
            break;
        }
        case 12:
        {

            isEmpty(dl);
            break;
        }
        case 13:
        {
            exit(0);
        }
        }
    }
}