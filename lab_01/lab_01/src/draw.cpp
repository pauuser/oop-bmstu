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
        pointarr_t proj_points = init_pointarr();

        rc = get_transformed_points(proj_points, model.points, model.transform_matrix);

        if (rc == OK)
        {
            rc = project_points(proj_points);
        }

        if (rc == OK)
        {
            clear_scene(scene);

            rc = draw_lines(scene, model.lines, proj_points);
        }
    }

    return rc;
}

error_t draw_lines(scene_t scene, const linearr_t &lines, const pointarr_t &points)
{
    error_t rc = OK;

    for (int i = 0; rc == OK && i < lines.n; i++)
    {
        point_t pt1, pt2;

        rc = find_points(pt1, pt2, points, lines.array[i]);

        if (rc == OK)
        {
            rc = show_line_on_scene(scene, pt1, pt2);
        }
    }

    return rc;
}

error_t find_points(point_t &pt1, point_t &pt2, const pointarr_t &points, const line_t &edge)
{
    error_t rc = OK;

    int i1 = edge.point1;
    int i2 = edge.point2;

    if (i1 < 1 || i1 > points.n)
    {
        rc = IND_OUT_OF_RANGE;
    }
    else if (i2 < 1 || i2 > points.n)
    {
        rc = IND_OUT_OF_RANGE;
    }
    else
    {
        pt1 = points.array[edge.point1];
        pt2 = points.array[edge.point2];
    }

    return rc;
}

void clear_scene(scene_t scene)
{
    scene->clear();
}
