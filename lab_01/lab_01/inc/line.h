#ifndef LINE_H
#define LINE_H

#include "point.h"
#include "errors.h"
#include "matrix.h"

typedef struct line_t line_t;

struct line_t
{
    int point1;
    int point2;
};

typedef struct linearr_t linearr_t;

struct linearr_t
{
   int n;
   line_t *array;
};

line_t init_line();

linearr_t init_linearr();

void free_linearr(linearr_t &lines);

bool index_is_valid_line(const int i);

error_t get_elem_line(point_t &point, const line_t &line, const int i);

error_t set_line(line_t &line, const int point1, const int point2);

error_t transform_line(line_t &new_line, const line_t &line, const matrix_t &matrix);

error_t allocate_lines_mas(linearr_t &lines, const int m);

error_t copy_linearr(linearr_t &dst, const linearr_t &src);

#endif // LINE_H
