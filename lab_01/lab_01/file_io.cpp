#include "file_io.h"
#include <iostream>

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

int input_model_from_file(model_t &model, const char *filename)
{
    int rc = OK;

    FILE *f = fopen(filename, "r");

    if (f == NULL)
        rc = NO_FILE;
    else
    {
        rc = read_model(model, f);
        fclose(f);
    }

    return rc;
}

int read_model(model_t &model, FILE *stream)
{
    int rc = OK;

    if (stream == NULL)
        rc = NO_FILE;
    else if ((rc = read_points(model, stream))
            || (rc = read_lines(model, stream)))
    {
        free(model.points);
        model.points = NULL;

        free(model.lines);
        model.lines = NULL;
    }

    return rc;
}

int read_points(model_t &model, FILE *stream)
{
    int rc = OK;

    int n = 0;

    if (stream == NULL)
        rc = NO_FILE;
    else if (fscanf(stream, "%d", &n) != 1)
        rc = INVALID_INPUT;
    else if (n < 1)
        rc = INAPPROPRIATE_INPUT;
    else
    {
        model.n = n;
        model.points = (point_t *)malloc(sizeof(point_t) * n);

        if (model.points == NULL)
            rc = NO_MEMORY;
        else if ((rc = add_points_to_mas(model, stream)) != OK)
        {
            free(model.points);
            model.points = NULL;
        }
    }

    return rc;
}

int add_points_to_mas(model_t &model, FILE *stream)
{
    int rc = OK;

    if (stream == NULL)
        rc = NO_FILE;

    for (int i = 0; i < model.n && rc == OK; i++)
    {
        double x = 0.0, y = 0.0, z = 0.0;

        if (fscanf(stream, "%lf", &x) != 1 ||
                fscanf(stream, "%lf", &y) != 1 ||
                    fscanf(stream, "%lf", &z) != 1)
            rc = INVALID_INPUT;
        else
            set_point(model.points[i], x, y, z);
    }

    return rc;
}

int read_lines(model_t &model, FILE *stream)
{
    int rc = OK;

    int m = 0;
    if (stream == NULL)
        rc = NO_FILE;
    else if (fscanf(stream, "%d", &m) != 1)
        rc = INVALID_INPUT;
    else if (m < 1)
        rc = INAPPROPRIATE_INPUT;
    else
    {
        model.m = m;
        model.lines = (line_t *)malloc(sizeof(line_t) * m);

        if (model.lines == NULL)
            rc = NO_MEMORY;
        else if ((rc = add_lines_to_mas(model, stream)) != OK)
        {
            free(model.lines);
            model.lines = NULL;
        }
    }

    return rc;
}

int add_lines_to_mas(model_t &model, FILE *stream)
{
    int rc = OK;

    if (stream == NULL)
        rc = NO_FILE;

    for (int i = 0; i < model.m && rc == OK; i++)
    {
        int src = 0, dest = 0;

        if (fscanf(stream, "%d", &src) != 1 ||
                fscanf(stream, "%d", &dest) != 1)
            rc = INVALID_INPUT;
        else if (src < 1 || src > model.n || dest < 1 || dest > model.n)
            rc = INAPPROPRIATE_INPUT;
        else if (src == dest)
            rc = INAPPROPRIATE_INPUT;
        else
            set_line(model.lines[i], model.points[src - 1], model.points[dest - 1]);

        fprintf(stdout, "%d %d\n", src, dest);
    }

    return rc;
}

int upload_model_to_file(const char *filename, const model_t &model)
{
    int rc = OK;

    FILE *f = fopen(filename, "w");

    if (f == NULL)
        rc = NO_FILE;
    else
    {
        fprintf(f, "%d\n", model.n);

        for (int i = 0; i < model.n; i++)
        {
            point_t new_point, cur_point;

            init_point(new_point);
            init_point(cur_point);

            transform_point(new_point, cur_point, model.transform_matrix);

            double x = get_x_point(new_point);
            double y = get_y_point(new_point);
            double z = get_z_point(new_point);

            fprintf(f, "%f %f %f\n", x, y, z);
        }

        for (int i = 0; i < model.m; i++)
        {

        }

        fclose(f);
    }

    return rc;
}
