#ifndef LINE_H
#define LINE_H

#include "point.h"
#include "errors.h"

typedef struct line_t line_t;

struct line_t
{
    int point1;
    int point2;
};

line_t init_line();

bool index_is_valid_line(const int i);

error_t get_elem_line(point_t &point, const line_t &line, const int i);

error_t set_line(line_t &line, const int point1, const int point2);

error_t transform_line(line_t &new_line, const line_t &line, const matrix_t &matrix);


#endif // LINE_H
