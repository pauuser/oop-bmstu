#include <stdio.h>

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

        if (rc == OK)
        {
            rc = transform_center(model.center, matr);
        }
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

        rc = transform_model(model, move_matr);
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

        rc = transform_model(model, move_matr);
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

        rc = transform_model(model, move_matr);
    }

    return rc;
}

error_t copy_model(model_t &dst, const model_t &model)
{
    error_t rc = OK;

    model_t tmp = init_model();

    rc = copy_pointarr(tmp.points, model.points);

    if (rc == OK)
    {
        rc = copy_linearr(tmp.lines, model.lines);

        if (rc == OK)
        {
            tmp.center = model.center;
            dst = tmp;
        }
    }

    return rc;
}

error_t get_transformed_model(model_t &dst, const model_t &src)
{
    error_t rc = OK;

    model_t tmp = init_model();

    rc = copy_model(tmp, src);

    if (rc == OK)
    {
        rc = get_transformed_points(tmp.points, src.points, src.transform_matrix);

        if (rc == OK)
        {
            tmp.transform_matrix = init_matrix();

            dst = tmp;
        }
    }

    return rc;
}


error_t transform_center(point_t &center, const matrix_t &transform_matr)
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
