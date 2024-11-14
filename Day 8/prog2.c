#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void lcs(char* X, char* Y, int m, int n) {
    int L[m + 1][n + 1];
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;
            else
                L[i][j] = (L[i - 1][j] > L[i][j - 1]) ? L[i - 1][j] : L[i][j - 1];
        }
    }

    int length = L[m][n];

    char lcs[length + 1];
    lcs[length] = '\0'; 
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            lcs[length - 1] = X[i - 1]; 
            i--;
            j--;
            length--; 
        } else if (L[i - 1][j] > L[i][j - 1])
            i--;
        else
            j--;
    }

    printf("LCS of %s and %s is %s\n", X, Y, lcs);
    printf("Length of LCS: %d\n", L[m][n]);
}

int main() {
    char X[100], Y[100];    
    printf("Enter the first string: ");
    scanf("%s", X);
    printf("Enter the second string: ");
    scanf("%s", Y);

    int m = strlen(X);
    int n = strlen(Y);
    lcs(X, Y, m, n);

    return 0;
}
