template <typename T>
bool Iterator<T>::_isIndexValid() const
{
	bool ans = false;

	if (index < nrow * ncol)
	{
		ans = true;
	}

	return ans;
}

template<typename T>
bool Iterator<T>::_isExpired() const
{
	return data.expired();
}

template<typename T>
void Iterator<T>::_checkIterValid(const std::string filename, const int line, const std::string inf) const
{
	if (_isExpired())
	{
		throw MemoryError(__FILE__, __LINE__, "Trying to address exipred data!" + inf);
	}

	if (!_isIndexValid())
	{
		throw IndexOutOfRange(index, __FILE__, __LINE__, "Unaddressable access!" + inf);
	}
}

template <typename T>
T& Iterator<T>::operator*()
{
	_checkIterValid(__FILE__, __LINE__, "operator *");

	SharedPtr<typename Matrix<T>::MatrixRow[]> data_ptr = data.lock();

	return data_ptr[index / ncol][index % ncol];
}

template <typename T>
T* Iterator<T>::operator->()
{
	_checkIterValid(__FILE__, __LINE__, "operator ->");

	SharedPtr<typename Matrix<T>::MatrixRow[]> data_ptr = data.lock();

	return data_ptr[index / ncol].get() + (index % ncol);
}

template <typename T>
Iterator<T>::operator bool() const
{
	return data.expired();
}

template <typename T>
Iterator<T>& Iterator<T>::operator++()
{
	if (index <= nrow * ncol)
	{
		++index;
	}

	return *this;
}

template <typename T>
Iterator<T> Iterator<T>::operator++(int)
{
	Iterator<T> it = Iterator(*this);

	operator++();

	return it;
}

template <typename T>
Iterator<T>& Iterator<T>::operator--()
{
	if (index > 0)
	{
		--index;
	}

	return *this;
}

template <typename T>
Iterator<T> Iterator<T>::operator--(int)
{
	Iterator<T> it = Iterator(*this);

	operator--();

	return it;
}

template <typename T>
Iterator<T> Iterator<T>::operator+(const int value) const
{
	Iterator<T> it(*this);

	if (value < 0)
	{
		if (it.index < static_cast<size_t>(-value))
		{
			it.index = 0;
		}
		else
		{
			it.index = it.index - static_cast<size_t>(-value);
		}
	}
	else
	{
		it.index += value;

		if (it.index >= it.nrow * it.ncol)
		{
			it.index = it.nrow * it.ncol - 1;
		}
	}

	return it;
}

template <typename T>
Iterator<T> Iterator<T>::operator-(const int value) const
{
	Iterator<T> it(*this);

	if (value > 0)
	{
		if (it.index < value)
		{
			it.index = 0;
		}
		else
		{
			it.index = it.index - value;
		}
	}
	else
	{
		it = operator+(-value);
	}

	return it;
}

template <typename T>
Iterator<T>& Iterator<T>::operator+=(const int value)
{
	*this = operator+(value);

	return *this;
}

template <typename T>
Iterator<T>& Iterator<T>::operator-=(const int value)
{
	*this = operator-(value);

	return *this;
}


template <typename T>
Iterator<T> Iterator<T>::operator+(const Iterator<T>& iterator) const
{
	Iterator<T> it(*this);

	it += iterator.index;

	return it;
}

template <typename T>
Iterator<T> Iterator<T>::operator-(const Iterator<T>& iterator) const
{
	Iterator<T> it(*this);

	it -= iterator.index;

	return it;
}

template <typename T>
Iterator<T>& Iterator<T>::operator+=(const Iterator<T>& iterator)
{
	*this += iterator.index;

	return *this;
}

template <typename T>
Iterator<T>& Iterator<T>::operator-=(const Iterator<T>& iterator)
{
	*this -= iterator.index;

	return *this;
}

template <typename T>
T& Iterator<T>::operator[](const int ind) const
{
	return *(operator+(ind));
}

template <typename T>
bool Iterator<T>::operator==(const Iterator<T>& iterator) const
{
	bool ans = true;

	if (index != iterator.index)
	{
		ans = false;
	}

	return ans;
}

template <typename T>
bool Iterator<T>::operator!=(const Iterator<T>& iterator) const
{
	return !(operator==(iterator));
}

template <typename T>
bool Iterator<T>::operator<(const Iterator<T>& iterator) const
{
	return index < iterator.index;
}

template <typename T>
bool Iterator<T>::operator>=(const Iterator<T>& iterator) const
{
	return !(operator <(iterator));
}

template <typename T>
bool Iterator<T>::operator>(const Iterator<T>& iterator) const
{
	return index > iterator.index;
}

template <typename T>
bool Iterator<T>::operator<=(const Iterator<T>& iterator) const
{
	return !(operator >(iterator));
}

template <typename T>
const T* Iterator<T>::operator->() const
{
	_checkIterValid(__FILE__, __LINE__, "operator -> const");

	SharedPtr<typename Matrix<T>::MatrixRow[]> data_ptr = data.lock();

	return data_ptr[index / ncol].get() + (index % ncol);
}

template <typename T>
const T& Iterator<T>::operator*() const
{
	_checkIterValid(__FILE__, __LINE__, "operator -> const");

	SharedPtr<typename Matrix<T>::MatrixRow[]> data_ptr = data.lock();

	return data_ptr[index / ncol][index % ncol];
}

template <typename T>
Iterator<T>& Iterator<T>::operator=(const Iterator<T>& it)
{
	data = it.data;
	nrow = it.nrow;
	ncol = it.ncol;
	index = it.index;

	return *this;
}

template <typename T>
T& Iterator<T>::value()
{
	return operator*();
}

template <typename T>
const T& Iterator<T>::value() const
{
	return operator*();
}

template <typename T>
Iterator<T>& Iterator<T>::next()
{
	return operator++();
}

template<typename T>
bool Iterator<T>::isEnd() const
{
	return index == (nrow * ncol - 1);
}

template<typename T>
bool Iterator<T>::isStart() const
{
	return index == 0;
}