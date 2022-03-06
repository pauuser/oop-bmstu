#ifndef FILE_IO_H
#define FILE_IO_H

#include <stdio.h>

#include "point.h"
#include "line.h"
#include "model.h"
#include "error.h"

int input_model_from_file(model_t &model, const char *filename);

int read_points(model_t &model, FILE *stream);

int add_points_to_mas(model_t &model, FILE *stream);

int read_lines(model_t &model, FILE *stream);

int add_lines_to_mas(model_t &model, FILE *stream);

int read_model(model_t &model, FILE *stream);

#endif // FILE_IO_H
