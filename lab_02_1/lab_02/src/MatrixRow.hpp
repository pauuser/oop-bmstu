#include "Matrix.h"
#include <iostream>

template <typename T>
Matrix<T>::MatrixRow::MatrixRow(std::initializer_list<T> row)
{
    SharedPtr<T[]> newrow = _allocateRow(row.getLength());
    this->length = row.getLength();

    for (size_t i = 0; i < this->length; i++)
    {
        newrow[i] = row[i];
    }

    this->data.reset(newrow);
}

template <typename T>
void Matrix<T>::MatrixRow::_checkPointer(T* cptr)
{
    if (!cptr)
    {
        throw InitError(__FILE__, __LINE__, "Bad pointer!");
    }
}

template <typename T>
Matrix<T>::MatrixRow::MatrixRow(T* cdata, const size_t len)
{
    _checkPointer(cdata);

    this->data = cdata;
    this->length = len;
}

template <typename T>
bool Matrix<T>::MatrixRow::_isIndexValid(const size_t index) const
{
    bool ans = true;

    if (index < 0 || index >= this->length)
    {
        ans = false;
    }

    return ans;
}

template <typename T>
T& Matrix<T>::MatrixRow::operator[](const size_t index)
{
    if (_isIndexValid(index) == false)
    {
        throw IndexOutOfRange(index, __FILE__, __LINE__, "Column index fail!");
    }
    
    return this->data[index];
}

template <typename T>
const T& Matrix<T>::MatrixRow::operator[](const size_t index) const
{
    if (_isIndexValid(index) == false)
    {
        throw IndexOutOfRange(index, __FILE__, __LINE__, "Column index fail!");
    }

    return this->data[index];
}

template <typename T>
SharedPtr<T[]> Matrix<T>::MatrixRow::_allocateRow(const size_t size)
{
    SharedPtr<T[]> data = nullptr;

    try
    {
        data.reset(new T[size]);
    }
    catch (std::bad_alloc&)
    {
        throw MemoryError(__FILE__, __LINE__, "_allocateMatrix failed.");
    }

    return data;
}

template <typename T>
Matrix<T>::MatrixRow::MatrixRow(const Matrix<T>::MatrixRow& row)
{
    SharedPtr<T[]> newrow = _allocateRow(row.getLength());
    length = row.getLength();

    for (size_t i = 0; i < this->length; i++)
    {
        newrow[i] = row[i];
    }

    data = newrow;
}

template <typename T>
Matrix<T>::MatrixRow::MatrixRow(Matrix<T>::MatrixRow&& row) noexcept
{
    length = row.length;
    data = row.data;
}

template <typename T>
Matrix<T>::MatrixRow& Matrix<T>::MatrixRow::operator=(std::initializer_list<T> values)
{
    size_t len = values.size();

    if (len == 0)
    {
        throw InitError(__FILE__, __LINE__, "Bad initialiser list.");
    }

    data.reset(_allocateRow(len));
    length = len;

    size_t i = 0;
    for (const auto& val : values)
    {
        data[i] = val;
        i++;
    }

    return *this;
}

template <typename T>
Matrix<T>::MatrixRow& Matrix<T>::MatrixRow::operator=(const Matrix<T>::MatrixRow& row)
{
    SharedPtr<T[]> newrow = _allocateRow(row.getLength());
    this->length = row.getLength();

    for (size_t i = 0; i < this->length; i++)
    {
        newrow[i] = row[i];
    }

    this->data.reset(newrow);

    return *this;
}

template <typename T>
Matrix<T>::MatrixRow& Matrix<T>::MatrixRow::operator=(MatrixRow&& row) noexcept
{
    this->length = row.length;
    this->data.reset(row.data);

    return *this;
}

template <typename T>
void Matrix<T>::MatrixRow::fillValue(const T& value)
{
    for (size_t i = 0; i < length; i++)
    {
        this->data[i] = value;
    }
}

template <typename T>
Matrix<T>::MatrixRow::~MatrixRow()
{
    this->data.reset();
    this->length = 0;
}

template <typename T>
void Matrix<T>::MatrixRow::reset()
{
    this->data.reset();
    this->length = 0;
}

template <typename T>
void Matrix<T>::MatrixRow::reset(T* newdata, const size_t size)
{
    this->data.reset(newdata);
    this->length = size;
}

