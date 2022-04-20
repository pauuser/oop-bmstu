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