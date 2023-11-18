#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int rows, cols;
    int *array;
} Matrix;

Matrix *matrix_constructor(int rows, int cols) {
    Matrix *matrix = malloc(sizeof(Matrix));
    matrix->rows = rows;
    matrix->cols = cols;
    matrix->array = malloc(rows*cols * sizeof(int));
    return matrix;
}

void matrix_destructor(Matrix *m) {
    free(m->array);
    free(m);
}

void fill_matrix(Matrix *m) {
    for (int i = 0; i < m->rows; ++i) {
        printf("Row %d: ", i+1);
        for (int j = 0; j < m->cols; ++j)
            scanf("%d", &m->array[i*m->cols + j]);
    }
}

void print_matrix(Matrix *m) {
    for (int i = 0; i < m->rows; ++i) {
        for (int j = 0; j < m->cols; ++j)
            printf("%d ", m->array[i*m->cols + j]);
        putchar('\n');
    }
}

Matrix *matrix_subtraction(Matrix *a, Matrix *b) {
    if (a->rows == b->rows && a->cols == b->cols) {
        Matrix *diff = matrix_constructor(a->rows, a->cols);
        for (int i = 0; i < a->rows * a->cols; ++i)
            diff->array[i] = a->array[i] - b->array[i];
        return diff;
    }
    printf("Subtraction not possible.\n");
    return matrix_constructor(0, 0);
}

int main()
{
    int rows, cols;
    printf("Dimension of matrix A: ");
    scanf("%d %d", &rows, &cols);
    Matrix *a = matrix_constructor(rows, cols);
    fill_matrix(a);
    printf("Dimension of matrix B: ");
    scanf("%d %d", &rows, &cols);
    Matrix *b = matrix_constructor(rows, cols);
    fill_matrix(b);
    printf("Matrix A-B:\n");
    print_matrix(matrix_subtraction(a, b));
    return 0;
}
