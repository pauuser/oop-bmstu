#include "projection.h"

int project_point(point_t &pout, const point_t &pin)
{
    double new_x = get_y_point(pin) - get_x_point(pin) * sin45;
    double new_y = get_z_point(pin) - get_x_point(pin) * cos45;
    set_point(pout, new_x, -new_y, 0);

    return OK;
}

int project_line(line_t &lout, const line_t &lin)
{
    line_t lout_new;
    init_line(lout_new);

    project_point(lout_new.point1, lin.point1);
    project_point(lout_new.point2, lin.point2);

    lout = lout_new;

    return OK;
}


