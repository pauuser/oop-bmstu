#ifndef MODEL_H
#define MODEL_H

#include "errors.h"
#include "matrix.h"
#include "point.h"
#include "line.h"
#include "point.h"


/*
Структура для хранения модели
Член структуры - массив отрезков,
из которых и состоит модель
m - число отрезков
*/
typedef struct model_t model_t;

struct model_t
{
    int n;
    point_t *points;

    int m;
    line_t *lines;

    matrix_t transform_matrix;
};

void init_model(model_t &model);

void free_model(model_t &model);

int transform_model(model_t &model, const matrix_t &matr);

int move_model(model_t &model, const double dx, const double dy, const double dz);

int scale_model(model_t &model, const double kx, const double ky, const double kz);

int rotate_model(model_t &model, const double ax, const double ay, const double az);

#endif // MODEL_H
