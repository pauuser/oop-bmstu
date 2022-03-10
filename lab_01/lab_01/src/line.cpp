#include "../inc/line.h"

line_t init_line()
{
    line_t line;

    line.point1 = 0;
    line.point2 = 0;

    return line;
}


int set_line(line_t &line, const int point1, const int point2)
{
    int rc = OK;

    line.point1 = point1;
    line.point2 = point2;

    return rc;
}


