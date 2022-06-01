#include <ostream>

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

template <typename T>
void Matrix<T>::_checkPointer(T** cptr, const size_t len)
{
    if (!cptr)
    {
        throw InitError(__FILE__, __LINE__, "Bad pointer!");
    }

    for (size_t i = 0; i < len; i++)
    {
        if (!cptr[i])
        {
            throw InitError(__FILE__, __LINE__, "Bad pointer!");
        }

    }
}

template <typename T>
Matrix<T>::Matrix(T** cdata, const size_t rows, const size_t cols) : BaseMatrix(rows, cols)
{
    _checkPointer(cdata, rows);

    this->data = _allocateMatrix(rows, cols);

    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            this->data[i][j] = cdata[i][j];
        }
    }
}

/*
* Копирование и перенос
*/

template <typename T>
Matrix<T>::Matrix(const Matrix<T>& matrix) : BaseMatrix(matrix.nrows, matrix.ncols)
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
Matrix<T>::Matrix(Matrix<T>&& matrix) noexcept : BaseMatrix(matrix.nrows, matrix.ncols)
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

template <typename T>
Matrix<T> Matrix<T>::DiagonalMatrix(const size_t size, const T& diag_val)
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

    return matr;
}

template <typename T>
Matrix<T>::operator bool() const
{
    return nrows && ncols && (data != nullptr);
}

template<typename T>
Iterator<T> Matrix<T>::begin()
{
    return Iterator<T>(*this, 0, 0);
}

template<typename T>
Iterator<T> Matrix<T>::end()
{
    return ++Iterator<T>(*this, nrows - 1, ncols - 1);
}

template<typename T>
ConstIterator<T> Matrix<T>::begin() const
{
    return ConstIterator<T>(*this, 0, 0);
}

template<typename T>
ConstIterator<T> Matrix<T>::end() const
{
    return ++ConstIterator<T>(*this, nrows - 1, ncols - 1);
}

template<typename T>
ConstIterator<T> Matrix<T>::cbegin() const
{
    return ConstIterator<T>(*this, 0, 0);
}

template<typename T>
ConstIterator<T> Matrix<T>::cend() const
{
    return ++ConstIterator<T>(*this, nrows - 1, ncols - 1);
}

template<typename T>
void Matrix<T>::fill(Iterator<T>& start, const Iterator<T>& end, T& fill_value)
{
    for (Iterator<T> it = start; it < end; it++)
    {
        *it = fill_value;
    }
}

template<typename T>
Matrix<T> operator +(const T& elem, const Matrix<T>& matr)
{
    return matr + elem;
}

template<typename T>
Matrix<T> operator *(const T& elem, const Matrix<T>& matr)
{
    return matr * elem;
}

template<typename T>
Matrix<T> operator -(const T& elem, const Matrix<T>& matr)
{
    return (-matr) + elem;
}

template<typename T>
std::ostream& operator <<(std::ostream& os, const Matrix<T>& matr)
{
    if (matr.getRows() == 0 && matr.getColumns() == 0)
    {
        os << "Empty matrix!" << std::endl;
    }
    else if (bool(matr) == 0)
    {
        os << "Empty matrix! But with m = " << matr.getRows() 
           << " n = " << matr.getColumns() << std::endl;
    }
    else
    {
        for (size_t i = 0; i < matr.getRows(); i++)
        {
            for (size_t j = 0; j < matr.getColumns(); j++)
            {
                os << matr[i][j] << "\t";
            }
            os << std::endl;
        }
    }

    return os;
}


