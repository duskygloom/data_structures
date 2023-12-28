#include "matrix_multiplication.c"

#include <stdio.h>

int main()
{
    int rows;
    int **matrixA, **matrixB, **prod_matrix;
    printf("Rows = 2^i, i: ");
    scanf("%d", &rows);
    rows = pow2(rows);

    printf("\nMatrix A\n");
    matrixA = create_sqmatrix(rows);
    fill_sqmatrix(matrixA, rows);
    printf("\nMatrix B\n");
    matrixB = create_sqmatrix(rows);
    fill_sqmatrix(matrixB, rows);

    prod_matrix = create_sqmatrix(rows);
    multiply_matrices(prod_matrix, 0, 0, matrixA, 0, 0, matrixB, 0, 0, rows);
    printf("\nMatrix A*B\n");
    print_sqmatrix(prod_matrix, rows);
    delete_sqmatrix(prod_matrix, rows);

    prod_matrix = create_sqmatrix(rows);
    multiply_matrices_loop(prod_matrix, matrixA, matrixB, rows);
    printf("\nMatrix A*B using loop\n");
    print_sqmatrix(prod_matrix, rows);
    delete_sqmatrix(prod_matrix, rows);

    delete_sqmatrix(matrixA, rows);
    delete_sqmatrix(matrixB, rows);

    return 0;
}
