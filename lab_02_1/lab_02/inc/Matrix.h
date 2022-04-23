#pragma once

#include <iostream>

#include "BaseMatrix.h"
#include "Exceptions.h"

#include "Iterator.hpp"
#include "ConstIterator.hpp"

template <typename T>
using SharedPtr = std::shared_ptr<T>;

template <typename T>
class Matrix : public BaseMatrix
{
public:
	class MatrixRow;
	friend Iterator<T>; // У итератора будет доступ к членам-данным матрицы
	friend ConstIterator<T>;

public:
	Matrix() = default;
	Matrix(size_t rows, size_t cols, const T& fill_value = {});
	Matrix(std::initializer_list<std::initializer_list<T>> values);

	explicit Matrix(const Matrix& matrix);
	Matrix(Matrix&& matrix);

	~Matrix();

	Matrix<T>& operator =(const Matrix<T>& matrix);
	Matrix<T>& operator =(Matrix<T>&& matrix);
	Matrix<T>& operator =(std::initializer_list<std::initializer_list<T>> values);

	Matrix<T>& DiagonalMatrix(const size_t size, const T& diag_val); 

	bool equals(const Matrix<T>& matrix) const;
	bool operator ==(const Matrix<T>& matrix) const;

	bool unequals(const Matrix<T>& matrix) const;
	bool operator !=(const Matrix<T>& matrix) const;

	explicit virtual operator bool() const;

	Matrix<T> operator +(const Matrix<T>& matrix) const;
	Matrix<T> operator -(const Matrix<T>& matrix) const;
	Matrix<T> operator *(const Matrix<T>& matrix) const;
	Matrix<T> operator /(const Matrix<T>& matrix) const;

	Matrix<T>& addMatrix(const Matrix<T>& matrix);
	Matrix<T>& mulMatrix(const Matrix<T>& matrix);
	Matrix<T>& divMatrix(const Matrix<T>& matrix);
	Matrix<T>& subMatrix(const Matrix<T>& matrix);
	Matrix<T>& dot(const Matrix<T>& matrix);

	Matrix<T> operator +(const T& val) const;
	Matrix<T> operator -(const T& val) const;
	Matrix<T> operator *(const T& val) const;
	Matrix<T> operator /(const T& val) const;

	Matrix<T>& addElem(const T& val);
	Matrix<T>& subElem(const T& val);
	Matrix<T>& divElem(const T& val);
	Matrix<T>& mulElem(const T& val);

	Matrix<T>& operator +=(const T& val);
	Matrix<T>& operator -=(const T& val);
	Matrix<T>& operator *=(const T& val);
	Matrix<T>& operator /=(const T& val);

	Matrix<T>& operator +=(const Matrix<T>& matrix);
	Matrix<T>& operator -=(const Matrix<T>& matrix);
	Matrix<T>& operator *=(const Matrix<T>& matrix);
	Matrix<T>& operator /=(const Matrix<T>& matrix);

	MatrixRow& operator[](const size_t ind);
	const MatrixRow& operator[](const size_t ind) const;
 
	Matrix<T> operator-() const; // Смена знака
	Matrix<T>& neg();

	Matrix<T>& abs();			 // модуль

	T determinant() const;		 // определитель
	void transpose();			 // транспонирование
	void horizontal_mirror();	 // отражение по горизонтали
	void vertical_mirror();		 // отражение по вертикали
	void rotate_right();		 // поворот на 90 градусов вправо
	void rotate_left();			 // поворот на 90 градусов влево

	void inverse();				 // обратная матрица

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
	SharedPtr<MatrixRow[]> _allocateMatrix(const size_t rows, const size_t cols);
	SharedPtr<MatrixRow[]> data = nullptr;

	bool _isMatrixIndValid(size_t ind) const;
	bool _equalSize(const Matrix<T>& matr) const;
	bool _CanMultiplyMatrices(const Matrix<T>& matr) const;
	void _cleanRows();

	T _MultiplyRowByColumn(const Matrix<T>& matrix, const size_t row, const size_t col) const;
	Matrix<T>& _excludeRowAndColumn(size_t i, size_t j);

public:
	class MatrixRow
	{
	private:
		size_t length = 0;
		SharedPtr<T[]> data = nullptr;
	public:
		MatrixRow(): length(0), data(nullptr) {};
		MatrixRow(std::initializer_list<T>);
		MatrixRow(const MatrixRow& row);
		MatrixRow(MatrixRow&& row);

		T& operator[](const size_t index);
		const T& operator[](const size_t index) const;

		MatrixRow& operator=(const MatrixRow& row);
		MatrixRow& operator=(MatrixRow&& row);
		MatrixRow& operator=(std::initializer_list<T> values);
		
		MatrixRow& operator+=(const MatrixRow& row);
		MatrixRow& operator-=(const MatrixRow& row);

		MatrixRow operator+(const MatrixRow& row) const;
		MatrixRow operator-(const MatrixRow& row) const;

		MatrixRow& operator*=(const T&val);
		MatrixRow& operator+=(const T& val);
		MatrixRow& operator-=(const T& val);
		MatrixRow& operator/=(const T& val);

		MatrixRow operator*(const T& val) const;
		MatrixRow operator+(const T& val) const;
		MatrixRow operator-(const T& val) const;
		MatrixRow operator/(const T& val) const;

		void fillValue(T& value);
		void reset();
		void reset(T* newdata, size_t size);

		size_t getLength() const { return length; };

		~MatrixRow();
	private:
		SharedPtr<T[]> _allocateRow(size_t size);

		bool _isIndexValid(const size_t index) const;
		bool _canAdd(const MatrixRow& row) const;
	};

};

#include "PrivateMatrix.hpp"
#include "MatrixRow.hpp"

