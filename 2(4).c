#include <stdio.h>
// nonzero
int countNonZeroElements(int A[][100], int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (A[i][j] != 0)
            {
                count++;
            }
        }
    }
    return count;
}

// sum of elements
int sumAboveLeadingDiagonal(int A[][100], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j > i)
            {
                sum += A[i][j];
            }
        }
    }
    return sum;
}

// display elements below the minor diagonal
void displayBelowMinorDiagonal(int A[][100], int n)
{
    printf("Elements below the minor diagonal:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j < i)
            {
                printf("%d ", A[i][j]);
            }
        }
        printf("\n");
    }
}

// product of leading diagonal elements
int productOfLeadingDiagonal(int A[][100], int n)
{
    int product = 1;
    for (int i = 0; i < n; i++)
    {
        product *= A[i][i];
    }
    return product;
}

int main()
{
    int n;
    printf("Enter the size of the square matrix (n): ");
    scanf("%d", &n);

    int A[100][100];

    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }

    printf("Number of nonzero elements: %d\n", countNonZeroElements(A, n));
    printf("Sum of elements above the leading diagonal: %d\n", sumAboveLeadingDiagonal(A, n));
    displayBelowMinorDiagonal(A, n);
    printf("Product of leading diagonal elements: %d\n", productOfLeadingDiagonal(A, n));

    return 0;
}