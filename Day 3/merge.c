#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge ( int arr[], int l, int m, int r){
    int i, j, k;
    int n1 = m-l+1;
    int n2 = r-m;

    int L[n1], R[n2];

    for(i=0; i<n1; i++){
        L[i] = arr[l+i];
    }

    for(j=0; j<n2; j++){
        R[j] = arr[m+1+j];
    }
    i=0, j=0, k=l;
    
    while(i<n1 && j<n2){
        if(L[i] < R[j]){
            arr[k]= L[i]; 
            i++;
        }
        else{
            arr[k]=R[j];
            j++;
        }
        k++;
    }
    while (i<n1){
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j<n2){
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort ( int arr[], int l, int r){
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

void generateFile(int size) {
    FILE *file = fopen("input.dat", "w");
    if (file == NULL) {
        printf("Error opening file %s\n");
        exit(1);
    }

    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        fprintf(file, "%d ", rand() % 1000);
    }

    fclose(file);
}

void readArray(int arr[], int *size) {
    FILE *file = fopen("input.dat", "r");
    if (file == NULL) {
        printf("Error opening file %s\n");
        exit(1);
    }
    
    int i = 0;
    while (fscanf(file, "%d", &arr[i]) != EOF) {
        i++;
    }
    *size = i;

    fclose(file);
}

void writeArray(int arr[], int size) {
    FILE *file = fopen("output.dat", "w");
    if (file == NULL) {
        printf("Error opening file %s\n");
        exit(1);
    }
    
    for (int i = 0; i < size; i++) {
        fprintf(file, "%d ", arr[i]);
    }

    fclose(file);
}

int binarySearch(int arr[], int size, int key) {
    int left = 0;
    int right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == key) {
            return mid;  
        }
        if (arr[mid] < key) {
            left = mid + 1;  
        } else {
            right = mid - 1; 
        }
    }
    return -1;
}

int main(){
    int arr[500];
    int size;
    int num = 300 + rand () % 201;
    generateFile(num);
    readArray(arr, &size);
    mergeSort(arr, 0, size-1);

    int key;
    printf("Enter the number to search: ");
    scanf("%d", &key);
    int result = binarySearch(arr, size, key);

    if (result != -1) {
        printf("Element %d found at index %d\n", key, result);
    } else {
        printf("Element %d not found in the array\n", key);
    }

    writeArray(arr,size);
}
