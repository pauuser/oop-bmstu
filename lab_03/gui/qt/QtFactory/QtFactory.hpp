//
// Created by Pavel Ivanov on 14.05.2022.
//

#ifndef LAB_03_QTFACTORY_HPP
#define LAB_03_QTFACTORY_HPP

#include "../QtDrawer/QtDrawer.hpp"
#include "../../drawer/AbstractFactory/AbstractFactory.hpp"
#include "../../drawer/BaseDrawer.hpp"


class QtFactory : public AbstractFactory
{
public:
    QtFactory() = delete;
    explicit QtFactory(std::shared_ptr<QGraphicsScene>& scene);

    std::unique_ptr<BaseDrawer> createDrawer() override;

private:
    std::shared_ptr<QGraphicsScene> _scene = nullptr;
};

#endif//LAB_03_QTFACTORY_HPP
