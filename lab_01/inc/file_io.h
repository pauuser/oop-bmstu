#ifndef FILE_IO_H
#define FILE_IO_H

#include <stdio.h>

#include "point.h"
#include "line.h"
#include "model.h"
#include "error.h"
#include "request.h"

error_t input_model_from_file(model_t &model, filename_t &data);

error_t read_model(model_t &model, FILE *stream);


error_t read_points_count(int &n, FILE *stream);

error_t read_point(point_t &point, FILE *stream);

error_t allocate_points_mas(pointarr_t &points, const int n);

error_t read_points(pointarr_t &points, FILE *stream);

error_t add_points_to_mas(pointarr_t &points, FILE *stream);


error_t allocate_lines_mas(linearr_t &lines, const int m);

error_t read_lines_count(int &m, FILE *stream);

bool connection_is_valid(const int src, const int dest);

error_t read_line(line_t &line, FILE *stream);

error_t read_lines(linearr_t &lines, FILE *stream);

error_t add_lines_to_mas(linearr_t &lines, FILE *stream);


error_t read_center(point_t &center, FILE *f);

/*
Функции для вывода в файл
*/
error_t upload_model_to_file(filename_t &data, const model_t &model);

error_t write_points_to_file(FILE *f, const pointarr_t &points);

error_t write_lines_to_file(FILE *f, const linearr_t &lines);

#endif // FILE_IO_H
