// 1. Write a program to search an element in a given list.

#include <stdio.h>

int main() {
    int arr[100], n, search, i;
    int found = 0;

    // Input number of elements
    printf("Enter the number of elements in the list: ");
    scanf("%d", &n);

    // Input elements of the array
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Input the element to search for
    printf("Enter the element to search: ");
    scanf("%d", &search);

    // Linear search
    for (i = 0; i < n; i++) {
        if (arr[i] == search) {
            printf("Element %d found at index %d.\n", search, i);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Element %d not found in the list.\n", search);
    }

    return 0;
}
