#ifndef PROJECTION_H
#define PROJECTION_H

#include <math.h>

#include "point.h"
#include "line.h"

static const double sin30 = sin(pi * 30 / 180);
static const double cos30 = cos(pi * 30 / 180);

typedef struct projected_point_t projected_point_t;

struct projected_point_t
{
    double x;
    double y;
};

typedef struct projected_line_t projected_line_t;

struct projected_line_t
{
    projected_point_t point1;
    projected_point_t point2;
};



#endif // PROJECTION_H
