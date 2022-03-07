#ifndef DRAW_H
#define DRAW_H

#include <QGraphicsView>

#include "errors.h"
#include "line.h"
#include "point.h"
#include "model.h"
#include "projection.h"

typedef QGraphicsScene* scene_t;

int draw_model(scene_t scene, model_t &model);

int draw_line(scene_t scene, const line_t &line, const QPen pen);

void clear_scene(scene_t scene);

int draw_coordinates(scene_t scene, const matrix_t &matr);

#endif // DRAW_H
