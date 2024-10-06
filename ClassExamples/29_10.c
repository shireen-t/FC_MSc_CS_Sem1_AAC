// 10. Write an algorithm for sorting given list using bubble sort.

#include <stdio.h>

void bubbleSort(int arr[], int n) {
    int temp;
    int swapped;

    // Loop through each element in the array
    for (int i = 0; i < n - 1; i++) {
        swapped = 0; // Initialize swapped flag

        // Compare adjacent elements
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap if the element found is greater
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1; // Set swapped flag
            }
        }

        // If no two elements were swapped, the array is sorted
        if (swapped == 0) {
            break;
        }
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    printArray(arr, n);

    bubbleSort(arr, n);

    printf("Sorted array:\n");
    printArray(arr, n);

    return 0;
}
