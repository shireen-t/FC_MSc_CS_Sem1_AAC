// 7. Write an algorithm to compute x^n.
#include <stdio.h>

double power(double x, int n) {
    // Base case: x^0 = 1
    if (n == 0) {
        return 1;
    }

    // Handle negative powers
    if (n < 0) {
        return 1 / power(x, -n); // Take reciprocal
    }

    // Recursive case
    return x * power(x, n - 1);
}

int main() {
    double x;
    int n;

    // Input x and n
    printf("Enter the base (x): ");
    scanf("%lf", &x);
    printf("Enter the exponent (n): ");
    scanf("%d", &n);

    // Compute x^n
    double result = power(x, n);

    // Output the result
    printf("%lf^%d = %lf\n", x, n, result);

    return 0;
}
