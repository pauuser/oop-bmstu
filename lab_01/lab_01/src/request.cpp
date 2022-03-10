#include "../inc/request.h"

request_t create_request(const event_t event, const double cx, const double cy, const double cz, const char *f)
{
    request_t request;
    data_t change_data = { .cx = cx, .cy = cy, .cz = cz };
    filename_t filename = { .filename = f };

    request.event = event;
    request.filename = filename;
    request.data = change_data;

    return request;
}
