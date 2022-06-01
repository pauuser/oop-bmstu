#include "../inc/model.h"

model_t init_model()
{
    model_t model;

    model.points = init_pointarr();

    model.lines = init_linearr();

    model.transform_matrix = init_matrix();

    model.center = init_point();

    return model;
}

void free_model(model_t &model)
{
    free_pointarr(model.points);

    free_linearr(model.lines);

    model.transform_matrix = init_matrix();
}

bool model_exists(const pointarr_t &points, const linearr_t &lines)
{
    bool res = 1;

    if (points.array == NULL || points.n < 1)
    {
        res = 0;
    }
    else if (lines.array == NULL || lines.n < 1)
    {
        res = 0;
    }

    return res;
}

error_t transform_model(model_t &model, const matrix_t &matr)
{
    error_t rc = OK;

    if (model_exists(model.points, model.lines) == 0)
    {
        rc = NO_MODEL;
    }
    else
    {
        rc = multiply_matrices(model.transform_matrix, matr);
    }

    return rc;
}

error_t move_model(model_t &model, const data_t &data)
{
    error_t rc = OK;

    if (model_exists(model.points, model.lines) == 0)
    {
        rc = NO_MODEL;
    }
    else
    {
        matrix_t move_matr = create_move_matrix(data);

        rc = multiply_matrices(model.transform_matrix, move_matr);

        if (rc == OK)
        {
            rc = transform_center_point(model.center, move_matr);
        }
    }

    return rc;
}

error_t scale_model(model_t &model, const data_t &data)
{
    error_t rc = OK;

    if (model_exists(model.points, model.lines) == 0)
    {
        rc = NO_MODEL;
    }
    else
    {
        matrix_t move_matr = create_scale_with_center_matrix(data, model.center);

        rc = multiply_matrices(model.transform_matrix, move_matr);
    }

    return rc;
}

error_t rotate_model(model_t &model, const data_t &data)
{
    error_t rc = OK;

    if (model_exists(model.points, model.lines) == 0)
    {
        rc = NO_MODEL;
    }
    else
    {
        matrix_t move_matr = create_rotate_with_center_matrix(data, model.center);

        rc = multiply_matrices(model.transform_matrix, move_matr);
    }

    return rc;
}

error_t transform_center_point(point_t &center, const matrix_t &transform_matr)
{
    error_t rc = OK;

    point_t new_center = init_point();

    rc = transform_point(new_center, center, transform_matr);

    if (rc == OK)
    {
        center = new_center;
    }

    return rc;
}
