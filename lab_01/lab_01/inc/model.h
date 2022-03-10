#ifndef MODEL_H
#define MODEL_H

#include "errors.h"
#include "matrix.h"
#include "point.h"
#include "line.h"
#include "point.h"
#include "request.h"


typedef struct model_t model_t;

struct model_t
{
    int n;
    point_t *points;

    int m;
    line_t *lines;

    matrix_t transform_matrix;
};

model_t init_model();

void free_model(model_t &model);

int transform_model(model_t &model, const matrix_t &matr);

int move_model(model_t &model, data_t &data);

int scale_model(model_t &model, data_t &data);

int rotate_model(model_t &model, data_t &data);


#endif // MODEL_H
