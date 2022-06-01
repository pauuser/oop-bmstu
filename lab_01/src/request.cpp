#include "../inc/request.h"

request_t create_request(const event_t event, const double cx, const double cy, const double cz, const char *f)
{
    request_t request;
    data_t change_data = create_data(cx, cy, cz);

    filename_t filename = create_filename(f);

    request.event = event;
    request.filename = filename;
    request.data = change_data;

    return request;
}

data_t create_data(double cx, double cy, double cz)
{
    data_t data = { .cx = cx, .cy = cy, .cz = cz };

    return data;
}

filename_t create_filename(const char *f)
{
    filename_t filename = { .filename = f };

    return filename;
}

