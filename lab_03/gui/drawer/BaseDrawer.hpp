//
// Created by Pavel Ivanov on 14.05.2022.
//

#ifndef LAB_03_BASEDRAWER_HPP
#define LAB_03_BASEDRAWER_HPP

#include "objects/Point/Point.hpp"

class BaseDrawer
{
public:
    BaseDrawer() = default;
    virtual ~BaseDrawer() = default;

    virtual void drawLine(const Point& p1, const Point& p2) = 0;
    virtual void clearScene() = 0;
};


#endif//LAB_03_BASEDRAWER_HPP
