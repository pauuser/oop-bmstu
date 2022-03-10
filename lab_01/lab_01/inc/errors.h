#ifndef ERRORS_H
#define ERRORS_H

#define OK                   0
#define NO_MEMORY           -1
#define IND_OUT_OF_RANGE    -2
#define INVALID_INPUT       -3
#define INAPPROPRIATE_INPUT -4
#define NULL_POINTER        -5
#define NO_FILE             -6
#define NO_MODEL            -7
#define UNKNOWN_COMMAND     -8

void print_error(int error);

#endif // ERRORS_H
