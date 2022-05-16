//
// Created by Pavel Ivanov on 16.05.2022.
//

#ifndef LAB_03_BASEMODELBUILDER_HPP
#define LAB_03_BASEMODELBUILDER_HPP

#include "builder/BaseBuilder.hpp"

class BaseModelBuilder : public BaseBuilder
{
public:
    BaseModelBuilder() = default;
    ~BaseModelBuilder() override = default;

    virtual void buildPoint(double x, double y, double z) = 0;
    virtual void buildEdge(std::size_t id1, std::size_t id2) = 0;
    virtual void buildCenter(double x, double y, double z) = 0;
};

#endif//LAB_03_BASEMODELBUILDER_HPP
