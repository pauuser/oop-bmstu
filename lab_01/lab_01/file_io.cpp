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

// Проверку на NULL!!!!!!!

int read_model(model_t &model, FILE *stream)
{
    int rc = OK;

    if ((rc = read_points(model, stream))
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
    if (fscanf(stream, "%d", &n) != 1)
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
    if (fscanf(stream, "%d", &m) != 1)
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

    for (int i = 0; i < model.m && rc == OK; i++)
    {
        fprintf(stdout, "i = %d\n", i);
        int src = 0, dest = 0;

        if (fscanf(stream, "%d", &src) != 1 ||
                fscanf(stream, "%d", &dest) != 1)
            rc = INVALID_INPUT;
        else if (src < 1 || src > model.n || dest < 1 || dest > model.n)
        {
            fprintf(stdout, "AAA %d %d\n", src, dest);
            rc = INAPPROPRIATE_INPUT;
        }
        else if (src == dest)
        {
            fprintf(stdout, "AAAOOOO\n");
            rc = INAPPROPRIATE_INPUT;
        }
        else
        {
            set_line(model.lines[i], model.points[src - 1], model.points[dest - 1]);
            fprintf(stdout, "%f %f %f %f\n", model.lines[i].point1.row[0], model.lines[i].point1.row[1],
                                             model.lines[i].point2.row[0], model.lines[i].point2.row[1]);
        }
    }

    return rc;
}
