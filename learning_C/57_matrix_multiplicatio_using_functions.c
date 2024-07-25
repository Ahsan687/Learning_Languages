#include <stdio.h>

void inputMatrix(float matrix[][10], int rows, int cols, int matrixNum) {
    printf("Enter the elements of matrix %d:\n", matrixNum);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Enter value of matrix%d[%d][%d]: ", matrixNum, i, j);
            scanf("%f", &matrix[i][j]);
        }
    }
}

void multiplyMatrices(float m1[][10], int r1, int c1, float m2[][10], int r2, int c2, float product[][10]) {
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            product[i][j] = 0;
            for (int k = 0; k < c1; k++) {
                product[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
}

void printMatrix(float matrix[][10], int rows, int cols) {
    printf("Resultant matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%8.2f ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int r1, c1, r2, c2;

    // Input dimensions of the matrices
    printf("Enter the dimensions of matrix 1 (rows columns): ");
    scanf("%d %d", &r1, &c1);
    printf("Enter the dimensions of matrix 2 (rows columns): ");
    scanf("%d %d", &r2, &c2);

    // Check if multiplication is possible
    if (c1 != r2) {
        printf("Matrix multiplication not possible with given dimensions.\n");
        return 1;
    }

    float m1[10][10], m2[10][10], product[10][10];

    // Input matrices
    inputMatrix(m1, r1, c1, 1);
    inputMatrix(m2, r2, c2, 2);

    // Multiply matrices
    multiplyMatrices(m1, r1, c1, m2, r2, c2, product);

    // Print the product matrix
    printMatrix(product, r1, c2);

    return 0;
}
