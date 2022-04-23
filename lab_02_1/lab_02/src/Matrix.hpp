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
}

/*
* Деструктор
*/

template <typename T>
Matrix<T>::~Matrix()
{
	if (bool(*this))
	{
		if (data.use_count() == 1)
		{
			_cleanRows();
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
Matrix<T>::operator bool() const
{
	return nrows && ncols && (data != nullptr);
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

template <typename T>
Matrix<T>& Matrix<T>::operator +=(const T& val)
{
	*this = operator+(val);

	return *this;
}

template <typename T>
Matrix<T>& Matrix<T>::operator -=(const T& val)
{
	*this = operator-(val);

	return *this;
}

template <typename T>
Matrix<T>& Matrix<T>::operator *=(const T& val)
{
	*this = operator+(val);

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
	Matrix<T> tmp(nrows, ncols);
	for (size_t i = 0; i < nrows; i++)
	{
		for (size_t j = 0; j < ncols; j++)
		{
			data[i][j] = -data[i][j];
		}
	}

	return tmp;
}

template <typename T>
Matrix<T>& Matrix<T>::neg()
{
	*this = operator-();

	return *this;
}

template <typename T>
Matrix<T>& Matrix<T>::abs()
{
	for (size_t i = 0; i < nrows; i++)
	{
		for (size_t j = 0; j < ncols; j++)
		{
			data[i][j] = abs(data[i][j]);
		}
	}
}

template <typename T>
T Matrix<T>::determinant() const
{
	if (isSquare() == false)
	{
		throw SizeError(nrows, ncols, __FILE__, __LINE__);
	}

	T det = 1;
	T bottom = 1;

	Matrix copy = Matrix(*this);

	for (size_t i = 0; i < nrows; i++)
	{
		size_t k = i + 1;
		while (data[i][i] == 0 && k < nrows)
		{
			copy[i] += copy[k];
			k++;
		}

		for (size_t j = i + 1; j < nrows; j++)
		{
			if (copy[i][i] != 0)
			{
				copy[j] *= copy[i][i];
				bottom *= copy[i][i];

				T diff = copy[j][i] / copy[i][i];
				copy[j] -= (copy[i] * diff);
			}
		}
	}

	for (size_t i = 0; i < nrows; i++)
	{
		det *= copy[i][i];
	}

	det /= bottom;

	return det;
}

template <typename T>
void Matrix<T>::transpose()
{
	size_t maxsize = 0, rescol = nrows, resrow = ncols;
	(nrows > ncols) ? maxsize = nrows : maxsize = ncols;
	
	this->resize(maxsize, maxsize);

	for (int i = 0; i < nrows; i++)
	{
		for (int j = 0; j < i; j++)
		{
			T tmp = data[i][j];
			data[i][j] = data[j][i];
			data[j][i] = tmp;
		}
	}

	this->resize(resrow, rescol);
}

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

template<typename T>
Iterator<T> Matrix<T>::begin()
{
	return Iterator<T>(*this, 0, 0);
}

template<typename T>
Iterator<T> Matrix<T>::end()
{
	return Iterator<T>(*this, nrows - 1, ncols - 1) + 1;
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
void Matrix<T>::inverse()
{
	if (!isSquare() || (isSquare() && nrows == 1))
	{
		throw SizeError(nrows, ncols, __FILE__, __LINE__, "Can't inverse!");
	}

	T det = determinant();

	if (det == 0)
	{
		throw SingularMatrixError(__FILE__, __LINE__, "Can't inverse!");
	}

	Matrix<T> res(nrows, ncols);
	Matrix tmp = Matrix(*this);

	for (size_t i = 0; i < nrows; i++)
	{
		for (size_t j = 0; j < ncols; j++)
		{
			tmp._excludeRowAndColumn(i, j);
			T minor = tmp.determinant();

			if ((i + j) % 2 == 0)
			{
				res[j][i] = minor / det;
			}
			else
			{
				res[j][i] = -minor / det;
			}
			tmp = Matrix(*this);
		}
	}

	*this = res;
}

template<typename T>
ConstIterator<T> Matrix<T>::begin() const
{
	return ConstIterator<T>(*this, 0, 0);
}

template<typename T>
ConstIterator<T> Matrix<T>::end() const
{
	return ConstIterator<T>(*this, nrows - 1, ncols - 1) + 1;
}

template<typename T>
ConstIterator<T> Matrix<T>::cbegin() const
{
	return ConstIterator<T>(*this, 0, 0);
}

template<typename T>
ConstIterator<T> Matrix<T>::cend() const
{
	return ConstIterator<T>(*this, nrows - 1, ncols - 1) + 1;
}

template<typename T>
void Matrix<T>::fill(Iterator<T>& start, const Iterator<T>& end, T& fill_value)
{
	for (Iterator<T> it = start; it < end; it++)
	{
		*it = fill_value;
	}
}
