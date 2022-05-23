//
// Created by Pavel Ivanov on 13.05.2022.
//

#ifndef LAB_03_DRAWVISITOR_HPP
#define LAB_03_DRAWVISITOR_HPP

#include <cmath>

#include "../../gui/drawer/BaseDrawer.hpp"
#include "../BaseVisitor.h"

class DrawVisitor : public BaseVisitor
{
public:
    DrawVisitor(const std::shared_ptr<BaseDrawer>& drawer, const std::shared_ptr<Camera>& camera);

    void visit(const Camera& camera)       override;
    void visit(const FrameModel& model)    override;
    void visit(const Composite& composite) override;
    void visit(const Model& model)         override;

private:
    std::shared_ptr<BaseDrawer> _drawer;
    std::shared_ptr<Camera> _camera;

    Point  _projectPoint(const Point& point);
    static double _toRad(double degrees);
};

class DrawVisitorCreator: public BaseVisitorCreator
{
public:
    DrawVisitorCreator(const std::shared_ptr<BaseDrawer>& drawer, const std::shared_ptr<Camera>& camera);
    ~DrawVisitorCreator() override = default;

    std::unique_ptr<BaseVisitor> create() override;

private:
    std::shared_ptr<BaseDrawer> _drawer;
    std::shared_ptr<Camera>     _camera;
};


#endif//LAB_03_DRAWVISITOR_HPP
