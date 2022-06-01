#include "Exceptions.h"
#include "Matrix.h"

/*
* Оператор присваивания
*/
template <typename T>
Matrix<T>& Matrix<T>::operator =(const Matrix<T>& matrix)
{
    nrows = matrix.getRows();
    ncols = matrix.getColumns();
    this->data = _allocateMatrix(nrows, ncols);

    for (size_t i = 0; i < nrows; i++)
    {
        for (size_t j = 0; j < ncols; j++)
        {
            (this->data)[i][j] = matrix[i][j];
        }
    }

    return *this;
}

template <typename T>
Matrix<T>& Matrix<T>::operator =(Matrix<T>&& matrix) noexcept
{
    nrows = matrix.nrows;
    ncols = matrix.ncols;
    this->data = matrix.data;

    return *this;
}

template <typename T>
Matrix<T>& Matrix<T>::operator =(std::initializer_list<std::initializer_list<T>> values)
{
    size_t rows = values.size();

    auto first = values.begin();
    size_t cols = first->size();

    // Проверка на корректность
    for (const auto& line : values)
    {
        if (line.size() != cols)
        {
            throw InitError(__FILE__, __LINE__, "Bad initialiser list.");
        }
    }

    data = _allocateMatrix(rows, cols);
    nrows = rows;
    ncols = cols;

    size_t i = 0;
    for (const auto& row : values)
    {
        size_t j = 0;
        for (const auto& val : row)
        {
            data[i][j] = val;
            j++;
        }
        i++;
    }

    return *this;
}

template <typename T>
bool Matrix<T>::operator ==(const Matrix<T>& matrix) const
{
    return this->equals(matrix);
}

template <typename T>
bool Matrix<T>::operator !=(const Matrix<T>& matrix) const
{
    return this->unequals(matrix);
}

/*
* Оператор доступа к строке
*/
template <typename T>
Matrix<T>::MatrixRow& Matrix<T>::operator[](const size_t ind)
{
    if (this->_isMatrixIndValid(ind) == false)
    {
        throw IndexOutOfRange(ind, __FILE__, __LINE__);
    }

    return this->data[ind];
}

template <typename T>
const typename Matrix<T>::MatrixRow& Matrix<T>::operator[](const size_t ind) const
{
    if (this->_isMatrixIndValid(ind) == false)
    {
        throw IndexOutOfRange(ind, __FILE__, __LINE__);
    }

    return this->data[ind];
}

/*
* Арифметические операторы
*/
template <typename T>
Matrix<T> Matrix<T>::operator +(const Matrix<T>& matrix) const
{
    if (this->_equalSize(matrix) == false)
    {
        throw SizeError(matrix.getColumns(), matrix.getRows(),
            __FILE__, __LINE__, "Sizes don't match!");
    }

    Matrix<T> tmp(nrows, ncols);

    for (size_t i = 0; i < nrows; i++)
    {
        for (size_t j = 0; j < ncols; j++)
        {
            tmp[i][j] = (*this)[i][j] + matrix[i][j];
        }
    }

    return tmp;
}

template <typename T>
Matrix<T> Matrix<T>::operator -(const Matrix<T>& matrix) const
{
    if (this->_equalSize(matrix) == false)
    {
        throw SizeError(matrix.getColumns(), matrix.getRows(),
            __FILE__, __LINE__, "Sizes don't match!");
    }

    Matrix<T> tmp(nrows, ncols);

    for (size_t i = 0; i < nrows; i++)
    {
        for (size_t j = 0; j < ncols; j++)
        {
            tmp[i][j] = (*this)[i][j] - matrix[i][j];
        }
    }

    return tmp;
}

template <typename T>
Matrix<T> Matrix<T>::operator /(const Matrix<T>& matrix) const
{
    if (this->_equalSize(matrix) == false)
    {
        throw SizeError(matrix.getColumns(), matrix.getRows(),
            __FILE__, __LINE__, "Sizes don't match!");
    }

    Matrix<T> tmp(nrows, ncols);

    for (size_t i = 0; i < nrows; i++)
    {
        for (size_t j = 0; j < ncols; j++)
        {
            if (matrix[i][j] != 0)
            {
                tmp[i][j] = (*this)[i][j] / matrix[i][j];
            }
            else
            {
                throw ZeroDivMatrix(i, j, __FILE__, __LINE__);
            }
        }
    }

    return tmp;
}

template <typename T>
Matrix<T> Matrix<T>::operator *(const Matrix<T>& matrix) const
{
    if (this->_CanMultiplyMatrices(matrix) == false)
    {
        throw SizeError(matrix.getColumns(), matrix.getRows(),
            __FILE__, __LINE__, "Sizes don't fit!");
    }

    Matrix<T> tmp(this->getColumns(), matrix.getColumns());

    for (size_t i = 0; i < this->getColumns(); i++)
    {
        for (size_t j = 0; j < matrix.getColumns(); j++)
        {
            tmp[i][j] = this->_MultiplyRowByColumn(matrix, i, j);
        }
    }

    return tmp;
}

