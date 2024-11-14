#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j, x, y, m;
    printf("Enter the number of elements in array : ");
    scanf("%d", &n);

    m = n;

    int *arr;
    arr = (int *)malloc(sizeof(int));

    printf("Enter the elements of the array :\n");
    for (int k = 0; k < n; k++)
    {
        scanf("%d", &arr[k]);
    }

    printf("Enter x and y : \n");
    scanf("%d %d", &x, &y);
    if (x == y)
    {
        printf("The shortest distance between the elements is 0");
    }
    for (i = 0; i < n - 1; i++)
    {
        if (arr[i] == x)
        {
            for (j = i + 1; j < n; j++)
            {
                if (arr[j] == x)
                {
                    i = j;
                }
                else if (arr[j] == y)
                {
                    if (j - i < m)
                    {
                        m = j - i;
                    }
                }
            }
        }
        else if (arr[i] == y)
        {
            for (j = i + 1; j < n; j++)
            {
                if (arr[j] == y)
                {
                    i = j;
                }
                else if (arr[j] == x)
                {
                    if (j - i < m)
                    {
                        m = j - i;
                    }
                }
            }
        }
    }
    printf("The shortest distance between the numbers is %d", m);
    return 0;
}