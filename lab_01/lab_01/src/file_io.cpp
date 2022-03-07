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

int input_model_from_file(model_t &model, const char *filename)
{
    int rc = OK;

    FILE *f = fopen(filename, "r");

    if (f == NULL)
        rc = NO_FILE;
    else
    {
        free_model(model);
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
        free_model(model);

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
    }

    return rc;
}

int upload_model_to_file(const char *filename, const model_t &model)
{
    int rc = OK;

    FILE *f = fopen(filename, "w");

    if (f == NULL)
        rc = NO_FILE;
    else if (model.n == 0)
        rc = NO_MODEL;
    else
    {
        write_points_to_file(f, model);
        write_lines_to_file(f, model);

        fclose(f);
    }

    return rc;
}

int write_points_to_file(FILE *f, const model_t &model)
{
    int rc = OK;

    if (f == NULL)
        rc = NO_FILE;
    else if (model.n == 0)
        rc = NO_MODEL;
    else
    {
        fprintf(f, "%d\n", model.n);
        for (int i = 0; i < model.n; i++)
        {
            point_t new_point, cur_point;

            init_point(new_point);
            init_point(cur_point);

            cur_point = model.points[i];
            transform_point(new_point, cur_point, model.transform_matrix);

            double x = get_x_point(new_point),
                        y = get_y_point(new_point),
                            z = get_z_point(new_point);
            fprintf(f, "%f %f %f\n", x, y, z);
        }
    }

    return rc;
}

int write_lines_to_file(FILE *f, const model_t &model)
{
    int rc = OK;

    if (f == NULL)
        rc = NULL;
    else if (model.n == 0)
        rc = NO_MODEL;
    else
    {
        fprintf(f, "%d\n", model.m);
        for (int i = 0; i < model.m; i++)
        {
            point_t point1, point2;

            get_elem_line(point1, model.lines[i], 0);
            get_elem_line(point2, model.lines[i], 1);

            int start = find_point_in_mas(point1, model.points, model.n) + 1;
            int dest = find_point_in_mas(point2, model.points, model.n) + 1;

            fprintf(f, "%d %d\n", start, dest);
        }
    }

    return rc;
}

