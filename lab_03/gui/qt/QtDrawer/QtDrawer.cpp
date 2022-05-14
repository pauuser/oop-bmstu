//
// Created by Pavel Ivanov on 14.05.2022.
//

#include "QtDrawer.hpp"

QtDrawer::QtDrawer(const QtDrawer &drawer)
{
    this->_scene = drawer._scene;
}

QtDrawer::QtDrawer(std::shared_ptr<QGraphicsScene>& scene)
{
    this->_scene = scene;
}

void QtDrawer::drawLine(const Point &p1, const Point &p2)
{
    this->_scene->addLine(p1.getX(), p1.getY(),
                          p2.getX(), p2.getY());
}

void QtDrawer::clearScene()
{
    this->_scene->clear();
}