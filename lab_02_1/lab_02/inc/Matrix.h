#pragma once

#include <iostream>

#include "BaseMatrix.h"
#include "Exceptions.h"
#include "Iterator.h"
#include "ConstIterator.h"

template <typename T>
using SharedPtr = std::shared_ptr<T>;

template <typename T>
class Matrix : public BaseMatrix
{
public:
    class MatrixRow;
    friend Iterator<T>;
    friend ConstIterator<T>;

public:
    Matrix() = default;
    Matrix(size_t rows, size_t cols, const T& fill_value = {});
    Matrix(std::initializer_list<std::initializer_list<T>> values);
    Matrix(T **cdata, const size_t rows, const size_t cols);

    explicit Matrix(const Matrix& matrix);
    Matrix(Matrix&& matrix) noexcept;

    ~Matrix();

    Matrix<T>& operator =(const Matrix<T>& matrix);
    Matrix<T>& operator =(Matrix<T>&& matrix) noexcept;
    Matrix<T>& operator =(std::initializer_list<std::initializer_list<T>> values);

    template <typename T1> Matrix<T>& operator =(const Matrix<T1>& matrix);
    template <typename T1> Matrix<T>& operator =(Matrix<T1>&& matrix) noexcept;

    static Matrix<T> DiagonalMatrix(const size_t size, const T& diag_val); 

    bool equals(const Matrix<T>& matrix) const;
    bool operator ==(const Matrix<T>& matrix) const;

    bool unequals(const Matrix<T>& matrix) const;
    bool operator !=(const Matrix<T>& matrix) const;

    explicit virtual operator bool() const;

    Matrix<T> operator +(const Matrix<T>& matrix) const;
    Matrix<T> operator +(const T& val) const noexcept;
    Matrix<T>& addMatrix(const Matrix<T>& matrix);
    Matrix<T>& addElem(const T& val) noexcept;
    template<typename T1> decltype(auto) operator +(const Matrix<T1>& matrix) const;
    template<typename T1> decltype(auto) operator +(const T1& val) const noexcept;
    template<typename T1> decltype(auto) addMatrix(const Matrix<T1>& matrix);
    template<typename T1> decltype(auto) addElem(const T1& val) noexcept;

    Matrix<T>& operator +=(const T& val) noexcept;
    Matrix<T>& operator +=(const Matrix<T>& matrix);
    template<typename T1> Matrix<T>& operator +=(const Matrix<T1>& matrix);
    template<typename T1> Matrix<T>& operator +=(const T1& val) noexcept;

    Matrix<T> operator -(const Matrix<T>& matrix) const;
    Matrix<T> operator -(const T& val) const noexcept;
    Matrix<T>& subMatrix(const Matrix<T>& matrix);
    Matrix<T>& subElem(const T& val) noexcept;
    template<typename T1> decltype(auto) operator -(const Matrix<T1>& matrix) const;
    template<typename T1> decltype(auto) operator -(const T1& val) const noexcept;
    template<typename T1> decltype(auto) subMatrix(const Matrix<T1>& matrix);
    template<typename T1> decltype(auto) subElem(const T1& val) noexcept;

    Matrix<T>& operator -=(const T& val) noexcept;
    Matrix<T>& operator -=(const Matrix<T>& matrix);
    template<typename T1> Matrix<T>& operator -=(const Matrix<T1>& matrix);
    template<typename T1> Matrix<T>& operator -=(const T1& val) noexcept;

    Matrix<T> operator *(const Matrix<T>& matrix) const;
    Matrix<T> operator *(const T& val) const noexcept;
    Matrix<T>& mulMatrix(const Matrix<T>& matrix);
    Matrix<T>& mulElem(const T& val) noexcept;
    Matrix<T>& dot(const Matrix<T>& matrix);
    template<typename T1> decltype(auto) operator *(const Matrix<T1>& matrix) const;
    template<typename T1> decltype(auto) operator *(const T1& val) const noexcept;
    template<typename T1> decltype(auto) mulMatrix(const Matrix<T1>& matrix);
    template<typename T1> decltype(auto) mulElem(const T1& val) noexcept;
    template<typename T1> decltype(auto) dot(const Matrix<T1>& matrix);

    Matrix<T>& operator *=(const T& val) noexcept;
    Matrix<T>& operator *=(const Matrix<T>& matrix);
    template<typename T1> Matrix<T>& operator *=(const Matrix<T1>& matrix);
    template<typename T1> Matrix<T>& operator *=(const T1& val) noexcept;

