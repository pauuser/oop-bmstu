#include "../inc/point.h"

point_t init_point()
{
    point_t point;

    for (int i = 0; i < dimension + 1; i++)
    {
        point.row[i] = 0;
    }

    return point;
}

pointarr_t init_pointarr()
{
    pointarr_t points;

    points.n = 0;
    points.array = NULL;

    return points;
}

void free_pointarr(pointarr_t &points)
{
    points.n = 0;

    free(points.array);

    points.array = NULL;
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

error_t get_elem_point(double &elem, const point_t &point, const int i)
{
    error_t rc = OK;

    if (!index_is_valid_point(i))
    {
        rc = IND_OUT_OF_RANGE;
    }
    else
    {
        elem = point.row[i];
    }

    return rc;
}

error_t set_elem_point(point_t &point, const double elem, const int i)
{
    error_t rc = OK;

    if (!index_is_valid_point(i))
    {
        rc = IND_OUT_OF_RANGE;
    }
    else
    {
        point.row[i] = elem;
    }

    return rc;
}

error_t set_point(point_t &point, const double x, const double y, const double z)
{
    error_t rc = OK;

    set_elem_point(point, x, 0);
    set_elem_point(point, y, 1);
    set_elem_point(point, z, 2);
    set_elem_point(point, 1, 3);

    return rc;
}

error_t create_points_mas(pointarr_t &points, const int n)
{
    error_t rc = OK;

    if (n < 1)
    {
        rc = INAPPROPRIATE_INPUT;
    }
    else
    {
        point_t *tmp = (point_t *)malloc(sizeof(point_t) * n);

        if (tmp == NULL)
        {
            rc = NO_MEMORY;
        }
        else
        {
            points.n = n;

            points.array = tmp;
        }
    }

    return rc;
}

error_t copy_pointarr(pointarr_t &dst, const pointarr_t &src)
{
    error_t rc = OK;

    pointarr_t tmp = init_pointarr();

    rc = create_points_mas(tmp, get_pointarr_n(src));

    if (rc == OK)
    {
        rc = copy_elements_pointarr(tmp, src);

        dst = tmp;
    }

    return rc;
}

error_t copy_elements_pointarr(pointarr_t &dst, const pointarr_t &src)
{
    error_t rc = OK;

    dst.n = src.n;

    for (int i = 0; i < src.n; i++)
    {
        dst.array[i] = src.array[i];
    }

    return rc;
}

error_t move_point(point_t &point, const data_t &data)
{
    error_t rc = OK;

    double dx = data.cx, dy = data.cy, dz = data.cz;

    double x = get_x_point(point) + dx;
    double y = get_y_point(point) + dy;
    double z = get_z_point(point) + dz;

    rc = set_point(point, x, y, z);

    return rc;
}

int get_pointarr_n(const pointarr_t &points)
{
    return points.n;
}



