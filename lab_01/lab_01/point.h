#ifndef POINT_H
#define POINT_H

#include <stdlib.h>

#include "errors.h"
#include "matrix.h"

/*
Структура для хранения точки
Координаты - вещественные числа
*/
typedef struct point_t point_t;

struct point_t
{
    double row[dimension + 1];
};


#endif // POINT_H
