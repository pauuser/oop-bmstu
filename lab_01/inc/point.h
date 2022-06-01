#ifndef POINT_H
#define POINT_H

#include <stdlib.h>

#include "errors.h"
#include "request.h"

typedef struct point_t point_t;

struct point_t
{
    double row[dimension + 1];
};

typedef struct pointarr_t pointarr_t;

struct pointarr_t
{
    int n;
    point_t *array;
};

point_t init_point();

pointarr_t init_pointarr();

void free_pointarr(pointarr_t &points);

double get_x_point(const point_t &point);

double get_y_point(const point_t &point);

double get_z_point(const point_t &point);

bool index_is_valid_point(const int i);

error_t get_elem_point(double &elem, const point_t &point, const int i);

error_t set_point(point_t &point, const double x, const double y, const double z);

error_t set_elem_point(point_t &point, const double elem, const int i);

bool points_match(const point_t &point1, const point_t &point2);

error_t find_point_in_mas(const point_t &point, const point_t *points, const int n);

bool points_match(const point_t &point1, const point_t &point2);

error_t copy_pointarr(pointarr_t &dst, const pointarr_t &src);

error_t create_points_mas(pointarr_t &points, const int n);

error_t move_point(point_t &point, const data_t &data);

int get_pointarr_n(const pointarr_t &points);

error_t copy_elements_pointarr(pointarr_t &dst, const pointarr_t &src);

#endif // POINT_H
