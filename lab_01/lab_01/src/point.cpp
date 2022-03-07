#include "../inc/point.h"

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

int set_elem_point(point_t &point, const double elem, const int i)
{
    int rc = OK;

    if (!index_is_valid_point(i))
        rc = IND_OUT_OF_RANGE;
    else
        point.row[i] = elem;

    return rc;
}

int set_point(point_t &point, const double x, const double y, const double z)
{
    int rc = OK;

    set_elem_point(point, x, 0);
    set_elem_point(point, y, 1);
    set_elem_point(point, z, 2);
    set_elem_point(point, 1, 3);

    return rc;
}

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

bool points_match(const point_t &point1, const point_t &point2)
{
    bool ans = 0;

    double x1 = get_x_point(point1), y1 = get_y_point(point1), z1 = get_z_point(point1);
    double x2 = get_x_point(point2), y2 = get_y_point(point2), z2 = get_z_point(point2);

    if (x1 == x2 && y1 == y2 && z1 == z2)
        ans = 1;

    return ans;
}

int find_point_in_mas(const point_t &point, const point_t *points, const int n)
{
    int ans = -1;

    for (int i = 0; i < n && ans == -1; i++)
        if (points_match(point, points[i]))
            ans = i;

    return ans;
}


