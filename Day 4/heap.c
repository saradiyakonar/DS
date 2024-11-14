#include <stdio.h>
#include <stdlib.h>
int arr[1000];
int size=0;
void readNumbersFromFile(char *filename) 
{
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file for reading");
        exit(EXIT_FAILURE);
    }
    size = 0;
    while (fscanf(file, "%d", &arr[size]) != EOF) {
        size++;
    }
    fclose(file);
}
void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int comparisons=0;
int heapify(int arr[], int N, int i)
{
    comparisons=0;
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < N && arr[left] > arr[largest])
        largest = left;
        comparisons++;
    if (right < N && arr[right] > arr[largest])
        largest = right;
        comparisons++;
    if (largest != i) {
        comparisons+=1;
        swap(&arr[i], &arr[largest]);
        comparisons+=heapify(arr, N, largest);
    }
    return comparisons;
}
void heapSort(int arr[], int N)
{   
    comparisons=0;
    for (int i = N / 2 - 1; i >= 0; i--){
        heapify(arr, N, i);
        comparisons+=heapify(arr,i,0);
    }
    for (int i = N - 1; i >= 0; i--) {
        swap(&arr[0], &arr[i]);
        comparisons+=heapify(arr, i, 0);
    }
    // printf("Total number of comparisons is: %d /n",comparisons);
}
void printArray(int arr[], int N)
{
    for (int i = 0; i < N; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
int main(){
    readNumbersFromFile("1_1.txt");
    heapSort(arr, size);
    comparisons=0;
    readNumbersFromFile("2_1.txt");
    heapSort(arr,size);
    comparisons=0;
    readNumbersFromFile("3_1.txt");
    heapSort(arr,size);
    //printf("Sorted array is\n");
    //printArray(arr, size);
}