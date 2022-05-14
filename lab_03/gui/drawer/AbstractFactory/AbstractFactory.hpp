//
// Created by Pavel Ivanov on 14.05.2022.
//

#ifndef LAB_03_ABSTRACTFACTORY_HPP
#define LAB_03_ABSTRACTFACTORY_HPP

#include "../BaseDrawer.hpp"

class AbstractFactory
{
public:
    AbstractFactory() = default;
    virtual ~AbstractFactory() = default;

    virtual std::unique_ptr<BaseDrawer> createDrawer() = 0;
};


#endif//LAB_03_ABSTRACTFACTORY_HPP
