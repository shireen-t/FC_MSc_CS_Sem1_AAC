// Implement 0/1 Knapsack problem using Dynamic
// Programming.

#include <stdio.h>

#define MAX_ITEMS 100
#define MAX_CAPACITY 1000

// Function prototype
int knapsack(int capacity, int weights[], int values[], int n);

int main() {
    int n, capacity;
    int weights[MAX_ITEMS], values[MAX_ITEMS];

    printf("Enter the number of items: ");
    scanf("%d", &n);
    
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);
    
    printf("Enter the weights and values of the items:\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d - Weight: ", i + 1);
        scanf("%d", &weights[i]);
        printf("Item %d - Value: ", i + 1);
        scanf("%d", &values[i]);
    }

    int maxValue = knapsack(capacity, weights, values, n);
    printf("Maximum value in the knapsack: %d\n", maxValue);

    return 0;
}

// Function to solve the 0/1 Knapsack problem using Dynamic Programming
int knapsack(int capacity, int weights[], int values[], int n) {
    int dp[MAX_CAPACITY + 1] = {0}; // DP array to store maximum values

    // Build the DP array
    for (int i = 0; i < n; i++) {
        for (int w = capacity; w >= weights[i]; w--) {
            dp[w] = (dp[w] > dp[w - weights[i]] + values[i]) ? dp[w] : (dp[w - weights[i]] + values[i]);
        }
    }

    return dp[capacity]; // The maximum value that can be carried in the knapsack
}
