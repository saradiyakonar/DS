#include <stdio.h>
void EXCHANGE(int *p, int *q) {
    int temp = *p;
    *p = *q;
    *q = temp;
}


void ROTATE_RIGHT(int *p1, int p2) {
    if (p2 <= 1) return; 

    
    int temp = *(p1 + p2 - 1);

    
    for (int i = p2 - 1; i > 0; i--) {
        *(p1 + i) = *(p1 + i - 1);
    }
    *(p1) = temp;
}
void printArray(int *array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter size of the array: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter an array of size %d:",n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int p2 = 5; 

    printf("Before rotate:\n");
    printArray(arr, n);

    ROTATE_RIGHT(arr, p2);

    printf("After rotate:\n", p2);
    printArray(arr, n);

    return 0;
}
