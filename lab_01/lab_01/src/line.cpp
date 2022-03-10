#include "../inc/line.h"

line_t init_line()
{
    line_t line;

    line.point1 = 0;
    line.point2 = 0;

    return line;
}


error_t set_line(line_t &line, const int point1, const int point2)
{
    error_t rc = OK;

    line.point1 = point1;
    line.point2 = point2;

    return rc;
}


