#include "../inc/projection.h"

error_t project_point(point_t &pout, const point_t &pin)
{
    error_t rc = OK;

    double new_x = get_y_point(pin) - get_x_point(pin) * sin(radians(45));
    double new_y = get_z_point(pin) - get_x_point(pin) * cos(radians(45));

    set_point(pout, new_x, -new_y, 0);

    return rc;
}

error_t project_points(pointarr_t &points)
{
    error_t rc = OK;

    for (int i = 0; rc == OK && i < points.n; i++)
    {
        rc = project_point(points.array[i], points.array[i]);
    }

    return rc;
}

error_t project_model(model_t &projected_model, const model_t &model)
{
    error_t rc = OK;

    model_t tmp_model = init_model();

    rc = get_transformed_model(tmp_model, model);

    if (rc == OK)
    {
        rc = project_points(tmp_model.points);

        if (rc == OK)
        {
            tmp_model.transform_matrix = init_matrix();
            projected_model = tmp_model;
        }
    }

    return rc;
}

