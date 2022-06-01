#ifndef MATRIX_H
#define MATRIX_H

#define _USE_MATH_DEFINES
#include <cmath>

#include <math.h>

#include "errors.h"
#include "point.h"
#include "request.h"


typedef struct matrix_t matrix_t;

struct matrix_t
{
    double data[dimension + 1][dimension  + 1];
};

matrix_t init_matrix();

error_t multiply_row_by_column_matrix(double &res, const matrix_t &mrow, const int row, const matrix_t &mcol, const int col);

matrix_t create_scale_matrix(const data_t &data);

matrix_t create_move_matrix(const data_t &data);

matrix_t create_rotate_matrix(const data_t &data);

error_t multiply_matrices(matrix_t &m1, const matrix_t &m2);

double radians(double angle);

error_t get_transformed_points(pointarr_t &dst, const pointarr_t &src, const matrix_t &transform_matrix);

error_t transform_point(point_t &new_point, const point_t &point, const matrix_t &matrix);

matrix_t create_move_to_center_matrix(const point_t &center);

matrix_t create_move_from_center_matrix(const point_t &center);

data_t create_move_to_center_data(const point_t &point);

data_t create_move_from_center_data(const point_t &point);

matrix_t create_rotate_with_center_matrix(const data_t &data, const point_t &center);

matrix_t create_scale_with_center_matrix(const data_t &data, const point_t &center);

error_t set_elem_matrix(matrix_t &mtr, const int i, const int j, const double val);

error_t transform_points(pointarr_t &dst, const pointarr_t &src, const matrix_t transform_matrix);

#endif // MATRIX_H