template <typename T>
Matrix<T> Matrix<T>::operator +(const T& val) const noexcept
{
    Matrix<T> tmp(nrows, ncols);

    for (size_t i = 0; i < nrows; i++)
    {
        for (size_t j = 0; j < ncols; j++)
        {
            tmp[i][j] = (*this)[i][j] + val;
        }
    }

    return tmp;
}

template <typename T>
Matrix<T> Matrix<T>::operator -(const T& val) const noexcept
{
    Matrix<T> tmp(nrows, ncols);

    for (size_t i = 0; i < nrows; i++)
    {
        for (size_t j = 0; j < ncols; j++)
        {
            tmp[i][j] = (*this)[i][j] - val;
        }
    }

    return tmp;
}

template <typename T>
Matrix<T> Matrix<T>::operator *(const T& val) const noexcept
{
    Matrix<T> tmp(nrows, ncols);

    for (size_t i = 0; i < nrows; i++)
    {
        for (size_t j = 0; j < ncols; j++)
        {
            tmp[i][j] = (*this)[i][j] * val;
        }
    }

    return tmp;
}

template <typename T>
Matrix<T> Matrix<T>::operator /(const T& val) const
{
    if (val == 0)
    {
        throw ZeroDivMatrix(0, 0, __FILE__, __LINE__);
    }

    Matrix<T> tmp(nrows, ncols);

    for (size_t i = 0; i < nrows; i++)
    {
        for (size_t j = 0; j < ncols; j++)
        {
            tmp[i][j] = (*this)[i][j] / val;
        }
    }

    return tmp;
}

template <typename T>
Matrix<T>& Matrix<T>::operator +=(const T& val) noexcept
{
    *this = operator+(val);

    return *this;
}

template <typename T>
Matrix<T>& Matrix<T>::operator -=(const T& val) noexcept
{
    *this = operator-(val);

    return *this;
}

template <typename T>
Matrix<T>& Matrix<T>::operator *=(const T& val) noexcept
{
    *this = operator*(val);

    return *this;
}

template <typename T>
Matrix<T>& Matrix<T>::operator /=(const T& val)
{
    *this = operator/(val);

    return *this;
}

template <typename T>
Matrix<T>& Matrix<T>::operator +=(const Matrix<T>& matrix)
{
    *this = operator+(matrix);

    return *this;
}

template <typename T>
Matrix<T>& Matrix<T>::operator -=(const Matrix<T>& matrix)
{
    *this = operator-(matrix);

    return *this;
}

template <typename T>
Matrix<T>& Matrix<T>::operator *=(const Matrix<T>& matrix)
{
    *this = operator*(matrix);

    return *this;
}

template <typename T>
Matrix<T>& Matrix<T>::operator /=(const Matrix<T>& matrix)
{
    *this = operator/(matrix);

    return *this;
}

template <typename T>
Matrix<T> Matrix<T>::operator-() const
{
    Matrix<T> tmp(*this);

    for (size_t i = 0; i < nrows; i++)
    {
        for (size_t j = 0; j < ncols; j++)
        {
            tmp[i][j] = -tmp[i][j];
        }
    }

    return tmp;
}

template <typename T>
template<typename T1> decltype(auto) Matrix<T>::operator +(const Matrix<T1>& matrix) const
{
    if (this->_equalSize(matrix) == false)
    {
        throw SizeError(matrix.getColumns(), matrix.getRows(),
            __FILE__, __LINE__, "Sizes don't match!");
    }
    
    Matrix<decltype(this->data[0][0] + matrix[0][0])> tmp(nrows, ncols);

    for (size_t i = 0; i < nrows; i++)
    {
        for (size_t j = 0; j < ncols; j++)
        {
            tmp[i][j] = this->data[i][j] + matrix[i][j];
        }
    }

    return tmp;
}

template <typename T>
template<typename T1> decltype(auto) Matrix<T>::operator -(const Matrix<T1>& matrix) const
{
    if (this->_equalSize(matrix) == false)
    {
        throw SizeError(matrix.getColumns(), matrix.getRows(),
            __FILE__, __LINE__, "Sizes don't match!");
    }

    Matrix<decltype(this->data[0][0] - matrix[0][0])> tmp(nrows, ncols);

    for (size_t i = 0; i < nrows; i++)
    {
        for (size_t j = 0; j < ncols; j++)
        {
            tmp[i][j] = this->data[i][j] - matrix[i][j];
        }
    }

    return tmp;
}

template <typename T>
template<typename T1> decltype(auto) Matrix<T>::operator /(const Matrix<T1>& matrix) const
{
    if (this->_equalSize(matrix) == false)
    {
        throw SizeError(matrix.getColumns(), matrix.getRows(),
            __FILE__, __LINE__, "Sizes don't match!");
    }

    Matrix<decltype(this->data[0][0] + matrix[0][0])> tmp(nrows, ncols);

    for (size_t i = 0; i < nrows; i++)
    {
        for (size_t j = 0; j < ncols; j++)
        {
            if (matrix[i][j] != 0)
            {
                tmp[i][j] = this->data[i][j] / matrix[i][j];
            }
            else
            {
                throw ZeroDivMatrix(i, j, __FILE__, __LINE__);
            }
        }
    }

    return tmp;
}

