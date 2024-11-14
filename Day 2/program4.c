#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}


void compute(const char *inputFile, const char *outputFile) {
    FILE *inFile = fopen(inputFile, "r");
    FILE *outFile = fopen(outputFile, "w");

    if (inFile == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    if (outFile == NULL) {
        printf("Error opening output file.\n");
        fclose(inFile);
        exit(1);
    }

    int num1, num2;
    while (fscanf(inFile, "%d %d", &num1, &num2) != EOF) {
        int result = gcd(num1, num2);
        fprintf(outFile, "GCD of %d and %d is %d\n", num1, num2, result);
    }

    fclose(inFile);
    fclose(outFile);
}

int main() {
    const char *inputFile = "numbers.txt";   
    const char *outputFile = "gcd.txt"; 

    compute(inputFile, outputFile);

    printf("GCD computation completed. Results are stored in '%s'.\n", outputFile);

    return 0;
}
