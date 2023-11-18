#include <stdio.h>
#include <stdlib.h>

int **matrix_constructor(int rows, int cols) {
    int **matrix = calloc(rows, sizeof(int *));
    for (int i = 0; i < rows; ++i) matrix[i] = calloc(cols, sizeof(int));
    return matrix;
}

void matrix_destructor(int **matrix, int rows) {
    for (int i = 0; i < rows; ++i) free(matrix[i]);
    free(matrix);
}

void fill_matrix(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        printf("Row %d: ", i+1);
        for (int j = 0; j < cols; ++j) scanf("%d", &matrix[i][j]);
    }
}

void print_matrix(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) printf("%d ", matrix[i][j]);
        putchar('\n');
    }
}

int **matrix_multiplication(int **a, int **b, int rows, int length, int cols) {
    // length = cols(a) = rows(b)
    int **prod = matrix_constructor(rows, cols);
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            for (int k = 0; k < length; ++k) prod[i][j] += a[i][k] * b[k][j];
    return prod;
}

int main()
{
    int rows, cols, length;
    printf("Dimension of matrix A: ");
    scanf("%d %d", &rows, &length);
    int **a = matrix_constructor(rows, length);
    fill_matrix(a, rows, length);
    printf("Columns of matrix B: ");
    scanf("%d", &cols);
    int **b = matrix_constructor(length, cols);
    fill_matrix(b, length, cols);
    printf("Matrix A*B:\n");
    print_matrix(matrix_multiplication(a, b, rows, length, cols), rows, cols);
    return 0;
}
