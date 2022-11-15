#pragma once

typedef struct matrix matrix;

matrix fill(int w, int h, int item);

matrix rand_fill(int w, int h);

matrix mat_sum(matrix a, matrix b);

matrix mat_sub(matrix a, matrix b);

matrix mat_multi(matrix a, matrix b);

matrix mat_tran(matrix b);

void mat_free(matrix c);

matrix mat_copy(matrix b);

void printmat(matrix b);
