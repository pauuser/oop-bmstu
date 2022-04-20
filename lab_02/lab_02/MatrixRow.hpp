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
SharedPtr<T[]> Matrix<T>::MatrixRow::_allocateRow(size_t size)
{
	SharedPtr<T[]> data = nullptr;

	try
	{
		data.reset(new T[size]);
	}
	catch (std::bad_alloc& err)
	{
		throw MemoryError(__FILE__, __LINE__, "_allocateMatrix failed.");
	}

	return data;
}

template <typename T>
Matrix<T>::MatrixRow::MatrixRow(const Matrix<T>::MatrixRow& row)
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
Matrix<T>::MatrixRow::MatrixRow(Matrix<T>::MatrixRow&& row)
{
	this->length = row.length;
	this->data.reset(row.data);
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
Matrix<T>::MatrixRow& Matrix<T>::MatrixRow::operator=(MatrixRow&& row)
{
	this->length = row.getLength();
	this->data.reset(row.data);

	return *this;
}

template <typename T>
void Matrix<T>::MatrixRow::fillValue(T& value)
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
void Matrix<T>::MatrixRow::reset(T* newdata, size_t size)
{
	this->data.reset(newdata);
	this->length = size;
}