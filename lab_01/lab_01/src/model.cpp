#include <stdio.h>

#include "model.h"

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
    matrix_t mres;
    init_matrix(mres);

    multiply_matrices(mres, model.transform_matrix, matr);
    model.transform_matrix = mres;

    return OK;
}

int move_model(model_t &model, const double dx, const double dy, const double dz)
{
    matrix_t move_matr;
    init_matrix(move_matr);

    create_move_matrix(move_matr, dx, dy, dz);
    transform_model(model, move_matr);

    return OK;
}

int scale_model(model_t &model, const double kx, const double ky, const double kz)
{
    matrix_t move_matr;
    init_matrix(move_matr);

    create_scale_matrix(move_matr, kx, ky, kz);
    transform_model(model, move_matr);

    return OK;
}

int rotate_model(model_t &model, const double ax, const double ay, const double az)
{
    matrix_t move_matr;
    init_matrix(move_matr);

    create_rotate_matrix(move_matr, ax, ay, az);
    transform_model(model, move_matr);

    return OK;
}

