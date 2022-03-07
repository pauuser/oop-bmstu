#include <stdio.h>

#include "../inc/model.h"

void init_model(model_t &model)
{
    model.n = 0;
    model.points = NULL;

    model.m = 0;
    model.lines = NULL;

    init_matrix(model.transform_matrix);
}

void free_model(model_t &model)
{
    model.n = 0;
    free(model.points);
    model.points = NULL;

    model.m = 0;
    free(model.points);
    model.points = NULL;

    init_matrix(model.transform_matrix);
}

int transform_model(model_t &model, const matrix_t &matr)
{
    int rc = OK;

    if (model.n == 0)
        rc = NO_MODEL;
    else
    {
        matrix_t mres;
        init_matrix(mres);

        multiply_matrices(mres, model.transform_matrix, matr);
        model.transform_matrix = mres;
    }

    return rc;
}

int move_model(model_t &model, const double dx, const double dy, const double dz)
{
    int rc = OK;

    if (model.n == 0)
        rc = NO_MODEL;
    else
    {
        matrix_t move_matr;
        init_matrix(move_matr);

        create_move_matrix(move_matr, dx, dy, dz);
        transform_model(model, move_matr);
    }

    return rc;
}

int scale_model(model_t &model, const double kx, const double ky, const double kz)
{
    int rc = OK;

    if (model.n == 0)
        rc = NO_MODEL;
    else
    {
        matrix_t move_matr;
        init_matrix(move_matr);

        create_scale_matrix(move_matr, kx, ky, kz);
        transform_model(model, move_matr);
    }

    return rc;
}

int rotate_model(model_t &model, const double ax, const double ay, const double az)
{
    int rc = OK;

    if (model.n == 0)
        rc = NO_MODEL;
    else
    {
        matrix_t move_matr;
        init_matrix(move_matr);

        create_rotate_matrix(move_matr, ax, ay, az);
        transform_model(model, move_matr);
    }

    return rc;
}

