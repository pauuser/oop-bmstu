#ifndef PROJECTION_H
#define PROJECTION_H

#define _USE_MATH_DEFINES
#include <cmath>

#include <math.h>

#include "point.h"
#include "line.h"

static const double sin45 = sin(M_PI * 45 / 180);
static const double cos45 = cos(M_PI * 45 / 180);

error_t project_point(point_t &pout, const point_t &pin);

error_t project_line(line_t &pout, const line_t &pin);

#endif // PROJECTION_H
