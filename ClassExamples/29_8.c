// 8. Write an algorithm addition of 2 matrices.

#include <stdio.h>

#define MAX 10 // Define a maximum size for the matrices

void addMatrices(int a[MAX][MAX], int b[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    // Loop through each element to perform the addition
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = a[i][j] + b[i][j];
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
    int rows, cols;

    // Input the dimensions of the matrices
    printf("Enter the number of rows and columns (max %d): ", MAX);
    scanf("%d %d", &rows, &cols);

    // Input the first matrix
    printf("Enter elements of the first matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    // Input the second matrix
    printf("Enter elements of the second matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &b[i][j]);
        }
    }

    // Add the matrices
    addMatrices(a, b, result, rows, cols);

    // Output the result
    printf("Resultant Matrix after addition:\n");
    printMatrix(result, rows, cols);

    return 0;
}
