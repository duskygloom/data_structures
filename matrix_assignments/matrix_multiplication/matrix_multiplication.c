#include <stdio.h>
#include <stdlib.h>

int pow2(int x)
{
    int value = 1;
    for (int i = 0; i < x; ++i) value *= 2;
    return value;
}

int **create_sqmatrix(int rows)
{
    int **matrix = calloc(rows, sizeof(int *));
    for (int i = 0; i < rows; ++i)
        matrix[i] = calloc(rows, sizeof(int));
    return matrix;
}

void delete_sqmatrix(int **matrix, int rows)
{
    for (int i = 0; i < rows; ++i)
        free(matrix[i]);
    free(matrix);
}

void fill_sqmatrix(int **matrix, int rows)
{
    for (int i = 0; i < rows; ++i) {
        printf("Row %d: ", i);
        for (int j = 0; j < rows; ++j)
            scanf("%d", &matrix[i][j]);
    }
}

void print_sqmatrix(int **matrix, int rows)
{
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < rows; ++j)
            printf("%d ", matrix[i][j]);
        putchar('\n');
    }
}

void multiply_matrices_loop(int **result, int **A, int **B, 
                            int rows)
{
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < rows; ++j)
            for (int k = 0; k < rows; ++k)
                result[i][j] += A[i][k] * B[k][j];
}

/**
 * @note
 * R00 = A00.B00 + A01.B10
 * R01 = A00.B01 + A01.B11
 * R10 = A10.B00 + A11.B10
 * R11 = A10.B01 + A11.B11
 * @note
 * X00 = X(x, y)
 * X01 = X(x, y+n/2)
 * X10 = X(x+n/2, y)
 * X11 = X(x+n/2, y+n/2)
 * @note
 * Only works for square matrices with rows
 * as a power of 2.
 * @param result
 * nxn matrix where product will be stored.
 * (rx, ry) is the top-left most point.
 * @param A
 * nxn matrix where first operand is stored.
 * (ax, ay) is the top-left most point.
 * @param B
 * nxn matrix where second operand is stored.
 * (bx, by) is the top-left most point.
 * @param n
 * n rows and columns from the top-left most point
 * make up the sub-matrix.
*/
void multiply_matrices(int **result, int rx, int ry,
                       int **A, int ax, int ay,
                       int **B, int bx, int by, int n)
{
    if (n == 1) result[rx][ry] += A[ax][ay] * B[bx][by];
    else {
        multiply_matrices(result, rx, ry, A, ax, ay, B, bx, by, n/2);
        multiply_matrices(result, rx, ry, A, ax, ay+n/2, B, bx+n/2, by, n/2);
        multiply_matrices(result, rx, ry+n/2, A, ax, ay, B, bx, by+n/2, n/2);
        multiply_matrices(result, rx, ry+n/2, A, ax, ay+n/2, B, bx+n/2, by+n/2, n/2);
        multiply_matrices(result, rx+n/2, ry, A, ax+n/2, ay, B, bx, by, n/2);
        multiply_matrices(result, rx+n/2, ry, A, ax+n/2, ay+n/2, B, bx+n/2, by, n/2);
        multiply_matrices(result, rx+n/2, ry+n/2, A, ax+n/2, ay, B, bx, by+n/2, n/2);
        multiply_matrices(result, rx+n/2, ry+n/2, A, ax+n/2, ay+n/2, B, bx+n/2, by+n/2, n/2);
    }
}
