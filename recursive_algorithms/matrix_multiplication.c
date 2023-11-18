#include <stdio.h>
#include <stdlib.h>

int **matrix_constructor(int nrows, int ncols) {
    int **matrix = calloc(nrows, sizeof(int *));
    for (int i = 0; i < nrows; ++i) matrix[i] = calloc(ncols, sizeof(int));
    return matrix;
}

void fill_matrix(int **matrix, int nrows, int ncols) {
    for (int i = 0; i < nrows; ++i) {
        printf("Row %d: ", i+1);
        for (int j = 0; j < ncols; ++j) scanf("%d", &matrix[i][j]);
    }
}

void print_matrix(int **matrix, int nrows, int ncols) {
    for (int i = 0; i < nrows; ++i) {
        for (int j = 0; j < ncols; ++j)
            printf("%d ", matrix[i][j]);
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

int single_row_multiplication(
    int **a, int **b,
    int row, int col, int length
) {
    // returns sum of product of individual elements of row and column
    // row: the row number
    // col: the column number
    // length: the length of row and column
    if (length == 1) return a[row][0] * b[0][col];
    return (a[row][length-1] * b[length-1][col]) + single_row_multiplication(a, b, row, col, length-1);
}

void matrix_multiplication_recursive(
    int **result, int **a, int **b,
    int arows, int bcols, int length
) {
    if (arows > 0) {
        if (bcols > 0) {
            // printf("setting result[%d][%d]\n", arows-1, bcols-1);
            result[arows-1][bcols-1] = single_row_multiplication(a, b, arows-1, bcols-1, length);
            // printf("(%d, %d)\n", arows, bcols-1);
            matrix_multiplication_recursive(result, a, b, arows, bcols-1, length);
        }
        // printf("(%d, %d)\n", arows-1, bcols);
        matrix_multiplication_recursive(result, a, b, arows-1, bcols, length);
    }
}

int main()
{
    int arows, acols, bcols;
    printf("Dimension of A: ");
    scanf("%d %d", &arows, &acols);
    int **a = matrix_constructor(arows, acols);
    printf("Matrix A\n");
    fill_matrix(a, arows, acols);
    printf("Column of B: ");
    scanf("%d", &bcols);
    int **b = matrix_constructor(acols, bcols);
    printf("Matrix B\n");
    fill_matrix(b, acols, bcols);

    int **result = matrix_constructor(arows, bcols);

    matrix_multiplication_recursive(result, a, b, arows, bcols, acols);

    printf("\nMatrix product by recursive function\n");
    print_matrix(result, arows, bcols);
    printf("Matrix product\n");
    print_matrix(matrix_multiplication(a, b, arows, acols, bcols), arows, bcols);
    
    return 0;
}
