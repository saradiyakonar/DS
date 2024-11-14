#include <stdio.h>
#include <stdlib.h>
int main()
{
    printf("Enter the no of elements in an array: ");
    int n;
    scanf("%d", &n);
    int *ptr;
    ptr = (int *)malloc(sizeof(int));
    printf("Enter the elements of an array: ");
    for (int j = 0; j < n; j++)
    {
        scanf("%d", &ptr[j]);
    }
    printf("The elements of the array are: ");
    for (int k = 0; k < n; ++k)
    {
        printf("%d, ", ptr[k]);
    }
    printf("\n");
    printf("Enter the element you want to search: ");
    int key;
    int found = 0;
    scanf("%d", &key);
    int j = 0;
    for (j = 0; j < n; j++)
    {
        if (ptr[j] == key)
        {
            found = 1;
            break;
        }
    }
    if (found == 1)
    {
        printf("Element %d found at index %d", key, (j));
    }
    else
    {
        printf("Element not found in array");
    }
}