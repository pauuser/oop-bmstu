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

#endif // LINE_H
