// 4. Given n is a positive integer. Determine whether is sum of all of its divisors.

#include <stdio.h>

int main() {
    int n, sum = 0;

    // Input a positive integer
    printf("Enter a positive integer: ");
    scanf("%d", &n);

    // Calculate the sum of divisors (excluding n)
    for (int i = 1; i < n; i++) {
        if (n % i == 0) {
            sum += i;
        }
    }

    // Check if n is equal to the sum of its divisors
    if (sum == n) {
        printf("%d is equal to the sum of its divisors (excluding itself).\n", n);
    } else {
        printf("%d is not equal to the sum of its divisors (excluding itself).\n", n);
    }

    return 0;
}
