// 1. Write an algorithm to print table of 2.

#include <stdio.h>

int main() {
    int i;

    printf("Multiplication table of 2:\n");

    // Loop to print the table from 1 to 10
    for (i = 1; i <= 10; i++) {
        printf("2 x %d = %d\n", i, 2 * i);
    }

    return 0;
}
