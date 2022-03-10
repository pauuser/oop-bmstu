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

error_t transform_model(model_t &model, const matrix_t &matr);

error_t move_model(model_t &model, data_t &data);

error_t scale_model(model_t &model, data_t &data);

error_t rotate_model(model_t &model, data_t &data);


#endif // MODEL_H
