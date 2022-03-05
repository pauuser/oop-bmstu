#include "projection.h"

int project_point(projected_point_t &pout, const point_t &pin)
{
    pout.x = get_y_point(pin) - get_x_point(pin) * sin30;
    pout.y = get_z_point(pin) - get_x_point(pin) * cos30;

    return OK;
}

int project_line(projected_line_t &pout, const line_t &pin)
{
    project_point(pout.point1, pin.point1);
    project_point(pout.point2, pin.point2);

    return OK;
}

