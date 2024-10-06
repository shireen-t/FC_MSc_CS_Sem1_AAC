// 5. Write an algorithm for sequencial search.

#include <stdio.h>

// Function to perform sequential search
int sequentialSearch(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            return i; // Return the index if found
        }
    }
    return -1; // Return -1 if not found
}

int main() {
    int arr[] = {4, 2, 3, 5, 1}; // Example array
    int n = sizeof(arr) / sizeof(arr[0]); // Size of the array
    int x;

    // Input the target value to search for
    printf("Enter the number to search: ");
    scanf("%d", &x);

    // Perform sequential search
    int result = sequentialSearch(arr, n, x);

    // Output the result
    if (result != -1) {
        printf("Element %d found at index %d.\n", x, result);
    } else {
        printf("Element %d not found in the array.\n", x);
    }

    return 0;
}
