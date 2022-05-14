//
// Created by Pavel Ivanov on 12.05.2022.
//

#include "Composite.hpp"

Composite::Composite(const std::shared_ptr<Object> &obj)
{
    this->_objects.push_back(obj);
}

Composite::Composite(const std::vector<std::shared_ptr<Object>> &vec)
{
    this->_objects = vec;
}

bool Composite::add(const std::shared_ptr<Object> &obj)
{
    this->_objects.push_back(obj);

    return true;
}

bool Composite::remove(const Iterator &it)
{
    this->_objects.erase(it);

    return true;
}

bool Composite::isVisible() const
{
    return false;
}

bool Composite::isComposite() const
{
    return true;
}

Iterator Composite::begin()
{
    return _objects.begin();
}

Iterator Composite::end()
{
    return _objects.end();
}

ConstIterator Composite::cbegin() const
{
    return _objects.cbegin();
}

ConstIterator Composite::cend() const
{
    return _objects.cend();
}

ConstIterator Composite::begin() const
{
    return _objects.cbegin();
}

ConstIterator Composite::end() const
{
    return _objects.cend();
}

void Composite::transform(const Point &move_params, const Point &scale_params, const Point &rotate_params)
{
    for (auto &obj: this->_objects)
    {
        obj->transform(move_params, scale_params, rotate_params);
    }
}

void Composite::accept(std::shared_ptr<BaseVisitor> visitor)
{
    for (auto &obj: this->_objects)
    {
        obj->accept(visitor);
    }
}
