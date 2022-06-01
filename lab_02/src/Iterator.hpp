template <typename T>
bool Iterator<T>::_isIndexValid() const
{
    size_t nrow = _getRows();
    size_t ncol = _getCols();

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
void Iterator<T>::_checkIterValid(const std::string filename, int line, const std::string inf) const
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

    size_t nrow = _getRows();
    size_t ncol = _getCols();

    SharedPtr<typename Matrix<T>::MatrixRow[]> data_ptr = data.lock();

    return data_ptr[index / ncol][index % ncol];
}

template <typename T>
T* Iterator<T>::operator->()
{
    _checkIterValid(__FILE__, __LINE__, "operator ->");

    size_t nrow = _getRows();
    size_t ncol = _getCols();

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
    size_t nrow = _getRows();
    size_t ncol = _getCols();

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
Iterator<T> Iterator<T>::operator+(int value) const
{
    Iterator<T> it(*this);

    size_t nrow = it._getRows();
    size_t ncol = it._getCols();

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

        if (it.index >= nrow * ncol)
        {
            it.index = nrow * ncol - 1;
        }
    }

    return it;
}

template <typename T>
Iterator<T> Iterator<T>::operator-(int value) const
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
Iterator<T>& Iterator<T>::operator+=(int value)
{
    *this = operator+(value);

    return *this;
}

template <typename T>
Iterator<T>& Iterator<T>::operator-=(int value)
{
    *this = operator-(value);

    return *this;
}

template <typename T>
const T& Iterator<T>::operator[](int ind) const
{
    return *(operator+(ind));
}

template <typename T>
T& Iterator<T>::operator[](int ind)
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

    size_t nrow = _getRows();
    size_t ncol = _getCols();

    SharedPtr<typename Matrix<T>::MatrixRow[]> data_ptr = data.lock();

    return data_ptr[data.index / ncol].get() + (index % ncol);
}

template <typename T>
const T& Iterator<T>::operator*() const
{
    _checkIterValid(__FILE__, __LINE__, "operator -> const");

    size_t nrow = _getRows();
    size_t ncol = _getCols();

    SharedPtr<typename Matrix<T>::MatrixRow[]> data_ptr = data.lock();

    return data_ptr[index / ncol][index % ncol];
}

template <typename T>
Iterator<T>& Iterator<T>::operator=(const Iterator<T>& it)
{
    data = it.data;
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
bool Iterator<T>::isEnd()
{
    size_t nrow = _getRows();
    size_t ncol = _getCols();

    return index == (nrow * ncol - 1);
}

template<typename T>
bool Iterator<T>::isStart()
{
    return index == 0;
}

template<typename T>
size_t Iterator<T>::_getRows() const
{
    SharedPtr<typename Matrix<T>::MatrixRow[]> data_ptr = data.lock();

    if (data_ptr == nullptr)
    {
        throw InitError(__FILE__, __LINE__, "Unitialised iterator!");
    }

    size_t nrow = data_ptr.get()->getLength();

    return nrow;
}

template<typename T>
size_t Iterator<T>::_getCols() const
{
    SharedPtr<typename Matrix<T>::MatrixRow[]> data_ptr = data.lock();

    if (data_ptr == nullptr)
    {
        throw InitError(__FILE__, __LINE__, "Unitialised iterator!");
    }

    size_t ncol = data_ptr[0].getLength();

    return ncol;
}