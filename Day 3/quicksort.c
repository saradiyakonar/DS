#include <stdio.h>
#include <stdlib.h>
int arr[1000];
int size;
void generateRandomNumbers() 
{
    FILE *file = fopen("1_1.txt", "w");
    if (file == NULL) {
        printf("Error opening file for writing");
        exit(EXIT_FAILURE);
    }
    int lbound;
    int ubound;
    printf("Enter lower bound: ");
    scanf("%d", &lbound);
    printf("Enter upper bound: ");
    scanf("%d", &ubound);
    for (int i = 0; i < 1000; i++) {
        fprintf(file, "%d\t", rand() % (ubound - lbound + 1) + lbound);
    }
    fclose(file);
}
void readNumbersFromFile() 
{
    FILE *file = fopen("1_1.txt", "r");
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
void insertionsort() {
    for (int i = 1; i < size; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
void reverseinsertionsort() {
    for (int i = 1; i < size; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] < key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
void writeSortedNumbersToFile(char *outputFile) {
    FILE *outFile = fopen(outputFile, "w");
    if (outFile == NULL) {
        printf("Error opening file for writing");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < size; i++) {
        fprintf(outFile, "%d\t", arr[i]);
    }
    fclose(outFile);
}
int comparisons=0;
void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int left = low + 1;
    int right = high;
    while (left <= right) {
        while (left <= high && arr[left] <= pivot) {
            left++;
            comparisons++;
        }
        while (right >= low && arr[right] > pivot) {
            right--;
            comparisons++;
        }
        if (left < right) {
            swap(arr, left, right);
        }
    }
    swap(arr, low, right);
    return right;
}
void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}
void sortFileNumbers(char *filename) {
    FILE *file = fopen(filename, "r"); 
    if (!file) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }
    int arr[10000];
    int size = 0;
    while (fscanf(file, "%d", &arr[size]) != EOF) {
        size++;
        if (size >= 10000) {
            printf("File contains more numbers than the array can handle.\n");
            fclose(file);
            exit(EXIT_FAILURE);
        }
    }
    if (size == 0) {
        printf("No numbers to sort\n");
        fclose(file);
        return;
    }
    quicksort(arr, 0, size - 1);
    printf("Total number of comparisons: %d\n", comparisons);
    comparisons = 0;
}

void quickrand(int arr[],int low,int high)
{
    int rnd;
    printf("Enter number from between upper and lower bounds : ");
    scanf("%d",&rnd);
    swap(arr,arr[0],arr[rnd]);

    quicksort(arr,low,high);
}

void sortFileNumbersrand(char *filename) {
    FILE *file = fopen(filename, "r"); 
    if (!file) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }
    int arr[10000];
    int size = 0;
    while (fscanf(file, "%d", &arr[size]) != EOF) {
        size++;
        if (size >= 10000) {
            printf("File contains more numbers than the array can handle.\n");
            fclose(file);
            exit(EXIT_FAILURE);
        }
    }
    if (size == 0) {
        printf("No numbers to sort\n");
        fclose(file);
        return;
    }
    quickrand(arr, 0, size - 1);
    printf("Total number of comparisons: %d\n", comparisons);
    comparisons = 0;
}

void quickmed(int arr[],int low,int high)
{
    int mid = low+(high-low)/2;
    swap(arr,arr[0],arr[mid]);
    quicksort(arr,low,high);
}

void sortFileNumbersmed(char *filename) {
    FILE *file = fopen(filename, "r"); 
    if (!file) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }
    int arr[10000];
    int size = 0;
    while (fscanf(file, "%d", &arr[size]) != EOF) {
        size++;
        if (size >= 10000) {
            printf("File contains more numbers than the array can handle.\n");
            fclose(file);
            exit(EXIT_FAILURE);
        }
    }
    if (size == 0) {
        printf("No numbers to sort\n");
        fclose(file);
        return;
    }
    quickmed(arr, 0, size - 1);
    printf("Total number of comparisons: %d\n", comparisons);
    comparisons = 0;
}

int main() {
    generateRandomNumbers();
    readNumbersFromFile();
    insertionsort();
    writeSortedNumbersToFile("2_1.txt");
    reverseinsertionsort();
    writeSortedNumbersToFile("3_1.txt");
    char *filename1="1_1.txt";
    sortFileNumbers(filename1);
    char *filename2="2_1.txt";
    sortFileNumbers(filename2);
    char *filename3 = "3_1.txt";
    sortFileNumbers(filename3);
    sortFileNumbersrand(filename1);
    sortFileNumbersrand(filename2);
    sortFileNumbersrand(filename3);
    sortFileNumbersmed(filename1);
    sortFileNumbersmed(filename2);
    sortFileNumbersmed(filename3);
    // quicksort(numbers, 0, size - 1);
    // printf("Total number of comparisons during quicksort: %d\n",comparisons );
    return 0;
}
