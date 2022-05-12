//
// Created by Pavel Ivanov on 12.05.2022.
//

#ifndef LAB_03_OBJECT_HPP
#define LAB_03_OBJECT_HPP

#include <memory>
#include <vector>

class Visitor;

class Object;
using Iterator = std::vector<std::shared_ptr<Object>>::iterator;
using ConstIterator = std::vector<std::shared_ptr<Object>>::const_iterator;

class Object
{
public:
    Object() = default;
    virtual ~Object() = default;

    virtual bool add   (std::shared_ptr<Object> &obj) { return false; }
    virtual bool remove(const Iterator &it)           { return false; }

    virtual bool isComposite() const { return false; }
    virtual bool isVisible() const = 0;

    virtual Iterator begin() { return Iterator{}; }
    virtual Iterator end()   { return Iterator{}; }

    virtual ConstIterator begin()  const { return ConstIterator{}; }
    virtual ConstIterator end()    const { return ConstIterator{}; }

    virtual ConstIterator cbegin() const { return ConstIterator{}; }
    virtual ConstIterator cend()   const { return ConstIterator{}; }

    virtual void accept(std::shared_ptr<Visitor> visitor) = 0; // FIX ME
    virtual void transform(...) = 0;                           // FIX ME
};

class VisibleObject : public Object
{
public:
    VisibleObject() = default;
    ~VisibleObject() override = default;

    bool isVisible() const override { return true; }
};

class InvisibleObject : public Object
{
public:
    InvisibleObject() = default;
    ~InvisibleObject() override = default;

    bool isVisible() const override { return false; }
};

#endif//LAB_03_OBJECT_HPP
