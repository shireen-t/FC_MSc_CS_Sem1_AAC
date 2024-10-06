// 6. Write an algorithm to create a magic square.

#include <stdio.h>

void createMagicSquare(int n) {
    int magicSquare[n][n];

    // Initialize all positions to 0
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            magicSquare[i][j] = 0;
        }
    }

    // Position for the first number
    int row = 0;
    int col = n / 2;

    // Fill the magic square
    for (int num = 1; num <= n * n; num++) {
        magicSquare[row][col] = num; // Place the number

        // Calculate next position
        int nextRow = (row - 1 + n) % n; // Move up
        int nextCol = (col + 1) % n; // Move right

        // If the next position is already occupied
        if (magicSquare[nextRow][nextCol] != 0) {
            row = (row + 1) % n; // Move down instead
        } else {
            row = nextRow; // Move to the calculated position
            col = nextCol; // Update column
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

    // Input the size of the magic square
    printf("Enter an odd integer for the size of the magic square: ");
    scanf("%d", &n);

    // Validate the input
    if (n % 2 == 0) {
        printf("Size must be an odd integer.\n");
        return 1; // Exit with error code
    }

    // Create and display the magic square
    createMagicSquare(n);

    return 0;
}
