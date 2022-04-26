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
class Iterator : public std::iterator<std::random_access_iterator_tag, T>
{
public:
	Iterator(Matrix<T>& matrix, const size_t i = 0, const size_t j = 0) : nrow(matrix.nrows), ncol(matrix.ncols),
		index(i * matrix.ncols + j), data(matrix.data) {}
	
	Iterator(const Iterator& It) = default;

	T* operator->();
	const T* operator->() const;

	T& operator*();
	const T& operator*() const;

	operator bool() const;

	Iterator<T>& operator++();
	Iterator<T> operator++(int);

	Iterator<T>& operator--();
	Iterator<T> operator--(int);

	T& operator[](const int ind) const;
	Iterator<T>& operator=(const Iterator<T>& it);

	Iterator<T>& operator+=(const Iterator<T>& iterator);
	Iterator<T>& operator-=(const Iterator<T>& iterator);
	Iterator<T> operator+(const Iterator<T>& iterator) const;
	Iterator<T> operator-(const Iterator<T>& iterator) const;

	Iterator<T>& operator+=(const int value);
	Iterator<T>& operator-=(const int value);
	Iterator<T> operator+(const int value) const;
	Iterator<T> operator-(const int value) const;

	bool operator!=(const Iterator<T>& iterator) const;
	bool operator==(const Iterator<T>& iterator) const;
	bool operator <(const Iterator<T>& iterator) const;
	bool operator<=(const Iterator<T>& iterator) const;
	bool operator >(const Iterator<T>& iterator) const;
	bool operator>=(const Iterator<T>& iterator) const;

	T& value();
	const T& value() const;

	Iterator<T>& next();

	bool isEnd() const;
	bool isStart() const;

private:
	size_t nrow;
	size_t ncol;
	size_t index;

	WeakPtr<typename Matrix<T>::MatrixRow[]> data;

	bool _isIndexValid() const;
	bool _isExpired() const;
	void _checkIterValid(const std::string filename, const int line, const std::string inf = "") const;
};

#include "Iterator.hpp"

