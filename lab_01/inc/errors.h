#ifndef ERRORS_H
#define ERRORS_H

const int dimension = 3;

enum error_t
{
    OK,
    NO_MEMORY,
    IND_OUT_OF_RANGE,
    INVALID_INPUT,
    INAPPROPRIATE_INPUT,
    NULL_POINTER,
    NO_FILE,
    UNKNOWN_COMMAND,
    NO_MODEL,
    NO_LINEARR,
    NO_POINTARR
};

void print_error(error_t error);

#endif // ERRORS_H
