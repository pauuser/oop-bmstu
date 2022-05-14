//
// Created by Pavel Ivanov on 14.05.2022.
//

#ifndef LAB_03_QTDRAWER_HPP
#define LAB_03_QTDRAWER_HPP

#include <memory>
#include <QGraphicsScene>

#include "gui/drawer/BaseDrawer.hpp"

class QtDrawer : public BaseDrawer
{
public:
    QtDrawer() = delete; // QtDrawer без QGraphicsScene не имеет смысла
    explicit QtDrawer(std::shared_ptr<QGraphicsScene>& scene);

    QtDrawer(const QtDrawer& drawer);

    ~QtDrawer() override = default;

    void drawLine(const Point &p1, const Point &p2) override;
    void clearScene() override;

private:
    std::shared_ptr<QGraphicsScene> _scene;
};


#endif//LAB_03_QTDRAWER_HPP
