// 8. Algorithm for iterative function for sum.

#include <stdio.h>

// Function to calculate the sum of the first n natural numbers iteratively
int iterativeSum(int n) {
    int sum = 0; // Initialize sum to 0
    for (int i = 1; i <= n; i++) {
        sum += i; // Add current number to sum
    }
    return sum; // Return the calculated sum
}

int main() {
    int n;

    // Input a non-negative integer
    printf("Enter a non-negative integer: ");
    scanf("%d", &n);

    // Validate the input
    if (n < 0) {
        printf("Please enter a non-negative integer.\n");
        return 1; // Exit with an error code
    }

    // Calculate and print the sum
    int result = iterativeSum(n);
    printf("The sum of the first %d natural numbers is: %d\n", n, result);

    return 0;
}
