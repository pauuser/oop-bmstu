#ifndef MATRIX_H
#define MATRIX_H

#include "errors.h"
#include "math.h"

const int dimension = 3;
static const double pi = acos(-1);

/*
Структура хранения матрицы преобразований
*/
typedef struct matrix_t matrix_t;

struct matrix_t
{
    double data[dimension + 1][dimension + 1];
};

matrix_t init_matrix();

int multiply_row_by_column_matrix(double &res, const double *row, const matrix_t &matr, int j);

matrix_t create_scale_matrix(const double kx, const double ky, const double kz);

matrix_t create_move_matrix(const double dx, const double dy, const double dz);

matrix_t create_rotate_matrix(const double ax, const double ay, const double az);

int multiply_matrices(matrix_t &mres, const matrix_t &m1, const matrix_t &m2);

double radians(double angle);

#endif // MATRIX_H