template <typename T>
template<typename T1> decltype(auto) Matrix<T>::operator *(const Matrix<T1>& matrix) const
{
    if (this->_CanMultiplyMatrices(matrix) == false)
    {
        throw SizeError(matrix.getColumns(), matrix.getRows(),
            __FILE__, __LINE__, "Sizes don't fit!");
    }

    Matrix<decltype(this->data[0][0] * matrix[0][0])> tmp(nrows, ncols);

    for (size_t i = 0; i < nrows; i++)
    {
        for (size_t j = 0; j < ncols; j++)
        {
            for (size_t k = 0; k < ncols; k++)
            {
                tmp[i][j] += this->data[i][k] * matrix[k][j];
            }
        }
    }

    return tmp;
}

template <typename T>
template<typename T1> decltype(auto)  Matrix<T>::operator +(const T1& val) const noexcept
{
    Matrix<decltype(this->data[0][0] + val)> tmp(nrows, ncols);

    for (size_t i = 0; i < nrows; i++)
    {
        for (size_t j = 0; j < ncols; j++)
        {
            tmp[i][j] = this->data[i][j] + val;
        }
    }

    return tmp;
}

template <typename T>
template<typename T1> decltype(auto)  Matrix<T>::operator -(const T1& val) const noexcept
{
    Matrix<decltype(this->data[0][0] - val)> tmp(nrows, ncols);

    for (size_t i = 0; i < nrows; i++)
    {
        for (size_t j = 0; j < ncols; j++)
        {
            tmp[i][j] = this->data[i][j] - val;
        }
    }

    return tmp;
}

template <typename T>
template<typename T1> decltype(auto)  Matrix<T>::operator *(const T1& val) const noexcept
{
    Matrix<decltype(this->data[0][0] * val)> tmp(nrows, ncols);

    for (size_t i = 0; i < nrows; i++)
    {
        for (size_t j = 0; j < ncols; j++)
        {
            tmp[i][j] = this->data[i][j] * val;
        }
    }

    return tmp;
}

template <typename T>
template<typename T1> decltype(auto) Matrix<T>::operator /(const T1& val) const
{
    if (val == 0)
    {
        throw ZeroDivMatrix(0, 0, __FILE__, __LINE__);
    }

    Matrix<decltype(this->data[0][0] / val)> tmp(nrows, ncols);

    for (size_t i = 0; i < nrows; i++)
    {
        for (size_t j = 0; j < ncols; j++)
        {
            tmp[i][j] = this->data[i][j] / val;
        }
    }

    return tmp;
}

template <typename T>
template<typename T1> Matrix<T>& Matrix<T>::operator -=(const Matrix<T1>& matrix)
{
    *this = operator-(matrix);

    return *this;
}

template <typename T>
template<typename T1> Matrix<T>& Matrix<T>::operator-=(const T1& val) noexcept
{
    *this = operator-(val);

    return *this;
}

template <typename T>
template<typename T1> Matrix<T>& Matrix<T>::operator +=(const Matrix<T1>& matrix)
{
    *this = operator+(matrix);

    return *this;
}

template <typename T>
template<typename T1> Matrix<T>& Matrix<T>::operator+=(const T1& val) noexcept
{
    *this = operator+(val);

    return *this;
}

template <typename T>
template<typename T1> Matrix<T>& Matrix<T>::operator *=(const Matrix<T1>& matrix)
{
    *this = operator*(matrix);

    return *this;
}

template <typename T>
template<typename T1> Matrix<T>& Matrix<T>::operator*=(const T1& val) noexcept
{
    *this = operator*(val);

    return *this;
}

template <typename T>
template<typename T1> Matrix<T>& Matrix<T>::operator /=(const Matrix<T1>& matrix)
{
    *this = operator/(matrix);

    return *this;
}

template <typename T>
template<typename T1> Matrix<T>& Matrix<T>::operator/=(const T1& val)
{
    *this = operator/(val);

    return *this;
}

template <typename T>
template <typename T1> Matrix<T>& Matrix<T>::operator =(const Matrix<T1>& matrix)
{
    nrows = matrix.getRows();
    ncols = matrix.getColumns();
    this->data = _allocateMatrix(nrows, ncols);

    for (size_t i = 0; i < nrows; i++)
    {
        for (size_t j = 0; j < ncols; j++)
        {
            (this->data)[i][j] = matrix[i][j];
        }
    }

    return *this;
}

template <typename T>
template <typename T1> Matrix<T>& Matrix<T>::operator =(Matrix<T1>&& matrix) noexcept
{
    nrows = matrix.getRows();
    ncols = matrix.getColumns();
    this->data = _allocateMatrix(nrows, ncols);

    for (size_t i = 0; i < nrows; i++)
    {
        for (size_t j = 0; j < ncols; j++)
        {
            (this->data)[i][j] = matrix[i][j];
        }
    }

    matrix.data = nullptr;

    return *this;
}