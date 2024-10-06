// 4. Write an algorithm to find max of n numbers.

#include <stdio.h>

int main() {
    int n, max, num;

    // Input the number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Check for valid input
    if (n <= 0) {
        printf("Please enter a positive integer for the number of elements.\n");
        return 1; // Exit the program with an error code
    }

    // Input the first number and initialize max
    printf("Enter number 1: ");
    scanf("%d", &num);
    max = num; // Initialize max to the first number

    // Input the remaining numbers and find the maximum
    for (int i = 2; i <= n; i++) {
        printf("Enter number %d: ", i);
        scanf("%d", &num);

        if (num > max) {
            max = num; // Update max if the current number is greater
        }
    }

    // Output the maximum number
    printf("The maximum number is: %d\n", max);

    return 0;
}
