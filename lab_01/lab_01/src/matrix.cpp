#include "../inc/matrix.h"

matrix_t init_matrix()
{
    matrix_t matr;

    for (int i = 0; i < dimension + 1; i++)
        for (int j = 0; j < dimension + 1; j++)
            matr.data[i][j] = (i == j);

    return matr;
}

error_t multiply_row_by_column_matrix(double &res, const matrix_t &mrow, const int row,
                                                   const matrix_t &mcol, const int col)
{
    error_t rc = OK;

    res = 0;

    for (int k = 0; rc == OK && k < dimension + 1; k++)
    {
        res += mrow.data[row][k] * mcol.data[k][col];
    }

    return rc;
}

matrix_t create_scale_matrix(const data_t &data)
{
    matrix_t matr = init_matrix();

    double kx = data.cx, ky = data.cy, kz = data.cz;

    matr.data[0][0] = kx;
    matr.data[1][1] = ky;
    matr.data[2][2] = kz;

    return matr;
}

matrix_t create_move_matrix(const data_t &data)
{    
    matrix_t matr = init_matrix();

    double dx = data.cx, dy = data.cy, dz = data.cz;

    matr.data[0][dimension] = dx;
    matr.data[1][dimension] = dy;
    matr.data[2][dimension] = dz;

    return matr;
}

matrix_t create_rotate_matrix(const data_t &data)
{
    matrix_t matrix = init_matrix();

    double ax = data.cx, ay = data.cy, az = data.cz;

    double x = radians(ax), y = radians(ay), z = radians(az);

    matrix.data[0][0] = cos(y) * cos(z);
    matrix.data[0][1] = -cos(y) * sin(z);
    matrix.data[0][2] = sin(y);

    matrix.data[1][0] = sin(x) * sin(y) * cos(z) + cos(x) * sin(z);
    matrix.data[1][1] = cos(x) * cos(z) - sin(x) * sin(y) * sin(z);
    matrix.data[1][2] = -sin(x) * cos(y);

    matrix.data[2][0] = sin(x) * sin(z) - cos(x) * sin(y) * cos(z);
    matrix.data[2][1] = cos(x) * sin(y) * sin(z) + sin(x) * cos(z);
    matrix.data[2][2] = cos(x) * cos(y);

    return matrix;
}

matrix_t create_rotate_with_center_matrix(const data_t &data, const point_t &center)
{
    matrix_t m_tocenter = create_move_to_center_matrix(center);

    matrix_t rotate_matr = create_rotate_matrix(data);

    matrix_t m_fromcenter = create_move_from_center_matrix(center);

    multiply_matrices(m_tocenter, rotate_matr);
    multiply_matrices(m_tocenter, m_fromcenter);

    return m_tocenter;
}

matrix_t create_scale_with_center_matrix(const data_t &data, const point_t &center)
{
    matrix_t m_tocenter = create_move_to_center_matrix(center);

    matrix_t scale_matr = create_scale_matrix(data);

    matrix_t m_fromcenter = create_move_from_center_matrix(center);

    multiply_matrices(m_tocenter, scale_matr);
    multiply_matrices(m_tocenter, m_fromcenter);

    return m_tocenter;
}

error_t multiply_matrices(matrix_t &m1, const matrix_t &m2)
{
    error_t rc = OK;

    matrix_t mres = m1;

    for (int i = 0; rc == OK && i < dimension + 1; i++)
    {
        for (int j = 0; rc == OK && j < dimension + 1; j++)
        {
            double val = 0;

            rc = multiply_row_by_column_matrix(val, m1, i, m2, j);

            if (rc == OK)
            {
                set_elem_matrix(mres, i, j, val);
            }
        }
    }

    if (rc == OK)
    {
        m1 = mres;
    }

    return rc;
}

error_t set_elem_matrix(matrix_t &mtr, const int i, const int j, const double val)
{
    error_t rc = OK;

    if (i < 0 || j < 0 || i > dimension || j > dimension)
    {
        rc = IND_OUT_OF_RANGE;
    }
    else
    {
        mtr.data[i][j] = val;
    }

    return rc;
}

double radians(double angle)
{
    return angle * M_PI / 180;
}

error_t get_transformed_points(pointarr_t &dst, const pointarr_t &src, const matrix_t &transform_matrix)
{
    error_t rc = OK;

    pointarr_t tmp = init_pointarr();

    rc = copy_pointarr(tmp, src);

    if (rc == OK)
    {
        rc = transform_points(tmp, src, transform_matrix);

        if (rc == OK)
        {
            dst = tmp;
        }
        else
        {
            free_pointarr(tmp);
        }
    }

    return rc;
}

error_t transform_points(pointarr_t &dst, const pointarr_t &src, const matrix_t transform_matrix)
{
    error_t rc = OK;

    for (int i = 0; rc == OK && i < dst.n; i++)
    {
        rc = transform_point(dst.array[i], src.array[i], transform_matrix);
    }

    return rc;
}

error_t transform_point(point_t &new_point, const point_t &point, const matrix_t &matrix)
{
    error_t rc = OK;

    for (int i = 0; rc == OK && i < dimension + 1; i++)
    {
        double val = 0;
        for (int j = 0; rc == OK && j < dimension + 1; j++)
        {
            double matr_elem = matrix.data[i][j], point_elem = 0.0;

            rc = get_elem_point(point_elem, point, j);

            if (rc == OK)
            {
                val += matr_elem * point_elem;
            }
        }
        set_elem_point(new_point, val, i);
    }

    return rc;
}

matrix_t create_move_to_center_matrix(const point_t &center)
{
    data_t data = create_move_to_center_data(center);

    matrix_t matr = create_move_matrix(data);

    return matr;
}

matrix_t create_move_from_center_matrix(const point_t &center)
{
    data_t data = create_move_from_center_data(center);

    matrix_t matr = create_move_matrix(data);

    return matr;
}

data_t create_move_to_center_data(const point_t &point)
{
    double x = get_x_point(point), y = get_y_point(point), z = get_z_point(point);

    data_t move_data = create_data(-x, -y, -z);

    return move_data;
}

data_t create_move_from_center_data(const point_t &point)
{
    double x = get_x_point(point), y = get_y_point(point), z = get_z_point(point);

    data_t move_data = create_data(x, y, z);

    return move_data;
}
