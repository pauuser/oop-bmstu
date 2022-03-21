#ifndef DRAW_H
#define DRAW_H

#include <QGraphicsView>
#include <QPen>

#include "errors.h"
#include "line.h"
#include "point.h"
#include "model.h"
#include "projection.h"

typedef QGraphicsScene* scene_t;

error_t draw_model(scene_t scene, model_t &model);

error_t show_line_on_scene(scene_t scene, const point_t &point1, const point_t &point2);

error_t draw_model(scene_t scene, model_t &model);

void clear_scene(scene_t scene);

error_t draw_lines(scene_t scene, const linearr_t &lines, const pointarr_t &points);


#endif // DRAW_H
