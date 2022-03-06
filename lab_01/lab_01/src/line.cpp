#include "../inc/line.h"

int init_line(line_t &line)
{
    point_t point1, point2;

    init_point(point1);
    init_point(point2);

    line.point1 = point1;
    line.point2 = point2;

    return OK;
}

bool index_is_valid_line(const int i)
{
    return (i == 0 || i == 1);
}

int get_elem_line(point_t &point, const line_t &line, const int i)
{
    int rc = OK;

    if (!index_is_valid_line(i))
        rc = IND_OUT_OF_RANGE;
    else if (i == 0)
        point = line.point1;
    else
        point = line.point2;

    return rc;
}

int set_line(line_t &line, const point_t &point1, const point_t &point2)
{
    int rc = OK;

    line.point1 = point1;
    line.point2 = point2;

    return rc;
}

int transform_line(line_t &new_line, const line_t &line, const matrix_t &matrix)
{
    int rc = OK;

    point_t point1, point2, new_point1, new_point2;
    get_elem_line(point1, line, 0);
    get_elem_line(point2, line, 1);

    transform_point(new_point1, point1, matrix);
    transform_point(new_point2, point2, matrix);

    set_line(new_line, new_point1, new_point2);

    return rc;
}


