#include "../inc/matrix.h"

int init_matrix(matrix_t &matr)
{
    for (int i = 0; i < dimension + 1; i++)
        for (int j = 0; j < dimension + 1; j++)
            matr.matr[i][j] = (i == j);

    return OK;
}

bool index_is_valid_matrix(const int i, const int j, const int n, const int m)
{
    return !(i >= n + 1 || i < 0 || j >= m + 1 || j < 0);
}

int get_elem_matrix(double &elem, const matrix_t &matr, const int i, const int j)
{
    int rc = OK;

    if (!index_is_valid_matrix(i, j, dimension + 1, dimension + 1))
        rc = IND_OUT_OF_RANGE;
    else
        elem = matr.matr[i][j];

    return rc;
}


int multiply_row_by_column_matrix(double &res, const double (&row)[dimension + 1], const matrix_t &m2, int j)
{
    int rc = OK;

    res = 0;
    for (int k = 0; k < dimension + 1 && rc == OK; k++)
    {
        double a = 0;
        int rc2 = get_elem_matrix(a, m2, k, j);

        if (rc2 == OK)
            res += row[k] * a;
        else
            rc = rc2;
    }

    return rc;
}

int set_elem_matrix(matrix_t &m1, const double val, const int i, const int j)
{
    int rc = OK;

    if (!index_is_valid_matrix(i, j, dimension + 1, dimension + 1))
        rc = IND_OUT_OF_RANGE;
    else
        m1.matr[i][j] = val;

    return rc;
}

int create_scale_matrix(matrix_t &matr, const double kx, const double ky, const double kz)
{
    set_elem_matrix(matr, kx, 0, 0);
    set_elem_matrix(matr, ky, 1, 1);
    set_elem_matrix(matr, kz, 2, 2);

    return OK;
}

int create_move_matrix(matrix_t &matr, const double dx, const double dy, const double dz)
{
    set_elem_matrix(matr, dx, 0, dimension);
    set_elem_matrix(matr, dy, 1, dimension);
    set_elem_matrix(matr, dz, 2, dimension);

    return OK;
}

int create_rotate_x_matrix(matrix_t &matr, const double ax)
{
    init_matrix(matr);

    double angle = pi * ax / 180;

    set_elem_matrix(matr, cos(angle), 1, 1);
    set_elem_matrix(matr, -sin(angle), 1, 2);
    set_elem_matrix(matr, sin(angle), 2, 1);
    set_elem_matrix(matr,cos(angle), 2, 2);

    return OK;
}

int create_rotate_y_matrix(matrix_t &matr, const double ay)
{
    init_matrix(matr);

    double angle = pi * ay / 180;

    set_elem_matrix(matr, cos(angle), 0, 0);
    set_elem_matrix(matr, -sin(angle), 0, 2);
    set_elem_matrix(matr, sin(angle), 2, 0);
    set_elem_matrix(matr,cos(angle), 2, 2);

    return OK;
}

int create_rotate_z_matrix(matrix_t &matr, const double az)
{
    init_matrix(matr);

    double angle = pi * az / 180;

    set_elem_matrix(matr, cos(angle), 0, 0);
    set_elem_matrix(matr, -sin(angle), 0, 1);
    set_elem_matrix(matr, sin(angle), 1, 0);
    set_elem_matrix(matr,cos(angle), 1, 1);

    return OK;
}

int create_rotate_matrix(matrix_t &matrix, const double ax, const double ay, const double az)
{
    matrix_t xrot_matr, yrot_matr, zrot_matr, mtemp;

    init_matrix(mtemp);

    create_rotate_x_matrix(xrot_matr, ax);
    create_rotate_y_matrix(yrot_matr, ay);
    create_rotate_z_matrix(zrot_matr, az);

    multiply_matrices(mtemp, xrot_matr, yrot_matr);
    multiply_matrices(matrix, mtemp, zrot_matr);

    return OK;
}

int multiply_matrices(matrix_t &mres, const matrix_t &m1, const matrix_t &m2)
{
    int rc = OK;

    for (int i = 0; i < dimension + 1; i++)
    {
        for (int j = 0; j < dimension + 1; j++)
        {
            double val = 0;
            multiply_row_by_column_matrix(val, m1.matr[i], m2, j);
            set_elem_matrix(mres, val, i, j);
        }
    }

    return rc;
}
