#include <stdio.h>

#include "../inc/model.h"

model_t init_model()
{
    model_t model;

    model.n = 0;
    model.points = NULL;

    model.m = 0;
    model.lines = NULL;

    model.transform_matrix = init_matrix();

    return model;
}

void free_model(model_t &model)
{
    model.n = 0;
    free(model.points);
    model.points = NULL;

    model.m = 0;
    free(model.points);
    model.points = NULL;

    model.transform_matrix = init_matrix();
}

int transform_model(model_t &model, const matrix_t &matr)
{
    int rc = OK;

    if (model.n == 0)
    {
        rc = NO_MODEL;
    }
    else
    {
        matrix_t mres = init_matrix();

        int rc = multiply_matrices(mres, model.transform_matrix, matr);

        if (rc == OK)
        {
            model.transform_matrix = mres;
        }
        fprintf(stdout, "------- %d\n", rc);
        for (int i = 0; i < dimension + 1; i++)
        {
            for (int j = 0; j < dimension + 1; j++)
                fprintf(stdout, "%f ", mres.data[i][j]);
            fprintf(stdout, "\t");
            for (int j = 0; j < dimension + 1; j++)
                fprintf(stdout, "%f ", matr.data[i][j]);
            fprintf(stdout, "\n");
        }
    }

    return rc;
}

int move_model(model_t &model, data_t &data)
{
    int rc = OK;

    if (model.n == 0)
    {
        rc = NO_MODEL;
    }
    else
    {
        double dx = data.cx, dy = data.cy, dz = data.cz;

        fprintf(stdout, "HERE!!!!\n");

        matrix_t move_matr = create_move_matrix(dx, dy, dz);

        rc = transform_model(model, move_matr);
    }

    return rc;
}

int scale_model(model_t &model, data_t &data)
{
    int rc = OK;

    if (model.n == 0)
    {
        rc = NO_MODEL;
    }
    else
    {
        double kx = data.cx, ky = data.cy, kz = data.cz;

        matrix_t move_matr = create_scale_matrix(kx, ky, kz);

        rc = transform_model(model, move_matr);
    }

    return rc;
}

int rotate_model(model_t &model, data_t &data)
{
    int rc = OK;

    if (model.n == 0)
    {
        rc = NO_MODEL;
    }
    else
    {
        double ax = data.cx, ay = data.cy, az = data.cz;

        matrix_t move_matr = create_rotate_matrix(ax, ay, az);

        rc = transform_model(model, move_matr);
    }

    return rc;
}

