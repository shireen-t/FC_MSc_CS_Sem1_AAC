// 1. Write an algorithm for finding factorial using recursive method.

#include <stdio.h>

// Function to compute factorial recursively
long long factorial(int n) {
    // Base case: factorial of 0 is 1
    if (n == 0) {
        return 1;
    } else {
        // Recursive case: n! = n * (n-1)!
        return n * factorial(n - 1);
    }
}

int main() {
    int n;

    // Input a non-negative integer
    printf("Enter a non-negative integer: ");
    scanf("%d", &n);

    // Validate the input
    if (n < 0) {
        printf("Factorial is not defined for negative numbers.\n");
        return 1; // Exit with error code
    }

    // Calculate and print the factorial
    long long result = factorial(n);
    printf("Factorial of %d is %lld\n", n, result);

    return 0;
}
