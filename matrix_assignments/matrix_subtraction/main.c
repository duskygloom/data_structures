#include "matrix_subtraction.c"

#include <stdio.h>

int main()
{
    int rows, cols;
    int **matrixA, **matrixB, **diff_matrix;
    printf("Rows, columns: ");
    scanf("%d %d", &rows, &cols);

    printf("\nMatrix A\n");
    matrixA = create_matrix(rows, cols);
    fill_matrix(matrixA, rows, cols);
    printf("\nMatrix B\n");
    matrixB = create_matrix(rows, cols);
    fill_matrix(matrixB, rows, cols);

    diff_matrix = create_matrix(rows, cols);
    sub_matrices(diff_matrix, matrixA, matrixB, 0, 0, rows, cols);
    printf("\nMatrix A-B\n");
    print_matrix(diff_matrix, rows, cols);
    delete_matrix(diff_matrix, rows, cols);

    diff_matrix = create_matrix(rows, cols);
    sub_matrices_loop(diff_matrix, matrixA, matrixB, rows, cols);
    printf("\nMatrix A-B using loop\n");
    print_matrix(diff_matrix, rows, cols);
    delete_matrix(diff_matrix, rows, cols);

    delete_matrix(matrixA, rows, cols);
    delete_matrix(matrixB, rows, cols);

    return 0;
}
