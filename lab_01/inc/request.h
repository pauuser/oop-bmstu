#ifndef REQUEST_H
#define REQUEST_H

#include "errors.h"

enum event_t
{
    UPLOAD,
    MOVE,
    SCALE,
    ROTATE,
    SAVE,
    DRAW
};

typedef struct data_t data_t;

struct data_t
{
    double cx;
    double cy;
    double cz;
};


typedef struct filename_t filename_t;

struct filename_t
{
    const char *filename;
};


typedef struct request_t request_t;

struct request_t
{
    event_t event;
    data_t data;
    filename_t filename;
};

request_t create_request(const event_t event, const double cx = 0, const double cy = 0, const double cz = 0, const char *f = "test.txt");

data_t create_data(double cx, double cy, double cz);

filename_t create_filename(const char *f);

#endif // REQUEST_H
