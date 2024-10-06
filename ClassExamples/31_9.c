// 9. Algorithm for recursive function for sum.

#include <stdio.h>

// Recursive function to calculate the sum of the first n natural numbers
int recursiveSum(int n) {
    // Base case: if n is 0, return 0
    if (n == 0) {
        return 0;
    }
    // Recursive case: return n plus sum of the first n-1 natural numbers
    return n + recursiveSum(n - 1);
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
    int result = recursiveSum(n);
    printf("The sum of the first %d natural numbers is: %d\n", n, result);

    return 0;
}
