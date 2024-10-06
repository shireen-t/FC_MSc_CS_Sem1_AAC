#include <stdio.h>

#define MAX 10 // Define a maximum size for the matrices

void multiplyMatrices(int a[MAX][MAX], int b[MAX][MAX], int result[MAX][MAX], int rowsA, int colsA, int colsB) {
    // Initialize the result matrix
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            result[i][j] = 0; // Initialize each element to 0
        }
    }

    // Perform matrix multiplication
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            for (int k = 0; k < colsA; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

void printMatrix(int matrix[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int a[MAX][MAX], b[MAX][MAX], result[MAX][MAX];
    int rowsA, colsA, rowsB, colsB;

    // Input dimensions for the first matrix
    printf("Enter rows and columns for the first matrix: ");
    scanf("%d %d", &rowsA, &colsA);

    // Input dimensions for the second matrix
    printf("Enter rows and columns for the second matrix (should be %d for multiplication): ", colsA);
    scanf("%d %d", &rowsB, &colsB);

    // Check if matrices can be multiplied
    if (colsA != rowsB) {
        printf("Error: Number of columns in the first matrix must equal number of rows in the second matrix.\n");
        return 1; // Exit the program with an error code
    }

    // Input the first matrix
    printf("Enter elements of the first matrix:\n");
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsA; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    // Input the second matrix
    printf("Enter elements of the second matrix:\n");
    for (int i = 0; i < rowsB; i++) {
        for (int j = 0; j < colsB; j++) {
            scanf("%d", &b[i][j]);
        }
    }

    // Multiply the matrices
    multiplyMatrices(a, b, result, rowsA, colsA, colsB);

    // Output the result
    printf("Resultant Matrix after multiplication:\n");
    printMatrix(result, rowsA, colsB);

    return 0;
}
