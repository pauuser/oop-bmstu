//
// Created by Pavel Ivanov on 16.05.2022.
//

#ifndef LAB_03_BASEBUILDER_HPP
#define LAB_03_BASEBUILDER_HPP

#include "objects/Object.hpp"


class BaseBuilder
{
public:
    BaseBuilder() = default;
    virtual ~BaseBuilder() = default;

    virtual void build() = 0;
    virtual bool is_built() = 0;
    virtual void reset() = 0;

    virtual std::shared_ptr<Object> get() = 0;
};

class BuilderCreator
{
public:
    BuilderCreator() = default;
    virtual ~BuilderCreator() = default;

    virtual std::shared_ptr<BaseBuilder> createBuilder() = 0;
};


#endif//LAB_03_BASEBUILDER_HPP
