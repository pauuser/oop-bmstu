#include "../inc/draw.h"

error_t show_line_on_scene(scene_t scene, const point_t &point1, const point_t &point2)
{
    error_t rc = OK;

    if (scene == NULL)
    {
        rc = NULL_POINTER;
    }
    else
    {
        double x1 = get_x_point(point1);
        double y1 = get_y_point(point1);

        double x2 = get_x_point(point2);
        double y2 = get_y_point(point2);

        scene->addLine(x1, y1, x2, y2);
    }

    return rc;
}

error_t draw_model(scene_t scene, model_t &model)
{
    error_t rc = OK;

    if (scene == NULL)
    {
        rc = NULL_POINTER;
    }
    else if (model_exists(model.points, model.lines) == 0)
    {
        rc = NO_MODEL;
    }
    else
    {
        model_t projected_model = init_model();
        rc = project_model(projected_model, model);

        if (rc == OK)
        {
            clear_scene(scene);
            rc = draw_lines(scene, projected_model.lines, projected_model.points);
        }

    }

    return rc;
}

error_t draw_lines(scene_t scene, const linearr_t &lines, const pointarr_t &points)
{
    error_t rc = OK;

    for (int i = 0; rc == OK && i < lines.n; i++)
    {
        line_t edge = lines.array[i];

        point_t pt1 = points.array[edge.point1];
        point_t pt2 = points.array[edge.point2];

        rc = show_line_on_scene(scene, pt1, pt2);
    }

    return rc;
}

void clear_scene(scene_t scene)
{
    scene->clear();
}
