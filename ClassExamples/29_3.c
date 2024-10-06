// 3. Write an algorithm to print odd numbers between 1 to 20 using repeat until loop.

#include <stdio.h>

int main() {
    int i = 1; // Start from 1

    printf("Odd numbers between 1 and 20:\n");

    do {
        // Print the current number if it's odd
        if (i % 2 != 0) {
            printf("%d\n", i);
        }
        i++; // Increment the counter
    } while (i <= 20); // Repeat until i exceeds 20

    return 0;
}
