#include "../inc/line.h"

line_t init_line()
{
    line_t line;

    line.point1 = 0;
    line.point2 = 0;

    return line;
}

linearr_t init_linearr()
{
    linearr_t lines;

    lines.n = 0;
    lines.array = NULL;

    return lines;
}

void free_linearr(linearr_t &lines)
{
    lines.n = 0;
    free(lines.array);
    lines.array = NULL;
}

error_t set_line(line_t &line, const int point1, const int point2)
{
    error_t rc = OK;

    line.point1 = point1;
    line.point2 = point2;

    return rc;
}

error_t create_lines_mas(linearr_t &lines, const int m)
{
    error_t rc = OK;

    if (m < 1)
    {
        rc = INAPPROPRIATE_INPUT;
    }
    else
    {
        line_t *tmp = (line_t *)malloc(sizeof(line_t) * m);

        if (tmp == NULL)
        {
            rc = NO_MEMORY;
        }
        else
        {
            lines.n = m;
            lines.array = tmp;
        }
    }

    return rc;
}

error_t copy_linearr(linearr_t &dst, const linearr_t &src)
{
    error_t rc = OK;

    linearr_t tmp = init_linearr();

    rc = create_lines_mas(tmp, get_linearr_n(src));

    if (rc == OK)
    {
        rc = copy_elements_linearr(tmp, src);

        dst = tmp;
    }

    return rc;
}

error_t copy_elements_linearr(linearr_t &dst, const linearr_t &src)
{
    error_t rc = OK;

    dst.n = src.n;

    for (int i = 0; i < dst.n; i++)
    {
        dst.array[i] = src.array[i];
    }

    return rc;
}

int get_linearr_n(const linearr_t &lines)
{
    return lines.n;
}
