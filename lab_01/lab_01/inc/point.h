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

int init_point(point_t &point);

double get_x_point(const point_t &point);

double get_y_point(const point_t &point);

double get_z_point(const point_t &point);

bool index_is_valid_point(const int i);

int get_elem_point(double &elem, const point_t &point, const int i);

int set_point(point_t &point, const double x, const double y, const double z);

int set_elem_point(point_t &point, const double elem, const int i);

int transform_point(point_t &new_point, const point_t &point, const matrix_t &matrix);

int find_point_in_mas(const point_t &point, const point_t *points, const int n);

bool points_match(const point_t &point1, const point_t &point2);

#endif // POINT_H
