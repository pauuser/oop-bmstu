#pragma once

#include <iterator>
#include <iostream>

#include "Exceptions.h"

template <typename T>
using SharedPtr = std::shared_ptr<T>;

template <typename T>
using WeakPtr = std::weak_ptr<T>;

template <typename T>
class Matrix;

template <typename T>
class ConstIterator : public std::iterator<std::random_access_iterator_tag, T>
{
public:
	ConstIterator(const Matrix<T>& matrix, const size_t i = 0, const size_t j = 0) : nrow(matrix.nrows), ncol(matrix.ncols),
		index(i* matrix.ncols + j), data(matrix.data) {}

	ConstIterator(const ConstIterator& It) = default;

	const T* operator->() const;
	const T& operator*() const;

	operator bool() const;

	ConstIterator<T>& operator++();
	ConstIterator<T> operator++(int);

	ConstIterator<T>& operator--();
	ConstIterator<T> operator--(int);

	const T& operator[](int ind) const;
	ConstIterator<T>& operator=(const ConstIterator<T>& it);

	ConstIterator<T>& operator+=(const ConstIterator<T>& iterator);
	ConstIterator<T>& operator-=(const ConstIterator<T>& iterator);
	ConstIterator<T> operator+(const ConstIterator<T>& iterator) const;
	ConstIterator<T> operator-(const ConstIterator<T>& iterator) const;

	ConstIterator<T>& operator+=(int value);
	ConstIterator<T>& operator-=(int value);
	ConstIterator<T> operator+(int value) const;
	ConstIterator<T> operator-(int value) const;

	bool operator!=(const ConstIterator<T>& iterator) const;
	bool operator==(const ConstIterator<T>& iterator) const;
	bool operator <(const ConstIterator<T>& iterator) const;
	bool operator<=(const ConstIterator<T>& iterator) const;
	bool operator >(const ConstIterator<T>& iterator) const;
	bool operator>=(const ConstIterator<T>& iterator) const;

	const T& value() const;

	ConstIterator<T>& next();

	bool isEnd() const;
	bool isStart() const;

private:
	size_t nrow;
	size_t ncol;
	size_t index;

	WeakPtr<typename Matrix<T>::MatrixRow[]> data;

	bool _isIndexValid() const;
	bool _isExpired() const;
	void _checkIterValid(const std::string filename, int line, const std::string inf = "") const;
};

#include "ConstIterator.hpp"

