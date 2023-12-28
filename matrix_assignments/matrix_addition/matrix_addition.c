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
