#include "Matrix.h"
#include "Exceptions.h"

#include <time.h>

template <typename T>
using SharedPtr = std::shared_ptr<T>;

template <typename T>
SharedPtr<typename Matrix<T>::MatrixRow[]> Matrix<T>::_allocateMatrix(const size_t rows, const size_t cols)
{
	SharedPtr<MatrixRow[]> data = nullptr;

	try
	{
		data.reset(new MatrixRow[rows]);
		for (int i = 0; i < rows; i++)
		{
			data[i].reset(new T[cols]);
		}
	}
	catch (std::bad_alloc& err)
	{
		time_t curtime = time(NULL);
		auto fmt_time = localtime(&curtime);
		throw MemoryError(asctime(fmt_time), __FILE__, __LINE__, "_allocateMatrix failed.");
	}
}