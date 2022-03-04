#include "point.h"

int init_point(point_t &point)
{
    int rc = OK;

    for (int i = 0; i < dimension + 1; i++)
        point.row[i] = 0;

    return rc;
}

double get_x_point(const point_t &point)
{
    return point.row[0];
}

double get_y_point(const point_t &point)
{
    return point.row[1];
}

double get_z_point(const point_t &point)
{
    return point.row[2];
}

int transform_point(point_t &new_point, const point_t &point, const matrix_t &matrix)
{
    int rc = OK;

    for (int i = 0; i < dimension + 1 && rc == OK; i++)
        rc = multiply_row_by_column_matrix(new_point.row[i], point.row, matrix, i);

    return rc;
}
