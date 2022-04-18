#include "Matrix.h"
#include "PrivateMatrix.hpp"

/*
* Конструкторы
*/

template <typename T>
Matrix<T>::Matrix(size_t rows, size_t cols) : BaseMatrix(rows, cols)
{
	data = _allocateMatrix(rows, cols);
}

template <typename T>
Matrix<T>::Matrix(size_t rows, size_t cols, T& fill_value) : BaseMatrix(rows, cols)
{
	data = _allocateMatrix(rows, cols);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
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
	size_t cols = iter->size();

	// Проверка на корректность
	for (const auto &line : values)
	{
		if (line.size() != cols)
		{
			time_t curtime = time(NULL);
			auto fmt_time = localtime(&curtime);
			throw InitError(asctime(fmt_time), __FILE__, __LINE__, "Bad initialiser list.");
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
			j++
		}
		i++;
	}
}

/*
* Копирование и перенос
*/

template <typename T>
Matrix<T>::Matrix(const Matrix& matrix) : BaseMatrix(matrix.getRows(), matrix.getColumns())
{
	
}