template <typename T>
Matrix<T>::MatrixRow& Matrix<T>::MatrixRow::operator+=(const MatrixRow& row)
{
    if (_canAdd(row) == false)
    {
        throw SizeError(length, row.length, __FILE__, __LINE__, "Rows have different size!");
    }

    for (size_t i = 0; i < length; i++)
    {
        data[i] += row[i];
    }

    return *this;
}

template <typename T>
bool Matrix<T>::MatrixRow::_canAdd(const MatrixRow& row) const
{
    bool ans = false;

    if (row.length == length)
    {
        ans = true;
    }

    return ans;
}

template <typename T>
Matrix<T>::MatrixRow& Matrix<T>::MatrixRow::operator+=(const T& val) noexcept
{
    for (size_t i = 0; i < length; i++)
    {
        data[i] += val;
    }

    return *this;
}

template <typename T>
Matrix<T>::MatrixRow& Matrix<T>::MatrixRow::operator-=(const T& val) noexcept
{
    for (size_t i = 0; i < length; i++)
    {
        data[i] -= val;
    }

    return *this;
}

template <typename T>
Matrix<T>::MatrixRow& Matrix<T>::MatrixRow::operator/=(const T& val)
{
    if (val == 0)
    {
        throw ZeroDivMatrix(0, 0, __FILE__, __LINE__);
    }
    for (size_t i = 0; i < length; i++)
    {
        data[i] /= val;
    }

    return *this;
}

template <typename T>
Matrix<T>::MatrixRow& Matrix<T>::MatrixRow::operator*=(const T& val) noexcept
{
    for (size_t i = 0; i < length; i++)
    {
        data[i] *= val;
    }

    return *this;
}

template <typename T>
Matrix<T>::MatrixRow& Matrix<T>::MatrixRow::operator-=(const Matrix<T>::MatrixRow& row)
{
    if (_canAdd(row) == false)
    {
        throw SizeError(length, row.length, __FILE__, __LINE__, "Rows have different size!");
    }

    for (size_t i = 0; i < length; i++)
    {
        data[i] -= row[i];
    }

    return *this;
}

template <typename T>
Matrix<T>::MatrixRow Matrix<T>::MatrixRow::operator*(const T& val) const noexcept
{
    MatrixRow temp = *this;

    for (size_t i = 0; i < temp.getLength(); i++)
    {
        temp[i] *= val;
    }

    return temp;
}

template <typename T>
Matrix<T>::MatrixRow Matrix<T>::MatrixRow::operator+(const T& val) const noexcept
{
    MatrixRow temp = *this;

    for (size_t i = 0; i < temp.getLength(); i++)
    {
        temp[i] *= val;
    }

    return temp;
}

template <typename T>
Matrix<T>::MatrixRow Matrix<T>::MatrixRow::operator-(const T& val) const noexcept
{
    MatrixRow temp = *this;

    for (size_t i = 0; i < temp.getLength(); i++)
    {
        temp[i] -= val;
    }

    return temp;
}

template <typename T>
Matrix<T>::MatrixRow Matrix<T>::MatrixRow::operator/(const T& val) const
{
    if (val == 0)
    {
        throw SizeError(0, 0, __FILE__, __LINE__, "Rows have different size!");
    }

    MatrixRow temp = *this;

    for (size_t i = 0; i < temp.getLength(); i++)
    {
        temp[i] *= val;
    }

    return temp;
}

template <typename T>
Matrix<T>::MatrixRow Matrix<T>::MatrixRow::operator+(const MatrixRow& row) const
{
    if (_canAdd(row) == false)
    {
        throw SizeError(length, row.length, __FILE__, __LINE__, "Rows have different size!");
    }

    MatrixRow temp = *this;

    for (size_t i = 0; i < length; i++)
    {
        temp.data[i] += row[i];
    }

    return temp;
}

template <typename T>
Matrix<T>::MatrixRow Matrix<T>::MatrixRow::operator-(const MatrixRow& row) const
{
    if (_canAdd(row) == false)
    {
        throw SizeError(length, row.length, __FILE__, __LINE__, "Rows have different size!");
    }

    MatrixRow temp = *this;

    for (size_t i = 0; i < length; i++)
    {
        temp.data[i] += row[i];
    }

    return temp;
}