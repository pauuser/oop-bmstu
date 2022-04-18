#pragma once

#include <iterator>
#include <iostream>

template <typename T>
using SharedPtr = std::shared_ptr<T>;

template <typename T>
using WeakPtr = std::weak_ptr<T>;

template <typename T>
class Matrix;

template <typename T>
class ConstIterator
{
public:
	// Конструктор
	ConstIterator(Matrix<T> matrix, size_t i, size_t j) : nrow(matrix.nrows), ncol(matrix.ncols),
		index(i* matrix.ncols + j), data(matrix.data) {}

	// Конструктор копирования
	ConstIterator(const ConstIterator& It) = default;

	const T* operator->() const;
	const T& operator*() const;
	operator bool() const;

	ConstIterator<T>& operator++();
	ConstIterator<T> operator++(int);

	ConstIterator<T>& operator--();
	ConstIterator<T> operator--(int);

	const T& operator[](const size_t ind) const;
	ConstIterator<T>& operator+=(ConstIterator<T>& iterator);
	ConstIterator<T>& operator-=(ConstIterator<T>& iterator);
	ConstIterator<T>& operator+(ConstIterator<T>& iterator) const;
	ConstIterator<T>& operator-(ConstIterator<T>& iterator) const;

	bool operator!=(ConstIterator<T>& iterator) const;
	bool operator==(ConstIterator<T>& iterator) const;
	bool operator<(ConstIterator<T>& iterator) const;
	bool operator<=(ConstIterator<T>& iterator) const;
	bool operator>(ConstIterator<T>& iterator) const;
	bool operator>=(ConstIterator<T>& iterator) const;

private:
	size_t nrow;
	size_t ncol;
	size_t index;

	WeakPtr<typename Matrix<T>::MatrixRow[]> data;
};

