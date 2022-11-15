#include "matrix.h"
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
//1
typedef struct matrix {
    int w, h;
    int** arr;
} matrix;
//2
matrix fill(int h, int w, int item) {
    matrix a;
    a.w = w;
    a.h = h;
    a.arr = (int**)malloc(sizeof(int*) * a.h);
    for (int i = 0; i < a.h; i++) {
        a.arr[i] = (int*)malloc(sizeof(int) * a.w);
    }
    for (int i = 0; i < a.h; i++) {
        for (int j = 0; j < a.w; j++) {
            a.arr[i][j] = item;
        }
    }
    return a;
}
//3
matrix rand_fill(int h, int w) {
    matrix b;
    b = fill(h, w, 0);
    for (int i = 0; i < b.h; i++) {
        for (int j = 0; j < b.w; j++) {
            b.arr[i][j] = rand() % 10;
        }
    }
    return b;
}
//4.1
matrix mat_sum(matrix a, matrix b) {
    matrix c;
    c = fill(a.h, b.w, 0);
    for (int i = 0; i < c.h; i++) {
        for (int j = 0; j < c.w; j++) {
            c.arr[i][j] = a.arr[i][j] + b.arr[i][j];
        }
    }
    return c;
}
//4.2
matrix mat_sub(matrix a, matrix b) {
    matrix c;
    c = fill(a.h, b.w, 0);
    for (int i = 0; i < c.h; i++) {
        for (int j = 0; j < c.w; j++) {
            c.arr[i][j] = a.arr[i][j] - b.arr[i][j];
        }
    }
    return c;
}
//5.1
matrix mat_multi(matrix a, matrix b) {
    matrix c;
    c = fill(a.h, b.w, 0);
    for (int i = 0; i < c.h; i++) {
        for (int j = 0; j < c.w; j++) {
            c.arr[i][j] = 0;
            for (int k = 0; k < a.w; k++) {
                c.arr[i][j] += a.arr[i][k] * b.arr[k][j];
            }
        }
    }
    return c;
}
//6
matrix mat_tran(matrix b) {
    matrix c;
    c = fill(b.w, b.h, 0);
    printf("%d %d\n", c.w, c.h);
    for (int i = 0; i < c.h; i++) {
        for (int j = 0; j < c.w; j++) {
            c.arr[i][j] = b.arr[j][i];
        }
    }
    return c;
}
//7
void mat_free(matrix c) {
    for (int i = 0; i < c.h; i++)
        free(c.arr[i]);
    free(c.arr);
    printf("\nMemory was cleared\n");
}
//8
matrix mat_copy(matrix b) {
    matrix c;
    c = fill(b.h, b.w, 0);
    for (int i = 0; i < c.h; i++) {
        for (int j = 0; j < c.w; j++) {
            c.arr[i][j] = b.arr[i][j];
        }
    }
    return c;
}
void printmat(matrix b) {
    for (int i = 0; i < b.h; i++) {
        for (int j = 0; j < b.w; j++) {
            printf("%d ", b.arr[i][j]);
        }
        printf("\n");
    }
}
