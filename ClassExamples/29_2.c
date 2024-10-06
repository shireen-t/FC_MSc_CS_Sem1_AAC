// 2. Write an algorithm to print odd numbers between 11 to 30 in reverse order.

#include <stdio.h>

int main() {
    printf("Odd numbers between 11 and 30 in reverse order:\n");

    // Loop from 29 down to 11
    for (int i = 29; i >= 11; i--) {
        // Check if the number is odd
        if (i % 2 != 0) {
            printf("%d\n", i);
        }
    }

    return 0;
}
