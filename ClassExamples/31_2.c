// 2. Write an algorithm to compute x^n using recursive method.

#include <stdio.h>

// Function to compute x^n recursively
double power(double x, int n) {
    // Base case: x^0 = 1
    if (n == 0) {
        return 1;
    }
    // Handle negative powers
    else if (n < 0) {
        return 1 / power(x, -n); // Compute x^(-n)
    }
    // Recursive case: x^n = x * x^(n-1)
    else {
        return x * power(x, n - 1);
    }
}

int main() {
    double x;
    int n;

    // Input base and exponent
    printf("Enter the base (x): ");
    scanf("%lf", &x);
    printf("Enter the exponent (n): ");
    scanf("%d", &n);

    // Compute and print the result
    double result = power(x, n);
    printf("%lf^%d = %lf\n", x, n, result);

    return 0;
}
