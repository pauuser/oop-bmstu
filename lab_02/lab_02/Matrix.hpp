#include "Matrix.h"

/*
* Конструкторы
*/

template <typename T>
Matrix<T>::Matrix(size_t rows, size_t cols, const T& fill_value) : BaseMatrix(rows, cols)
{
	if (rows < 1 || cols < 1)
	{
		throw SizeError(rows, cols, __FILE__, __LINE__);
	}

	data = _allocateMatrix(rows, cols);

	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			data[i][j] = fill_value;
		}
	}
}

template <typename T>
Matrix<T>::Matrix(std::initializer_list<std::initializer_list<T>> values)
{
	size_t rows = values.size();

	auto first = values.begin();
	size_t cols = first->size();

	// Проверка на корректность
	for (const auto &line : values)
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
}

/*
* Копирование и перенос
*/

template <typename T>
Matrix<T>::Matrix(const Matrix<T>& matrix) : BaseMatrix(matrix.getRows(), matrix.getColumns())
{
	this->data = _allocateMatrix(nrows, ncols);
	
	for (size_t i = 0; i < nrows; i++)
	{
		for (size_t j = 0; j < ncols; j++)
		{
			data[i][j] = matrix[i][j];
		}
	}
}

template <typename T>
Matrix<T>::Matrix(Matrix<T>&& matrix) : BaseMatrix(matrix.getRows(), matrix.getColumns())
{
	this->data = matrix.data;
	matrix.data = nullptr;
}

/*
* Деструктор
*/

template <typename T>
Matrix<T>::~Matrix()
{
	if (bool(*this))
	{
		for (size_t i = 0; i < nrows; i++)
		{
			data[i].reset();
		}
		data.reset();
		nrows = 0;
		ncols = 0;
	}
}

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
Matrix<T>& Matrix<T>::operator =(Matrix<T>&& matrix)
{
	nrows = matrix.getRows();
	ncols = matrix.getColumns();
	this->data = matrix.data;
	matrix.data = nullptr;

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

/*
* Создание разных матриц
*/
template <typename T>
Matrix<T>& Matrix<T>::DiagonalMatrix(const size_t size, const T& diag_val)
{
	if (size <= 0)
	{
		throw SizeError(size, size, __FILE__, __LINE__);
	}

	T fill = 0;
	Matrix<T> matr(size, size, fill);

	for (size_t i = 0; i < size; i++)
	{
		matr[i][i] = diag_val;
	}

	*this = matr;

	return *this;
}

/*
* Операторы равенства и неравенства
*/
template <typename T>
bool Matrix<T>::equals(const Matrix<T>& matrix) const
{
	bool ans = true;

	if (matrix.nrows != this->nrows || matrix.ncols != this->ncols)
	{
		ans = false;
	}

	for (size_t i = 0; ans == true && i < nrows; i++)
	{
		for (size_t j = 0; ans == true && j < ncols; j++)
		{
			if (matrix.data[i][j] != this->data[i][j])
			{
				ans = false;
			}
		}
	}

	return ans;
}

template <typename T>
bool Matrix<T>::operator ==(const Matrix<T>& matrix) const
{
	return this->equals(matrix);
}

template <typename T>
bool Matrix<T>::unequals(const Matrix<T>& matrix) const
{
	bool ans = false;

	if (matrix.nrows != this->nrows || matrix.ncols != this->ncols)
	{
		ans = true;
	}

	for (size_t i = 0; ans == false && i < nrows; i++)
	{
		for (size_t j = 0; ans == false && j < ncols; j++)
		{
			if (matrix.data[i][j] != this->data[i][j])
			{
				ans = true;
			}
		}
	}

	return ans;
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

template <typename T>
bool Matrix<T>::_isMatrixIndValid(size_t ind) const
{
	bool ans = true;

	if (ind < 0 || ind >= nrows)
	{
		ans = false;
	}

	return ans;
}

template <typename T>
Matrix<T>::operator bool() const
{
	return nrows && ncols && (data != nullptr);
}

template <typename T>
bool Matrix<T>::_equalSize(const Matrix<T>& matr) const
{
	bool ans = false;

	if (this->getColumns() == matr.getColumns() && this->getRows() == matr.getRows())
	{
		ans = true;
	}

	return ans;
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
Matrix<T>& Matrix<T>::addMatrix(const Matrix<T>& matrix)
{
	*this = operator+(matrix);

	return *this;
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
Matrix<T>& Matrix<T>::subMatrix(const Matrix<T>& matrix)
{
	*this = operator-(matrix);

	return *this;
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
Matrix<T>& Matrix<T>::divMatrix(const Matrix<T>& matrix)
{
	*this = operator/(matrix);

	return *this;
}

template <typename T>
T Matrix<T>::_MultiplyRowByColumn(const Matrix<T>& matrix, const size_t row, const size_t col) const
{
	T ans = {};
	for (size_t i = 0; i < matrix.getRows(); i++)
	{
		ans += (*this)[row][i] * matrix[i][col];
	}

	return ans;
}

template <typename T>
bool Matrix<T>::_CanMultiplyMatrices(const Matrix<T>& matr) const
{
	bool ans = false;

	if (this->getColumns() == matr.getRows())
	{
		ans = true;
	}

	return ans;
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
Matrix<T>& Matrix<T>::mulMatrix(const Matrix<T>& matrix)
{
	*this = operator*(matrix);

	return *this;
}

template <typename T>
Matrix<T>& Matrix<T>::dot(const Matrix<T>& matrix)
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
			tmp[i][j] = (*this)[i][j] * matrix[i][j];
		}
	}

	*this = tmp;

	return *this;
}

template <typename T>
Matrix<T> Matrix<T>::operator +(const T& val) const
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
Matrix<T> Matrix<T>::operator -(const T& val) const
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
Matrix<T> Matrix<T>::operator *(const T& val) const
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
Matrix<T>& Matrix<T>::addElem(const T& val)
{
	*this = operator+(val);

	return *this;
}

template <typename T>
Matrix<T>& Matrix<T>::subElem(const T& val)
{
	*this = operator-(val);

	return *this;
}

template <typename T>
Matrix<T>& Matrix<T>::mulElem(const T& val)
{
	*this = operator*(val);

	return *this;
}

template <typename T>
Matrix<T>& Matrix<T>::divElem(const T& val)
{
	*this = operator/(val);

	return *this;
}
