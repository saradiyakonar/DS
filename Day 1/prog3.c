#include <stdio.h>
#include <stdlib.h>
void generateRandomNumbers(){
    int min;
    int max;
    int count;
    printf("Enter min: ");
    scanf("%d",&min);
    printf("Enter max: ");
    scanf("%d",&max);
    for (int i = 0; i <25; i++) {
        printf("%d\t", rand() % (max - min + 1) + min);
    }
}
int main() {
    generateRandomNumbers();
}
