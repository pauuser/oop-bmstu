#include "../inc/projection.h"

int project_point(point_t &pout, const point_t &pin)
{
    double new_x = get_y_point(pin) - get_x_point(pin) * sin45;
    double new_y = get_z_point(pin) - get_x_point(pin) * cos45;

    set_point(pout, new_x, -new_y, 0);

    return OK;
}


