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
        for (int j = 0; j < cols; ++j)
            printf("%d ", matrix[i][j]);
        putchar('\n');
    }
}

int **matrix_addition(int **a, int **b, int rows, int cols) {
    int **sum = matrix_constructor(rows, cols);
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j) sum[i][j] = a[i][j] + b[i][j];
    return sum;
}

int main()
{
    int rows, cols;
    printf("Dimension: ");
    scanf("%d %d", &rows, &cols);
    int **a = matrix_constructor(rows, cols);
    printf("Matrix A\n");
    fill_matrix(a, rows, cols);
    int **b = matrix_constructor(rows, cols);
    printf("Matrix B\n");
    fill_matrix(b, rows, cols);
    printf("Matrix A+B:\n");
    print_matrix(matrix_addition(a, b, rows, cols), rows, cols);
    return 0;
}
