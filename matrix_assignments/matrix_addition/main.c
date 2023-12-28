#include "matrix_addition.c"

#include <stdio.h>

int main()
{
    int rows, cols;
    int **matrixA, **matrixB, **sum_matrix;
    printf("Rows, columns: ");
    scanf("%d %d", &rows, &cols);

    printf("\nMatrix A\n");
    matrixA = create_matrix(rows, cols);
    fill_matrix(matrixA, rows, cols);
    printf("\nMatrix B\n");
    matrixB = create_matrix(rows, cols);
    fill_matrix(matrixB, rows, cols);

    sum_matrix = create_matrix(rows, cols);
    add_matrices(sum_matrix, matrixA, matrixB, 0, 0, rows, cols);
    printf("\nMatrix A+B\n");
    print_matrix(sum_matrix, rows, cols);
    delete_matrix(sum_matrix, rows, cols);
    
    sum_matrix = create_matrix(rows, cols);
    add_matrices_loop(sum_matrix, matrixA, matrixB, rows, cols);
    printf("\nMatrix A+B using loop\n");
    print_matrix(sum_matrix, rows, cols);
    delete_matrix(sum_matrix, rows, cols);

    delete_matrix(matrixA, rows, cols);
    delete_matrix(matrixB, rows, cols);

    return 0;
}
