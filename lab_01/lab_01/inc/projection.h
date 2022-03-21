#ifndef PROJECTION_H
#define PROJECTION_H

#define _USE_MATH_DEFINES
#include <cmath>

#include <math.h>

#include "point.h"
#include "line.h"
#include "model.h"

error_t project_point(point_t &pout, const point_t &pin);

error_t project_points(pointarr_t &points);

error_t project_model(model_t &projected_model, const model_t &model);


#endif // PROJECTION_H
