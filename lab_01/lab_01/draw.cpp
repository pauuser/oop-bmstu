#include "draw.h"

int draw_line(scene_t scene, const line_t &line)
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

        scene->addLine(x1, y1, x2, y2);
    }

    return rc;
}

int draw_model(scene_t scene, model_t &model)
{
    int rc = OK;

    for (int i = 0; i < model.m; i++)
    {
        line_t transformed_line, cur_line;
        init_line(transformed_line);

        init_line(cur_line);
        cur_line = model.lines[i];

        matrix_t mtr = model.transform_matrix;

        transform_line(transformed_line, cur_line, mtr);
        project_line(cur_line, cur_line);


        draw_line(scene, cur_line);
    }

    return rc;
}
