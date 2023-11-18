#include <stdio.h>
#include <stdlib.h>

int **matrix_constructor(int rows, int cols) {
    int **matrix = calloc(rows, sizeof(int *));
    for (int i = 0; i < rows; ++i) matrix[i] = calloc(cols, sizeof(int));
    return matrix;
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

void matrix_addition_recursive(
    int **result, int **a, int **b, 
    int x, int rows, int y, int cols
) {
    if (rows == 1 && cols == 1) {
        result[x][y] = a[x][y] + b[x][y];
        // printf("\na[%d][%d] = %d\n", x, y, a[x][y]);
        // printf("b[%d][%d] = %d\n", x, y, b[x][y]);
        // printf("result[%d][%d] = %d\n", x, y, result[x][y]);
    } else if (rows == 1) {
        matrix_addition_recursive(result, a, b, x, rows, y, cols/2);
        matrix_addition_recursive(result, a, b, x, rows, y+cols/2, cols-(cols/2));
    } else if (cols == 1) {
        matrix_addition_recursive(result, a, b, x, rows/2, y, cols);
        matrix_addition_recursive(result, a, b, x+rows/2, rows-(rows/2), y, cols);
    } else {
        matrix_addition_recursive(result, a, b, x, rows/2, y, cols/2);
        matrix_addition_recursive(result, a, b, x+rows/2, rows-(rows/2), y, cols);
        matrix_addition_recursive(result, a, b, x, rows, y+cols/2, cols-(cols/2));
        matrix_addition_recursive(result, a, b, x+rows/2, rows-(rows/2), y+cols/2, cols-(cols/2));
    }
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

    int **result = matrix_constructor(rows, cols);

    matrix_addition_recursive(result, a, b, 0, rows, 0, cols);

    printf("\nMatrix sum by recursive function\n");
    print_matrix(result, rows, cols);
    printf("Matrix sum\n");
    print_matrix(matrix_addition(a, b, rows, cols), rows, cols);
    
    return 0;
}