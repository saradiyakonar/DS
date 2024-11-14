#include <stdio.h>

typedef struct {
    int item_id;
    double item_profit;
    double item_weight;
    double profit_weight_ratio;
} ITEM;

void heapify(ITEM items[], int n, int i) {
    int largest = i; 
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && items[left].profit_weight_ratio > items[largest].profit_weight_ratio)
        largest = left;

    if (right < n && items[right].profit_weight_ratio > items[largest].profit_weight_ratio)
        largest = right;

    if (largest != i) {
        ITEM temp = items[i];
        items[i] = items[largest];
        items[largest] = temp;
        heapify(items, n, largest);
    }
}

void heapSort(ITEM items[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(items, n, i);

    for (int i = n - 1; i > 0; i--) {
        ITEM temp = items[0];
        items[0] = items[i];
        items[i] = temp;
        heapify(items, i, 0);
    }
}

int main() {
    int n;
    printf("Enter the number of items: ");
    scanf("%d", &n);

    ITEM items[n];
    for (int i = 0; i < n; i++) {
        printf("Enter the profit and weight of item no %d: ", i + 1);
        scanf("%lf %lf", &items[i].item_profit, &items[i].item_weight);
        items[i].item_id = i + 1;
        items[i].profit_weight_ratio = items[i].item_profit / items[i].item_weight;
    }

    double capacity;
    printf("Enter the capacity of knapsack: ");
    scanf("%lf", &capacity);

    heapSort(items, n);

    double total_profit = 0.0;
    double amount_taken[n];
    for (int i = 0; i < n; i++) {
        amount_taken[i] = 0.0;
    }
    for (int i = n - 1; i >= 0; i--) {
        if (items[i].item_weight <= capacity) {
            capacity -= items[i].item_weight;
            total_profit += items[i].item_profit;
            amount_taken[items[i].item_id - 1] = 1.0;
        } else {
            total_profit += items[i].item_profit * (capacity / items[i].item_weight);
            amount_taken[items[i].item_id - 1] = capacity / items[i].item_weight;
            break;
        }
    }
    printf("Item No\tProfit\tWeight\tAmount to be taken\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%.6lf\t%.6lf\t%.6lf\n", items[i].item_id, items[i].item_profit, items[i].item_weight, amount_taken[items[i].item_id - 1]);
    }
    printf("Maximum profit: %.6lf\n", total_profit);
    return 0;
}