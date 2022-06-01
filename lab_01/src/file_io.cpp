#include "../inc/file_io.h"

/*
  На вход подаётся файл формата:

  n
  x1 y1 z1
  z2 y2 z2
  ...
  xn yn zn
  m
  a1 b1
  a2 b2
  ...
  am bm

  ai, bi - номера рёбер, которые мы соединяем.
  n - число точек
  m - число рёбер

  Координаты - действительные числа
*/

error_t input_model_from_file(model_t &model, filename_t &data)
{
    error_t rc = OK;

    FILE *f = fopen(data.filename, "r");

    if (f == NULL)
    {
        rc = NO_FILE;
    }
    else
    {
        model_t tmp_model = init_model();

        rc = read_model(tmp_model, f);

        fclose(f);

        if (rc == OK)
        {
            free_model(model);

            model = tmp_model;
        }
    }

    return rc;
}

error_t read_model(model_t &tmp_model, FILE *stream)
{
    error_t rc = OK;

    if (stream == NULL)
    {
        rc = NO_FILE;
    }
    else
    {
        rc = read_points(tmp_model.points, stream);
    }

    if (rc == OK)
    {
        rc = read_lines(tmp_model.lines, stream);

        if (rc != OK)
        {
            free_pointarr(tmp_model.points);
        }
    }

    if (rc == OK)
    {
        rc = read_center(tmp_model.center, stream);

        if (rc != OK)
        {
            free_linearr(tmp_model.lines);

            free_pointarr(tmp_model.points);
        }
    }

    return rc;
}

error_t read_points_count(int &n, FILE *stream)
{
    error_t rc = OK;

    int tmp_n = 0;

    int read = fscanf(stream, "%d", &tmp_n);

    if (read != 1)
    {
        rc = INVALID_INPUT;
    }
    else if (tmp_n < 1)
    {
        rc = INAPPROPRIATE_INPUT;
    }
    else
    {
        n = tmp_n;
    }

    return rc;
}

error_t read_point(point_t &point, FILE *stream)
{
    error_t rc = OK;

    if (stream == NULL)
    {
        rc = NO_FILE;
    }
    else
    {
        double x = 0.0, y = 0.0, z = 0.0;

        if (fscanf(stream, "%lf %lf %lf", &x, &y, &z) != 3)
        {
            rc = INVALID_INPUT;
        }
        else
        {
            rc = set_point(point, x, y, z);
        }
    }

    return rc;
}

error_t read_center(point_t &center, FILE *f)
{
    error_t rc = OK;

    if (f == NULL)
    {
        rc = NO_FILE;
    }
    else
    {
        rc = read_point(center, f);
    }

    return rc;
}

error_t read_points(pointarr_t &points, FILE *stream)
{
    error_t rc = OK;

    if (stream == NULL)
    {
        rc = NO_FILE;
    }
    else
    {
        int n = 0;

        rc = read_points_count(n, stream);

        if (rc == OK)
        {
            rc = create_points_mas(points, n);
        }

        if (rc == OK)
        {
            rc = add_points_to_mas(points, stream);

            if (rc != OK)
            {
                free_pointarr(points);
            }
        }
    }

    return rc;
}


error_t add_points_to_mas(pointarr_t &points, FILE *stream)
{
    error_t rc = OK;

    if (stream == NULL)
    {
        rc = NO_FILE;
    }
    else if (points.n == 0)
    {
        rc = NULL_POINTER;
    }

    for (int i = 0; rc == OK && i < points.n; i++)
    {
        rc = read_point(points.array[i], stream);
    }

    return rc;
}

/*
 Работа с чтением линий
*/

error_t read_lines_count(int &m, FILE *stream)
{
    error_t rc = OK;

    int tmp_m = 0;

    int read = fscanf(stream, "%d", &tmp_m);

    if (read != 1)
    {
        rc = INVALID_INPUT;
    }
    else if (tmp_m < 1)
    {
        rc = INAPPROPRIATE_INPUT;
    }
    else
    {
        m = tmp_m;
    }

    return rc;
}

