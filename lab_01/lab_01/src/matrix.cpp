#include "../inc/matrix.h"
#include <stdio.h>

matrix_t init_matrix()
{
    matrix_t matr;

    for (int i = 0; i < dimension + 1; i++)
        for (int j = 0; j < dimension + 1; j++)
            matr.data[i][j] = (i == j);

    return matr;
}

int multiply_row_by_column_matrix(double &res, const double *row, const matrix_t &matr, int j)
{
    int rc = OK;

    res = 0;

    for (int k = 0; k < dimension + 1 && rc == OK; k++)
    {
        res += row[k] * matr.data[k][j];
    }

    return rc;
}

matrix_t create_scale_matrix(const double kx, const double ky, const double kz)
{
    matrix_t matr = init_matrix();

    matr.data[0][0] = kx;
    matr.data[1][1] = ky;
    matr.data[2][2] = kz;

    return matr;
}

matrix_t create_move_matrix(const double dx, const double dy, const double dz)
{    
    matrix_t matr = init_matrix();

    fprintf(stdout, "%f %f %f\n", dx, dy, dz);

    matr.data[0][dimension] = dx;
    matr.data[1][dimension] = dy;
    matr.data[2][dimension] = dz;

    return matr;
}

matrix_t create_rotate_matrix(const double ax, const double ay, const double az)
{
    matrix_t matrix = init_matrix();

    double x = radians(ax), y = radians(ay), z = radians(az);

    matrix.data[0][0] = cos(y) * cos(z);
    matrix.data[0][1] = -cos(y) * sin(z);
    matrix.data[0][2] = -sin(y);

    matrix.data[1][0] = cos(x) * sin(z) - sin(x) * sin(y) * cos(z);
    matrix.data[1][1] = sin(x) * sin(y) * sin(z) + cos(x) * cos(z);
    matrix.data[1][2] = -cos(y) * sin(x);

    matrix.data[2][0] = cos(x) * sin(y) * cos(z) + sin(x) * sin(z);
    matrix.data[2][1] = sin(x) * cos(z) - cos(x) * sin(y) * sin(z);
    matrix.data[2][2] = cos(x) * cos(y);

    matrix.data[3][3] = 1;

    return matrix;
}

int multiply_matrices(matrix_t &mres, const matrix_t &m1, const matrix_t &m2)
{
    int rc = OK;

    for (int i = 0; i < dimension + 1 && rc == OK; i++)
    {
        for (int j = 0; j < dimension + 1 && rc == OK; j++)
        {
            double val = 0;

            rc = multiply_row_by_column_matrix(val, m1.data[i], m2, j);

            if (rc == OK)
            {
                mres.data[i][j] = val;
            }
        }
    }

    return rc;
}

double radians(double angle)
{
    return angle * pi / 180;
}
