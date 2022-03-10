#ifndef POINT_H
#define POINT_H

#include <stdlib.h>

#include "errors.h"
#include "matrix.h"

/*
Структура для хранения точки
Координаты - вещественные числа
*/
typedef struct point_t point_t;

struct point_t
{
    double row[dimension + 1];
};

point_t init_point();

double get_x_point(const point_t &point);

double get_y_point(const point_t &point);

double get_z_point(const point_t &point);

bool index_is_valid_point(const int i);

error_t get_elem_point(double &elem, const point_t &point, const int i);

error_t set_point(point_t &point, const double x, const double y, const double z);

error_t set_elem_point(point_t &point, const double elem, const int i);

error_t transform_point(point_t &new_point, const point_t &point, const matrix_t &matrix);

bool points_match(const point_t &point1, const point_t &point2);

error_t find_point_in_mas(const point_t &point, const point_t *points, const int n);

bool points_match(const point_t &point1, const point_t &point2);

#endif // POINT_H
