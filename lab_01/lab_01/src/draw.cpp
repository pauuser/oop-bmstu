#include "../inc/draw.h"

int draw_model_edge(scene_t scene, const point_t &pt1, const point_t &pt2, const QPen pen)
{
    int rc = OK;

    if (scene == NULL)
        rc = NULL_POINTER;
    else
    {
        point_t pt1_projected = init_point();
        point_t pt2_projected = init_point();

        rc = project_point(pt1_projected, pt1);

        if (rc == OK)
        {
            rc = project_point(pt2_projected, pt2);

            if (rc == OK)
            {
                rc = show_line_on_scene(scene, pt1_projected, pt2_projected, pen);
            }
        }
    }

    return rc;
}

int show_line_on_scene(scene_t scene, const point_t &point1, const point_t &point2, const QPen pen)
{
    int rc = OK;

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

        scene->addLine(x1, y1, x2, y2, pen);
    }

    return rc;
}

int draw_model(scene_t scene, model_t &model)
{
    int rc = OK;
    QPen pen(Qt::black);

    if (scene == NULL)
    {
        rc = NULL_POINTER;
    }
    else if (model.n == 0)
    {
        rc = NO_MODEL;
    }
    else
    {
        clear_scene(scene);

        for (int i = 0; i < model.m; i++)
        {
            line_t edge = model.lines[i];

            point_t pt1 = model.points[edge.point1];
            point_t pt2 = model.points[edge.point2];

            point_t transformed_pt1, transformed_pt2;

            rc = transform_point(transformed_pt1, pt1, model.transform_matrix);

            if (rc == OK)
            {
                rc = transform_point(transformed_pt2, pt2, model.transform_matrix);
            }

            if (rc == OK)
            {
                rc = draw_model_edge(scene, transformed_pt1, transformed_pt2, pen);
            }
        }
    }

    return rc;
}

void clear_scene(scene_t scene)
{
    scene->clear();
}
