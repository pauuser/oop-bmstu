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
class Iterator : public std::iterator<std::random_access_iterator_tag, T>
{
public:
	// Конструктор
	Iterator(Matrix<T> matrix, size_t i, size_t j) : nrow(matrix.nrows), ncol(matrix.ncols),
		index(i* matrix.ncols + j), data(matrix.data) {}
	
	// Конструктор копирования
	Iterator(const Iterator& It) = default;

	T* operator->();
	T& operator*();
	operator bool() const;

	Iterator<T>& operator++();
	Iterator<T> operator++(int);

	Iterator<T>& operator--();
	Iterator<T> operator--(int);

	T& operator[](const size_t ind) const;
	Iterator<T>& operator+=(Iterator<T>& iterator);
	Iterator<T>& operator-=(Iterator<T>& iterator);
	Iterator<T>& operator+(Iterator<T>& iterator) const;
	Iterator<T>& operator-(Iterator<T>& iterator) const;

	bool operator!=(Iterator<T>& iterator) const;
	bool operator==(Iterator<T>& iterator) const;
	bool operator<(Iterator<T>& iterator) const;
	bool operator<=(Iterator<T>& iterator) const;
	bool operator>(Iterator<T>& iterator) const;
	bool operator>=(Iterator<T>& iterator) const;

private:
	size_t nrow;
	size_t ncol;
	size_t index;

	WeakPtr<typename Matrix<T>::MatrixRow[]> data;

};

