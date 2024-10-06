// 3. Write an recursive algorithm to return n Fibonacci number.

#include <stdio.h>

// Function to compute the n-th Fibonacci number recursively
int fibonacci(int n) {
    // Base case: Fibonacci of 0 is 0, and Fibonacci of 1 is 1
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    }
    // Recursive case: Fibonacci of n = Fibonacci of (n-1) + Fibonacci of (n-2)
    else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main() {
    int n;

    // Input a non-negative integer
    printf("Enter a non-negative integer: ");
    scanf("%d", &n);

    // Validate the input
    if (n < 0) {
        printf("Fibonacci is not defined for negative numbers.\n");
        return 1; // Exit with error code
    }

    // Calculate and print the n-th Fibonacci number
    int result = fibonacci(n);
    printf("Fibonacci number at position %d is %d\n", n, result);

    return 0;
}
