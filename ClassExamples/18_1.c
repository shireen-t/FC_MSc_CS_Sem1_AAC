// 1. Write a program to find a factorial of n numbers.

#include <stdio.h>

int main() {
    int n;
    unsigned long long factorial = 1;

    printf("Enter a non-negative integer: ");
    scanf("%d", &n);

    // Check for non-negative input
    if (n < 0) {
        printf("Factorial is not defined for negative numbers.\n");
        return 1; // Exit the program
    }

    // Calculate factorial
    for (int i = 1; i <= n; i++) {
        factorial *= i;
    }

    // Print the result
    printf("Factorial of %d is %llu\n", n, factorial);

    return 0;
}
