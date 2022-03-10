#ifndef FILE_IO_H
#define FILE_IO_H

#include <stdio.h>

#include "point.h"
#include "line.h"
#include "model.h"
#include "error.h"
#include "request.h"

error_t input_model_from_file(model_t &model, filename_t &data);

error_t read_points(model_t &model, FILE *stream);

error_t add_points_to_mas(model_t &model, FILE *stream);

error_t read_lines(model_t &model, FILE *stream);

error_t add_lines_to_mas(model_t &model, FILE *stream);

error_t read_model(model_t &model, FILE *stream);

error_t upload_model_to_file(filename_t &data, const model_t &model);

error_t write_points_to_file(FILE *f, const model_t &model);

error_t write_lines_to_file(FILE *f, const model_t &model);

#endif // FILE_IO_H
