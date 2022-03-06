#ifndef LINE_H
#define LINE_H

#include "point.h"
#include "errors.h"

/*
Структура для хранения отрезка
Члены структуры - две точки
*/
typedef struct line_t line_t;

struct line_t
{
    point_t point1;
    point_t point2;
};

int init_line(line_t &line);

bool index_is_valid_line(const int i);

int get_elem_line(point_t &point, const line_t &line, const int i);

int set_line(line_t &line, const point_t &point1, const point_t &point2);

int transform_line(line_t &new_line, const line_t &line, const matrix_t &matrix);


#endif // LINE_H
