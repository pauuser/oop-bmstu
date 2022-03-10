#ifndef FILE_IO_H
#define FILE_IO_H

#include <stdio.h>

#include "point.h"
#include "line.h"
#include "model.h"
#include "error.h"
#include "request.h"

int input_model_from_file(model_t &model, filename_t &data);

int read_points(model_t &model, FILE *stream);

int add_points_to_mas(model_t &model, FILE *stream);

int read_lines(model_t &model, FILE *stream);

int add_lines_to_mas(model_t &model, FILE *stream);

int read_model(model_t &model, FILE *stream);

int upload_model_to_file(filename_t &data, const model_t &model);

int write_points_to_file(FILE *f, const model_t &model);

int write_lines_to_file(FILE *f, const model_t &model);

#endif // FILE_IO_H
