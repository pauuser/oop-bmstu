#ifndef MATRIX_H
#define MATRIX_H

#include "errors.h"
#include "math.h"

const int dimension = 3;
const double pi = acos(-1);

/*
Структура хранения матрицы преобразований
*/
typedef struct matrix_t matrix_t;

struct matrix_t
{
    double  matr[dimension + 1][dimension + 1];
};

int init_matrix(matrix_t &matr);

bool index_is_valid_matrix(const int i, const int j, const int n, const int m);

int get_elem_matrix(double &elem, const matrix_t &matr, const int i, const int j);

int multiply_row_by_column_matrix(double &res, const double (&row)[dimension + 1], const matrix_t &m2, int j);

int set_value_matrix(matrix_t &m1, const double val, const int i, const int j);

int multiply_matrices(matrix_t &mres, const matrix_t &m1, const matrix_t &m2);


#endif // MATRIX_H
