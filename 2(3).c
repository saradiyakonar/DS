#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, a, b, a1, b1;
    int *c;

    printf("Enter the value of n : ");
    scanf("%d", &n);
    c = (int *)malloc(sizeof(int));
    printf("Enter the elements : \n");
    for (int k = 0; k < n; k++)
    {
        scanf("%d", &c[k]);
    }

    printf("Enter the value of a and b :");
    scanf("%d %d", &a, &b);

    for (int k = 0; k < n; k++)
    {
        if (c[k] == a)
        {
            a1 = k;
            break;
        }
    }
    for (int k = 0; k < n; k++)
    {
        if (c[k] == b)
        {
            b1 = k;
            break;
        }
    }
    if (a1 > b1)
    {
        int t = a1;
        a1 = b1;
        b1 = t;
    }
    for (int j = a1; j <= b1; j++)
    {
        printf("%d", c[j]);
    }
    return 0;
}