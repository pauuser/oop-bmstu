#include "Exceptions.h"
#include "Matrix.h"

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
Matrix<T>& Matrix<T>::neg()
{
	*this = operator-();

	return *this;
}

template <typename T>
Matrix<T>& Matrix<T>::abs()
{
	for (T& elem : *this)
	{
		if (elem < 0)
		{
			elem = -elem;
		}
	}
	

	return *this;
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

template <typename T>
Matrix<T>& Matrix<T>::addMatrix(const Matrix<T>& matrix)
{
	*this = operator+(matrix);

	return *this;
}

template <typename T>
Matrix<T>& Matrix<T>::subMatrix(const Matrix<T>& matrix)
{
	*this = operator-(matrix);

	return *this;
}

template <typename T>
Matrix<T>& Matrix<T>::divMatrix(const Matrix<T>& matrix)
{
	*this = operator/(matrix);

	return *this;
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
Matrix<T>& Matrix<T>::addElem(const T& val) noexcept
{
	*this = operator+(val);

	return *this;
}

template <typename T>
Matrix<T>& Matrix<T>::subElem(const T& val) noexcept
{
	*this = operator-(val);

	return *this;
}

template <typename T>
Matrix<T>& Matrix<T>::mulElem(const T& val) noexcept
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

/*
* ��������� ��������� � �����������
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