bool connection_is_valid(const int src, const int dest)
{
    bool res = 1;

    if (src < 0 || dest < 0)
    {
        res = 0;
    }
    else if (src == dest)
    {
        res = 0;
    }

    return res;
}

error_t read_line(line_t &line, FILE *stream)
{
    error_t rc = OK;

    if (stream == NULL)
    {
        rc = NO_FILE;
    }
    else
    {
        int src = 0, dest = 0;

        if (fscanf(stream, "%d %d", &src, &dest) != 2)
        {
            rc = INVALID_INPUT;
        }
        else if (connection_is_valid(src, dest) == 0)
        {
            rc = INAPPROPRIATE_INPUT;
        }
        else
        {
            rc = set_line(line, src, dest);
        }
    }

    return rc;
}


error_t read_lines(linearr_t &lines, FILE *stream)
{
    error_t rc = OK;

    if (stream == NULL)
    {
        rc = NO_FILE;
    }
    else
    {
        int m = 0;

        rc = read_lines_count(m, stream);

        if (rc == OK)
        {
            rc = create_lines_mas(lines, m);
        }
        if (rc == OK)
        {
            rc = add_lines_to_mas(lines, stream);

            if (rc != OK)
            {
                free_linearr(lines);
            }
        }
    }

    return rc;
}


error_t add_lines_to_mas(linearr_t &lines, FILE *stream)
{
    error_t rc = OK;

    if (stream == NULL)
    {
        rc = NO_FILE;
    }
    else if (lines.n == 0 || lines.array == NULL)
    {
        rc = NO_LINEARR;
    }

    for (int i = 0; rc == OK && i < lines.n; i++)
    {
        rc = read_line(lines.array[i], stream);
    }

    return rc;
}


/*
Функции для вывода в файл
*/
error_t upload_model_to_file(filename_t &data, const model_t &model)
{
    error_t rc = OK;

    FILE *f = fopen(data.filename, "w");

    if (f == NULL)
    {
        rc = NO_FILE;
    }
    else if (model_exists(model.points, model.lines) == 0)
    {
        rc = NO_MODEL;

        fclose(f);
    }
    else
    {
        rc = write_points_to_file(f, model.points);

        if (rc == OK)
        {
            rc = write_lines_to_file(f, model.lines);
        }

        fclose(f);
    }

    return rc;
}

error_t write_point_to_file(FILE *f, const point_t &point)
{
    error_t rc = OK;

    if (f == NULL)
    {
        rc = NO_FILE;
    }
    else
    {
        double x = get_x_point(point),
                    y = get_y_point(point),
                        z = get_z_point(point);

        fprintf(f, "%f %f %f\n", x, y, z);
    }

    return rc;
}

error_t write_count_to_file(FILE *f, const int n)
{
    error_t rc = OK;

    if (f == NULL)
    {
        rc = NO_FILE;
    }
    else
    {
       fprintf(f, "%d\n", n);
    }

    return rc;
}


error_t write_points_to_file(FILE *f, const pointarr_t &points)
{
    error_t rc = OK;

    if (f == NULL)
    {
        rc = NO_FILE;
    }
    else if (points.n < 1 || points.array == NULL)
    {
        rc = NO_POINTARR;
    }
    else
    {
        rc = write_count_to_file(f, points.n);

        for (int i = 0; rc == OK && i < points.n; i++)
        {
            rc = write_point_to_file(f, points.array[i]);
        }
    }

    return rc;
}

error_t write_line_to_file(FILE *f, const line_t &line)
{
    error_t rc = OK;

    if (f == NULL)
    {
        rc = NO_FILE;
    }
    else
    {
        fprintf(f, "%d %d\n", line.point1, line.point2);
    }

    return rc;
}


error_t write_lines_to_file(FILE *f, const linearr_t &lines)
{
    error_t rc = OK;

    if (f == NULL)
    {
        rc = NULL_POINTER;
    }
    else if (lines.n < 1 || lines.array == NULL)
    {
        rc = NO_MODEL;
    }
    else
    {
        rc = write_count_to_file(f, lines.n);

        for (int i = 0; rc == OK && i < lines.n; i++)
        {
            rc = write_line_to_file(f, lines.array[i]);
        }
    }

    return rc;
}
