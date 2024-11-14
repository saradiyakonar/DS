#include <stdio.h>
#include <stdlib.h>


void decimalToBinary(int n) {
    if (n == 0) {
        return;
    }
    decimalToBinary(n/2);
    printf("%d ", n%2);
}

void convertDecimalsToBinary(const char *inputFile, const char *outputFile) {
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
    int number;
    while (fscanf(inFile, "%d", &number) != EOF) {
        
        if (number == 0) {
            fprintf(outFile, "0");
        } else {
            decimalToBinary(number);
        }
        
        fprintf(outFile, "\n");
    }

    fclose(inFile);
    fclose(outFile);
}

int main() {
    const char *inputFile = "decimals.txt";
    const char *outputFile = "binaries.txt"; 
    convertDecimalsToBinary(inputFile, outputFile);
    printf("Conversion completed. Binary values are stored in '%s'.\n", outputFile);
    return 0;
}