    Matrix<T> operator /(const Matrix<T>& matrix) const;
    Matrix<T> operator /(const T& val) const;
    Matrix<T>& divMatrix(const Matrix<T>& matrix);
    Matrix<T>& divElem(const T& val);
    template<typename T1> decltype(auto) operator /(const Matrix<T1>& matrix) const;
    template<typename T1> decltype(auto) operator /(const T1& val) const;
    template<typename T1> decltype(auto) divMatrix(const Matrix<T1>& matrix);
    template<typename T1> decltype(auto) divElem(const T1& val);
    
    Matrix<T>& operator /=(const T& val);
    Matrix<T>& operator /=(const Matrix<T>& matrix);
    template<typename T1> Matrix<T>& operator /=(const Matrix<T1>& matrix);
    template<typename T1> Matrix<T>& operator /=(const T1& val);

    MatrixRow& operator[](const size_t ind);
    const MatrixRow& operator[](const size_t ind) const;
 
    Matrix<T> operator-() const; // Смена знака
    Matrix<T>& neg();

    Matrix<T>& abs();			 // модуль

    T determinant() const;		 // определитель
    Matrix<T> transpose();		 // транспонирование
    void horizontal_mirror();	 // отражение по горизонтали
    void vertical_mirror();		 // отражение по вертикали
    void rotate_right();		 // поворот на 90 градусов вправо
    void rotate_left();			 // поворот на 90 градусов влево

    Matrix<T> inverse();		 // обратная матрица

    void insertRow(const size_t before_ind, const T& fill_value = {});
    void insertCol(const size_t before_ind, const T& fill_value = {});
    void deleteRow(const size_t ind);
    void deleteCol(const size_t ind);

    void resize(const size_t new_row, const size_t new_col, const T& fill_value = {});
    void resizeColumns(const size_t new_col, const T& fill_value = {});
    void resizeRows(const size_t new_row, const T& fill_value = {});

    Iterator<T> begin();
    Iterator<T> end();

    ConstIterator<T> begin() const;
    ConstIterator<T> end() const;

    ConstIterator<T> cbegin() const;
    ConstIterator<T> cend() const;

    void fill(Iterator<T>& start, const Iterator<T>& end, T& fill_value = {});

private:
    SharedPtr<MatrixRow[]> data = nullptr;

    SharedPtr<MatrixRow[]> _allocateMatrix(const size_t rows, const size_t cols);

    bool _isMatrixIndValid(const size_t ind) const;
    bool _equalSize(const Matrix<T>& matr) const;
    template<typename T1> bool _equalSize(const Matrix<T1>& matr) const;
    bool _CanMultiplyMatrices(const Matrix<T>& matr) const;
    template<typename T1> bool _CanMultiplyMatrices(const Matrix<T1>& matr) const;
    void _cleanRows();
    void _checkPointer(T** cptr, const size_t len);

    T _MultiplyRowByColumn(const Matrix<T>& matrix, const size_t row, const size_t col) const;
    Matrix<T>& _excludeRowAndColumn(const size_t i, const size_t j);

public:
    class MatrixRow
    {
    private:
        size_t length = 0;
        SharedPtr<T[]> data = nullptr;
    public:
        MatrixRow(): length(0), data(nullptr) {};
        MatrixRow(std::initializer_list<T>);
        MatrixRow(T *cdata, const size_t len);

        MatrixRow(const MatrixRow& row);
        MatrixRow(MatrixRow&& row) noexcept;

        T& operator[](const size_t index);
        const T& operator[](const size_t index) const;

        MatrixRow& operator=(const MatrixRow& row);
        MatrixRow& operator=(MatrixRow&& row) noexcept;
        MatrixRow& operator=(std::initializer_list<T> values);
        
        MatrixRow& operator+=(const MatrixRow& row);
        MatrixRow& operator-=(const MatrixRow& row);

        MatrixRow operator+(const MatrixRow& row) const;
        MatrixRow operator-(const MatrixRow& row) const;

        MatrixRow& operator*=(const T&val) noexcept;
        MatrixRow& operator+=(const T& val) noexcept;
        MatrixRow& operator-=(const T& val) noexcept;
        MatrixRow& operator/=(const T& val);

        MatrixRow operator*(const T& val) const noexcept;
        MatrixRow operator+(const T& val) const noexcept;
        MatrixRow operator-(const T& val) const noexcept;
        MatrixRow operator/(const T& val) const;

        void fillValue(const T& value);
        void reset();
        void reset(T* newdata, const size_t size);

        size_t getLength() const { return length; };

        ~MatrixRow();
    private:
        SharedPtr<T[]> _allocateRow(const size_t size);

        bool _isIndexValid(const size_t index) const;
        bool _canAdd(const MatrixRow& row) const;
        void _checkPointer(T *cptr);
    };

};

#include "Matrix.hpp"
#include "MatrixPrivate.hpp"
#include "MatrixRow.hpp"
#include "MatrixOperators.hpp"
#include "MatrixMath.hpp"
#include "MatrixTransformations.hpp"

