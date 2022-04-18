#pragma once

#include <iostream>

#include "BaseMatrix.h"
#include "Iterator.h"
#include "ConstIterator.h"

template <typename T>
using SharedPtr = std::shared_ptr<T>;

template <typename T>
class Matrix : public BaseMatrix
{
public:
	class MatrixRow;
	friend Iterator<T>; // � ��������� ����� ������ � ������-������ �������
	friend ConstIterator<T>;
public:
	// ������������
	explicit Matrix(size_t rows = 0, size_t cols = 0);
	Matrix(size_t rows, size_t cols, T& fill_value);
	Matrix(std::initializer_list<std::initializer_list<T>> values);

	// ����������� � �������
	explicit Matrix(const Matrix& matrix);
	Matrix(Matrix&& matrix);

	// ����������
	~Matrix();

	// ���������� ��������� ������������ ���������� ������� ��������
	Matrix<T>& operator =(const Matrix<T>& matrix);
	Matrix<T>& operator =(Matrix<T>&& matrix);
	Matrix<T>& operator =(std::initializer_list<std::initializer_list<T>> values);

	// �������� ��������� ������
	static Matrix<T>& OnesMatrix(size_t rows, size_t cols);
	static Matrix<T>& ZerosMatrix(size_t rows, size_t cols);
	static Matrix<T>& IdentityMatrix(size_t size);

	// ��������� ��������� � �����������
	bool equals(const Matrix<T>& matrix) const;
	bool operator ==(const Matrix<T>& matrix) const;

	bool unequals(const Matrix<T>& matrix) const;
	bool operator !=(const Matrix<T>& matrix) const;

	// ���������� ������ ����������
	Matrix<T>& operator +(const Matrix<T>& matrix) const;
	Matrix<T>& operator -(const Matrix<T>& matrix) const;
	Matrix<T>& operator *(const Matrix<T>& matrix) const;
	Matrix<T>& operator /(const Matrix<T>& matrix) const;

	Matrix<T>& addMatrix(const Matrix<T>& matrix);
	Matrix<T>& mulMatrix(const Matrix<T>& matrix);
	Matrix<T>& divMatrix(const Matrix<T>& matrix);
	Matrix<T>& subMatrix(const Matrix<T>& matrix);
	Matrix<T>& dot(const Matrix<T>& matrix); // ������������ ���������

	Matrix<T>& operator +(const T& val) const;
	Matrix<T>& operator -(const T& val) const;
	Matrix<T>& operator *(const T& val) const;
	Matrix<T>& operator /(const T& val) const;

	Matrix<T>& addElem(const T& val);
	Matrix<T>& subElem(const T& val);
	Matrix<T>& divElem(const T& val);
	Matrix<T>& mulElem(const T& val);

	// ������������ � ���������
	Matrix<T>& operator +=(const T& val);
	Matrix<T>& operator -=(const T& val);
	Matrix<T>& operator *=(const T& val);
	Matrix<T>& operator /=(const T& val);

	Matrix<T>& operator +=(const Matrix<T>& matrix);
	Matrix<T>& operator -=(const Matrix<T>& matrix);
	Matrix<T>& operator *=(const Matrix<T>& matrix);
	Matrix<T>& operator /=(const Matrix<T>& matrix);

	// ������ � ������ �������
	MatrixRow& operator[](const size_t ind);
	const MatrixRow& operator[](const size_t ind) const;

	// ����� ����� 
	Matrix<T>& operator-();
	Matrix<T>& neg();

	Matrix<T>& abs(); // ������

	T& determinant(); // ������������
	void transpose(); // ����������������
	void rotate(); // ������� �� 90 �������� ������
	void inverse(); // �������� �������

	void insertRow(const size_t ind, const T& fill_value);
	void insertCol(const size_t ind, const T& fill_value);
	void deleteRow(const size_t ind);
	void deleteCol(const size_t ind);
	void resize(const size_t new_row, const size_t new_col, const T& fill_value);

	// ������� ���������
	Iterator<T> begin();
	Iterator<T> end();

	ConstIterator<T> begin() const;
	ConstIterator<T> end() const;

	ConstIterator<T> cbegin() const;
	ConstIterator<T> cend() const;

	Iterator<T> rbegin();
	Iterator<T> rend();

private:
	SharedPtr<MatrixRow[]> _allocateMatrix(const size_t rows, const size_t cols);
	SharedPtr<MatrixRow[]> data;

public:
	class MatrixRow
	{
	private:
		size_t length;
		SharedPtr<T[]> data;
	public:
		// ������������
		MatrixRow(): length(0), data(nullptr) {};
		MatrixRow(std::initializer_list<T> values);

		// ���������� ����������
		T& operator[](const size_t index);
		const T& operator[](const size_t index) const;
		MatrixRow operator=(const MatrixRow& row);
		MatrixRow operator=(MatrixRow&& row);
		MatrixRow operator=(std::initializer_list<T> values);

		MatrixRow fillValue(T& value);

		size_t getLength();

		// ����������
		~MatrixRow();
	};

};

#include "Matrix.hpp"

