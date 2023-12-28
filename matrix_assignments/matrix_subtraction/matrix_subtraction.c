#include <stdio.h>
#include <stdlib.h>

int **create_matrix(int rows, int cols)
{
    int **matrix = calloc(rows, sizeof(int *));
    for (int i = 0; i < rows; ++i)
        matrix[i] = calloc(cols, sizeof(int));
    return matrix;
}

void delete_matrix(int **matrix, int rows, int cols)
{
    for (int i = 0; i < rows; ++i)
        free(matrix[i]);
    free(matrix);
}

void fill_matrix(int **matrix, int rows, int cols)
{
    for (int i = 0; i < rows; ++i) {
        printf("Row %d: ", i);
        for (int j = 0; j < cols; ++j)
            scanf("%d", &matrix[i][j]);
    }
}

void print_matrix(int **matrix, int rows, int cols)
{
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j)
            printf("%d ", matrix[i][j]);
        putchar('\n');
    }
}

void sub_matrices_loop(int **result, int **A, int **B, int rows, int cols)
{
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            result[i][j] = A[i][j] - B[i][j];
}

/**
 * @param result
 * The rowsxcols matrix where sum will be stored.
 * @param A
 * One of the rowsxcols matrices to be added.
 * @param B
 * The other rowsxcols matrix to be added.
 * @param x
 * Row number of the top-left most element.
 * Initialized at 0.
 * @param y
 * Column number of the top-left most element.
 * Initialized at 0.
 * @param rows
 * Number of rows to be added from (x, y).
 * @param cols
 * Number of columns to be added from (x, y).
*/
void sub_matrices(int **result, int **A, int **B,
                  int x, int y, int rows, int cols)
{
    if (rows == 1 && cols == 1)
        result[x][y] = A[x][y] - B[x][y];
    else if (rows == 1) {
        sub_matrices(result, A, B, x, y, rows, cols/2);
        sub_matrices(result, A, B, x, y+cols/2, rows, cols-cols/2);
    }
    else if (cols == 1) {
        sub_matrices(result, A, B, x, y, rows/2, cols);
        sub_matrices(result, A, B, x+rows/2, y, rows-rows/2, cols);
    }
    else {
        sub_matrices(result, A, B, x, y, rows/2, cols/2);
        sub_matrices(result, A, B, x+rows/2, y, rows-rows/2, cols/2);
        sub_matrices(result, A, B, x, y+cols/2, rows/2, cols-cols/2);
        sub_matrices(result, A, B, x+rows/2, y+cols/2, rows-rows/2, cols-cols/2);
    }
}
