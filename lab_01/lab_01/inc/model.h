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
    pointarr_t points;

    linearr_t lines;

    matrix_t transform_matrix;

    point_t center;
};

model_t init_model();

void free_model(model_t &model);

bool model_exists(const pointarr_t &points, const linearr_t &lines);

error_t transform_model(model_t &model, const matrix_t &matr);

error_t move_model(model_t &model, const data_t &data);

error_t scale_model(model_t &model, const data_t &data);

error_t rotate_model(model_t &model, const data_t &data);

error_t copy_model(model_t &dst, const model_t &model);

/*
error_t get_transformed_model(model_t &dst, const model_t &src);

error_t transform_full_model(model_t &tmp_model);
*/

error_t transform_center_point(point_t &center, const matrix_t &transform_matr);

#endif // MODEL_H
