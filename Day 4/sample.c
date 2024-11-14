#include <stdio.h>

typedef struct {
    int item_id;
    float item_profit;
    float item_weight;
    float profit_weight_ratio;
} ITEM;

void swap(ITEM* a, ITEM* b) {
    ITEM temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(ITEM arr[], int n, int i) {
    int largest = i; 
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left].profit_weight_ratio > arr[largest].profit_weight_ratio)
        largest = left;

    if (right < n && arr[right].profit_weight_ratio > arr[largest].profit_weight_ratio)
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(ITEM arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

float fractionalKnapsack(ITEM items[], int n, float knapsack_capacity) {
    heapSort(items, n);

    float total_profit = 0.0;
    float remaining_capacity = knapsack_capacity;

    for (int i = 0; i < n; i++) {
        if (items[i].item_weight <= remaining_capacity) {
            total_profit += items[i].item_profit;
            remaining_capacity -= items[i].item_weight;
        } else {
            total_profit += items[i].profit_weight_ratio * remaining_capacity;
            break;
        }
    }

    return total_profit;
}

int main() {
    int n;
    float knapsack_capacity;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    ITEM items[n];

    for (int i = 0; i < n; i++) {
        printf("Enter profit and weight for item %d: ", i + 1);
        scanf("%f %f", &items[i].item_profit, &items[i].item_weight);
        items[i].item_id = i + 1;
        items[i].profit_weight_ratio = items[i].item_profit / items[i].item_weight;
    }

    printf("Enter knapsack capacity: ");
    scanf("%f", &knapsack_capacity);

    float max_profit = fractionalKnapsack(items, n, knapsack_capacity);

    printf("Maximum profit closest to knapsack capacity: %.2f\n", max_profit);

    return 0;
}
