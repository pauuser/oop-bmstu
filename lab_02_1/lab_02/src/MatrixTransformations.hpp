#include "Exceptions.h"
#include "Matrix.h"

template <typename T>
void Matrix<T>::resize(const size_t new_row, const size_t new_col, const T& fill_value)
{
    if (new_row < 1 || new_col < 1)
    {
        throw SizeError(new_row, new_col, __FILE__, __LINE__);
    }

    auto new_data = _allocateMatrix(new_row, new_col);

    for (size_t i = 0; i < new_row; i++)
    {
        for (size_t j = 0; j < new_col; j++)
        {
            ((i < nrows) && (j < ncols)) ? new_data[i][j] = data[i][j] :
                new_data[i][j] = fill_value;
        }
    }

    data = new_data;
    new_data = nullptr;

    nrows = new_row;
    ncols = new_col;
}

template <typename T>
void Matrix<T>::rotate_right()
{
    this->transpose();
    this->vertical_mirror();
}

template <typename T>
void Matrix<T>::rotate_left()
{
    this->transpose();
    this->horizontal_mirror();
}

template <typename T>
void Matrix<T>::resizeColumns(const size_t new_col, const T& fill_value)
{
    this->resize(nrows, new_col, fill_value);
}

template <typename T>
void Matrix<T>::resizeRows(const size_t new_row, const T& fill_value)
{
    this->resize(new_row, ncols, fill_value);
}

template <typename T>
void Matrix<T>::insertRow(const size_t before_ind, const T& fill_value)
{
    if (before_ind > nrows)
    {
        throw IndexOutOfRange(before_ind, __FILE__, __LINE__, "Can't insert!");
    }

    this->resize(nrows + 1, ncols, fill_value);

    for (size_t i = nrows - 1; i > before_ind; i--)
    {
        for (size_t j = 0; j < ncols; j++)
        {
            T tmp = data[i][j];
            data[i][j] = data[i - 1][j];
            data[i - 1][j] = tmp;
        }
    }
}

template <typename T>
void Matrix<T>::insertCol(const size_t before_ind, const T& fill_value)
{
    if (before_ind > ncols)
    {
        throw IndexOutOfRange(before_ind, __FILE__, __LINE__, "Can't insert!");
    }

    this->resize(nrows, ncols + 1, fill_value);

    for (size_t i = ncols - 1; i > before_ind; i--)
    {
        for (size_t j = 0; j < nrows; j++)
        {
            T tmp = data[j][i];
            data[j][i] = data[j][i - 1];
            data[j][i - 1] = tmp;
        }
    }
}

template <typename T>
void Matrix<T>::deleteRow(const size_t ind)
{
    if (ind >= nrows)
    {
        throw IndexOutOfRange(ind, __FILE__, __LINE__, "Can't delete!");
    }

    if (nrows == 1)
    {
        throw SizeError(nrows, ncols, __FILE__, __LINE__, "Too small matrix!");
    }

    for (size_t i = ind; i < nrows - 1; i++)
    {
        for (size_t j = 0; j < ncols; j++)
        {
            T tmp = data[i][j];
            data[i][j] = data[i + 1][j];
            data[i + 1][j] = tmp;
        }
    }

    this->resize(nrows - 1, ncols);
}

template <typename T>
void Matrix<T>::deleteCol(const size_t ind)
{
    if (ind >= ncols)
    {
        throw IndexOutOfRange(ind, __FILE__, __LINE__, "Can't delete!");
    }

    if (ncols == 1)
    {
        throw SizeError(nrows, ncols, __FILE__, __LINE__, "Too small matrix!");
    }

    for (size_t i = ind; i < ncols - 1; i++)
    {
        for (size_t j = 0; j < nrows; j++)
        {
            T tmp = data[j][i];
            data[j][i] = data[j][i + 1];
            data[j][i + 1] = tmp;
        }
    }

    this->resize(nrows, ncols - 1);
}

template <typename T>
void Matrix<T>::vertical_mirror()
{
    for (size_t i = 0; i < nrows; i++)
    {
        for (size_t j = 0; j < ncols / 2; j++)
        {
            T tmp = data[i][j];
            data[i][j] = data[i][ncols - 1 - j];
            data[i][ncols - 1 - j] = tmp;
        }
    }
}

template <typename T>
void Matrix<T>::horizontal_mirror()
{
    for (size_t i = 0; i < ncols; i++)
    {
        for (size_t j = 0; j < nrows / 2; j++)
        {
            T tmp = data[j][i];
            data[j][i] = data[nrows - 1 - j][i];
            data[nrows - 1 - j][i] = tmp;
        }
    }
}