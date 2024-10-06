// 2. Write a program for Fibonacci series.

#include <stdio.h>

int main() {
    int n, t1 = 0, t2 = 1, nextTerm;

    printf("Enter the number of terms in the Fibonacci series: ");
    scanf("%d", &n);

    printf("Fibonacci Series: ");

    // Generate the Fibonacci series
    for (int i = 1; i <= n; ++i) {
        if (i == 1) {
            printf("%d, ", t1); // Print first term
            continue;
        }
        if (i == 2) {
            printf("%d, ", t2); // Print second term
            continue;
        }
        nextTerm = t1 + t2; // Calculate the next term
        t1 = t2; // Update t1
        t2 = nextTerm; // Update t2
        printf("%d", nextTerm);
        
        if (i < n) {
            printf(", "); // Print comma for terms except the last one
        }
    }

    printf("\n");
    return 0;
}
