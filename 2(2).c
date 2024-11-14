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
    int j = 0;
    int i = 0;
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (ptr[i] > ptr[j])
            {
                int temp = ptr[i];
                ptr[i] = ptr[j];
                ptr[j] = temp;
            }
        }
    }
    printf("The sorted array is: ");
    for (int k = 0; k < n; k++)
    {
        printf("%d, ", ptr[k]);
    }
}