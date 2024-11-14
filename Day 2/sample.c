#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Global variable to count iterations
int iteration_count;

// Swap function
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Bubble Sort for generating a sorted array
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

// Partition for Quick Sort with first element as pivot
int partition_first(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low + 1;
    for (int j = low + 1; j <= high; j++) {
        iteration_count++;  // Count iterations (comparisons)
        if (arr[j] < pivot) {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[low], &arr[i-1]);
    return i-1;
}

// Partition for Quick Sort with random element as pivot
int partition_random(int arr[], int low, int high) {
    int random_index = low + rand() % (high - low + 1);
    swap(&arr[low], &arr[random_index]);
    return partition_first(arr, low, high);
}

// Partition for Quick Sort with median of first, middle, and last element as pivot
int partition_median(int arr[], int low, int high) {
    int mid = low + (high - low) / 2;
    int first = arr[low], middle = arr[mid], last = arr[high];
    int median_index = low;
    
    if ((first < middle && middle < last) || (last < middle && middle < first))
        median_index = mid;
    else if ((middle < first && first < last) || (last < first && first < middle))
        median_index = low;
    else
        median_index = high;
    
    swap(&arr[low], &arr[median_index]);
    return partition_first(arr, low, high);
}

// Quick Sort implementation
void quickSort(int arr[], int low, int high, int (*partition)(int[], int, int)) {
    if (low < high) {
        int pivot_index = partition(arr, low, high);
        quickSort(arr, low, pivot_index - 1, partition);
        quickSort(arr, pivot_index + 1, high, partition);
    }
}

// Save the array to a file
void saveToFile(const char *filename, int arr[], int size) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        return;
    }
    for (int i = 0; i < size; i++) {
        fprintf(file, "%d ", arr[i]);
    }
    fclose(file);
}

// Read the array from a file
void readFromFile(const char *filename, int arr[], int size) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        return;
    }
    for (int i = 0; i < size; i++) {
        fscanf(file, "%d", &arr[i]);
    }
    fclose(file);
}

// Main function
int main() {
    int size;
    printf("Enter the size of the array (N): ");
    scanf("%d", &size);

    int arr[size];
    srand(time(0));

    // Generate a random unsorted array
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100 + 1;
    }
    saveToFile("file11.txt", arr, size);

    // Create sorted and reversed arrays
    int sorted[size], reversed[size];
    for (int i = 0; i < size; i++) {
        sorted[i] = arr[i];
    }
    bubbleSort(sorted, size);
    saveToFile("file21.txt", sorted, size);

    for (int i = 0; i < size; i++) {
        reversed[i] = sorted[size - i - 1];
    }
    saveToFile("file31.txt", reversed, size);

    int copy[size];

    // Apply Quick Sort to the unsorted array
    readFromFile("file11.txt", copy, size);

    // First element as pivot
    iteration_count = 0;
    quickSort(copy, 0, size - 1, partition_first);
    saveToFile("file12.txt", copy, size);
    printf("Iterations for file11.txt with first element as pivot: %d\n", iteration_count);

    // Random element as pivot
    readFromFile("file11.txt", copy, size);
    iteration_count = 0;
    quickSort(copy, 0, size - 1, partition_random);
    saveToFile("file13.txt", copy, size);
    printf("Iterations for file11.txt with random element as pivot: %d\n", iteration_count);

    // Median of first, middle, and last element as pivot
    readFromFile("file11.txt", copy, size);
    iteration_count = 0;
    quickSort(copy, 0, size - 1, partition_median);
    saveToFile("file14.txt", copy, size);
    printf("Iterations for file11.txt with median element as pivot: %d\n", iteration_count);

    // Apply Quick Sort to the sorted array
    readFromFile("file21.txt", copy, size);

    // First element as pivot
    iteration_count = 0;
    quickSort(copy, 0, size - 1, partition_first);
    saveToFile("file22.txt", copy, size);
    printf("Iterations for file21.txt with first element as pivot: %d\n", iteration_count);

    // Random element as pivot
    readFromFile("file21.txt", copy, size);
    iteration_count = 0;
    quickSort(copy, 0, size - 1, partition_random);
    saveToFile("file23.txt", copy, size);
    printf("Iterations for file21.txt with random element as pivot: %d\n", iteration_count);

    // Median of first, middle, and last element as pivot
    readFromFile("file21.txt", copy, size);
    iteration_count = 0;
    quickSort(copy, 0, size - 1, partition_median);
    saveToFile("file24.txt", copy, size);
    printf("Iterations for file21.txt with median element as pivot: %d\n", iteration_count);

    // Apply Quick Sort to the reversed array
    readFromFile("file31.txt", copy, size);

    // First element as pivot
    iteration_count = 0;
    quickSort(copy, 0, size - 1, partition_first);
    saveToFile("file32.txt", copy, size);
    printf("Iterations for file31.txt with first element as pivot: %d\n", iteration_count);

    // Random element as pivot
    readFromFile("file31.txt", copy, size);
    iteration_count = 0;
    quickSort(copy, 0, size - 1, partition_random);
    saveToFile("file33.txt", copy, size);
    printf("Iterations for file31.txt with random element as pivot: %d\n", iteration_count);

    // Median of first, middle, and last element as pivot
    readFromFile("file31.txt", copy, size);
    iteration_count = 0;
    quickSort(copy, 0, size - 1, partition_median);
    saveToFile("file34.txt", copy, size);
    printf("Iterations for file31.txt with median element as pivot: %d\n", iteration_count);

    return 0;
}
