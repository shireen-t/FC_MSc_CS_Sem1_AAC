// 5. Write an algorithm to find min of n numbers.

#include <stdio.h>

int main() {
    int n, min, num;

    // Input the number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Check for valid input
    if (n <= 0) {
        printf("Please enter a positive integer for the number of elements.\n");
        return 1; // Exit the program with an error code
    }

    // Input the first number and initialize min
    printf("Enter number 1: ");
    scanf("%d", &num);
    min = num; // Initialize min to the first number

    // Input the remaining numbers and find the minimum
    for (int i = 2; i <= n; i++) {
        printf("Enter number %d: ", i);
        scanf("%d", &num);

        if (num < min) {
            min = num; // Update min if the current number is smaller
        }
    }

    // Output the minimum number
    printf("The minimum number is: %d\n", min);

    return 0;
}
