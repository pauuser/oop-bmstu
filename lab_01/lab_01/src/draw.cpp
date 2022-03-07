#include "../inc/draw.h"

#include <QPen>

int draw_line(scene_t scene, const line_t &line, const QPen pen)
{
    int rc = OK;

    if (scene == NULL)
        rc = NULL_POINTER;
    else
    {
        point_t p1 = line.point1;
        point_t p2 = line.point2;

        double x1 = get_x_point(p1);
        double y1 = get_y_point(p1);

        double x2 = get_x_point(p2);
        double y2 = get_y_point(p2);

        scene->addLine(x1, y1, x2, y2, pen);
    }

    return rc;
}

int draw_model(scene_t scene, model_t &model)
{
    int rc = OK;
    clear_scene(scene);

    for (int i = 0; i < model.m; i++)
    {
        line_t transformed_line, cur_line;
        init_line(transformed_line);

        init_line(cur_line);
        cur_line = model.lines[i];

        matrix_t mtr = model.transform_matrix;

        transform_line(transformed_line, cur_line, mtr);
        project_line(transformed_line, transformed_line);

        QPen pen(Qt::black);
        draw_line(scene, transformed_line, pen);
    }

    draw_coordinates(scene, model.transform_matrix);

    return rc;
}

int draw_coordinates(scene_t scene, const matrix_t &matr)
{
    double x1 = 0, y1 = 0, z1 = 0;
    double x2 = 50, y2 = 0, z2 = 0;
    double x3 = 0, y3 = 50, z3 = 0;
    double x4 = 0, y4 = 0, z4 = 50;

    point_t point1, point2, point3, point4;
    set_point(point1, x1, y1, z1);
    set_point(point2, x2, y2, z2);
    set_point(point3, x3, y3, z3);
    set_point(point4, x4, y4, z4);

    line_t line1, line2, line3;
    set_line(line1, point1, point2);
    set_line(line2, point1, point3);
    set_line(line3, point1, point4);

    line_t x, y, z;

    transform_line(x, line1, matr);
    transform_line(y, line2, matr);
    transform_line(z, line3, matr);

    project_line(x, x);
    project_line(y, y);
    project_line(z, z);

    QPen x_pen(Qt::red);
    QPen y_pen(Qt::blue);
    QPen z_pen(Qt::green);

    x_pen.setWidth(2);
    y_pen.setWidth(2);
    z_pen.setWidth(2);

    draw_line(scene, x, x_pen);
    draw_line(scene, y, y_pen);
    draw_line(scene, z, z_pen);

    return OK;
}

void clear_scene(scene_t scene)
{
    scene->clear();
}
