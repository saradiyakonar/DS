#include <stdio.h>
#include <limits.h>

#define MAX 100
void matrixChainOrder(int p[], int n, int mTable[MAX][MAX], int sTable[MAX][MAX]) {
    for (int i = 1; i < n; i++) {
        mTable[i][i] = 0;  
    }

    for (int length = 2; length < n; length++) {
        for (int i = 1; i < n - length + 1; i++) {
            int j = i + length - 1;
            mTable[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                int q = mTable[i][k] + mTable[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < mTable[i][j]) {
                    mTable[i][j] = q;
                    sTable[i][j] = k;
                }
            }
        }
    }
}
void printOptimalParens(int sTable[MAX][MAX], int i, int j) {
    if (i == j) {
        printf("A%d", i);
    } else {
        printf("(");
        printOptimalParens(sTable, i, sTable[i][j]);
        printOptimalParens(sTable, sTable[i][j] + 1, j);
        printf(")");
    }
}
int areDimensionsCompatible(int dims[], int n) {
    for (int i = 1; i < n; i++) {
        if (dims[i - 1] != dims[i]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int n;
    printf("Enter number of matrices: ");
    scanf("%d", &n);

    if (n < 2) {
        printf("At least two matrices are required for multiplication.\n");
        return 1;
    }

    int p[MAX];
    for (int i = 0; i < n; i++) {
        int rows, cols;
        printf("Enter row and col size of A%d: ", i + 1);
        scanf("%d %d", &rows, &cols);
        if (i == 0) {
            p[i] = rows;
            p[i + 1] = cols;
        } else {
            if (p[i] != rows) {
                printf("Dimension mismatch: Rows of A%d must match cols of A%d\n", i + 1, i);
                return 1;
            }
            p[i + 1] = cols;
        }
    }

    int mTable[MAX][MAX] = {0}, sTable[MAX][MAX] = {0};
    matrixChainOrder(p, n + 1, mTable, sTable);
    printf("\nM Table:\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%d ", mTable[i][j]);
        }
        printf("\n");
    }

    printf("\nS Table:\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%d ", sTable[i][j]);
        }
        printf("\n");
    }
    printf("\nMinimum number of multiplications: %d\n", mTable[1][n]);
    printf("Optimal parenthesization: ");
    printOptimalParens(sTable, 1, n);
    printf("\n");

    return 0;
}
