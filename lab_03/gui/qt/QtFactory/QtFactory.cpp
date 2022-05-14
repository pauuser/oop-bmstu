//
// Created by Pavel Ivanov on 14.05.2022.
//

#include "QtFactory.hpp"

QtFactory::QtFactory(std::shared_ptr<QGraphicsScene> &scene) : _scene(scene) {}

std::unique_ptr<BaseDrawer> QtFactory::createDrawer()
{
    return std::make_unique<QtDrawer>(this->_scene);
}
