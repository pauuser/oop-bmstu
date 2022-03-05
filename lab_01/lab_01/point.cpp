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

bool index_is_valid_point(const int i)
{
    return !(i >= dimension + 1);
}

int get_elem_point(double &elem, const point_t &point, const int i)
{
    int rc = OK;

    if (!index_is_valid_point(i))
        rc = IND_OUT_OF_RANGE;
    else
        elem = point.row[i];

    return rc;
}

int set_elem_point(point_t &point, const double &elem, const int i)
{
    int rc = OK;

    if (!index_is_valid_point(i))
        rc = IND_OUT_OF_RANGE;
    else
        point.row[i] = elem;

    return rc;
}

// подумать над тем что делать если данные испортились посередине...
// обернуть точку - сделать обёртку
int transform_point(point_t &new_point, const point_t &point, const matrix_t &matrix)
{
    int rc = OK;

    for (int i = 0; i < dimension + 1 && rc == OK; i++)
    {
        double val = 0;
        for (int j = 0; j < dimension + 1 && rc == OK; j++)
        {
            double matr_elem = 0.0, point_elem = 0.0;

            if (get_elem_matrix(matr_elem, matrix, i, j) || get_elem_point(point_elem, point, j))
                rc = IND_OUT_OF_RANGE;
            else
                val += matr_elem * point_elem;
        }
        set_elem_point(new_point, val, i);
    }

    return rc;
}
