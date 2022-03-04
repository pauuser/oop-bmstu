#include <stdio.h>

#include "model.h"

int init_model(model_t &model)
{
    model.n = 0;
    model.points = NULL;

    model.m = 0;
    model.lines = NULL;

    model.transform_matrix = NULL;
    return OK;
}


