#pragma once

#include <iterator>
#include <iostream>

#include "Exceptions.h"

template <typename T>
using UniquePtr = std::unique_ptr<T>;

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
	Iterator(Matrix<T>& matrix, const size_t i = 0, const size_t j = 0) : index(i * matrix.ncols + j), data(matrix.data),
																		  nrow(matrix.nrows), ncol(matrix.ncols) {}
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
	
	T& operator[](int ind);
	const T& operator[](int ind) const;
	Iterator<T>& operator=(const Iterator<T>& it);

	Iterator<T>& operator+=(int value);
	Iterator<T>& operator-=(int value);
	Iterator<T> operator+(int value) const;
	Iterator<T> operator-(int value) const;

	bool operator!=(const Iterator<T>& iterator) const;
	bool operator==(const Iterator<T>& iterator) const;
	bool operator <(const Iterator<T>& iterator) const;
	bool operator<=(const Iterator<T>& iterator) const;
	bool operator >(const Iterator<T>& iterator) const;
	bool operator>=(const Iterator<T>& iterator) const;

	T& value();
	const T& value() const;

	Iterator<T>& next();

	bool isEnd();
	bool isStart();

private:
	mutable size_t nrow;
	mutable size_t ncol;
	size_t index;

	WeakPtr<typename Matrix<T>::MatrixRow[]> data;

	bool _isIndexValid() const;
	bool _isExpired() const;
	void _checkIterValid(const std::string filename, int line, const std::string inf = "") const;
	void _updateSize() const;
};

#include "Iterator.hpp"

