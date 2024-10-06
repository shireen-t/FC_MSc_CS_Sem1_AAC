// Write a program to print n x n magic square.

#include <stdio.h>

void generateMagicSquare(int n) {
    int magicSquare[n][n];

    // Initialize the magic square with 0s
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            magicSquare[i][j] = 0;
        }
    }

    int num = 1; // Start with the number 1
    int i = 0, j = n / 2; // Start position

    while (num <= n * n) {
        magicSquare[i][j] = num; // Place the current number in the magic square
        num++; // Move to the next number

        // Move to the next position
        int newi = (i - 1 + n) % n; // Up one row (wrap around)
        int newj = (j + 1) % n;      // Right one column (wrap around)

        if (magicSquare[newi][newj] != 0) { // If the position is already filled
            i++; // Move down one row instead
        } else {
            i = newi;
            j = newj;
        }
    }

    // Print the magic square
    printf("Magic Square of size %d:\n", n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%2d ", magicSquare[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;

    printf("Enter an odd number for the size of the magic square: ");
    scanf("%d", &n);

    if (n % 2 == 0) {
        printf("Please enter an odd number.\n");
    } else {
        generateMagicSquare(n);
    }

    return 0;
}
