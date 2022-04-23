#include "Exceptions.h"
#include "Matrix.h"

template <typename T>
using SharedPtr = std::shared_ptr<T>;

template <typename T>
SharedPtr<typename Matrix<T>::MatrixRow[]> Matrix<T>::_allocateMatrix(const size_t rows, const size_t cols)
{
	SharedPtr<MatrixRow[]> data = nullptr;

	try
	{
		data.reset(new MatrixRow[rows]);
		for (size_t i = 0; i < rows; i++)
		{
			data[i].reset(new T[cols], cols);
		}
	}
	catch (std::bad_alloc&)
	{
		throw MemoryError(__FILE__, __LINE__, "_allocateMatrix failed.");
	}

	return data;
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
bool Matrix<T>::_equalSize(const Matrix<T>& matr) const
{
	bool ans = false;

	if (this->getColumns() == matr.getColumns() && this->getRows() == matr.getRows())
	{
		ans = true;
	}

	return ans;
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
Matrix<T>& Matrix<T>::_excludeRowAndColumn(size_t i, size_t j)
{
	deleteCol(j);
	deleteRow(i);

	return *this;
}

template <typename T>
void Matrix<T>::_cleanRows()
{
	for (size_t i = 0; i < nrows; i++)
	{
		data[i].reset();
	}
}