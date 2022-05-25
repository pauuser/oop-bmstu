//
// Created by Pavel Ivanov on 13.05.2022.
//

#include "DrawVisitor.hpp"
#include "objects/Camera/Camera/Camera.hpp"
#include "objects/Composite/Composite.hpp"
#include "objects/Model/FrameModel/FrameModel.hpp"
#include "objects/Model/Model.hpp"

DrawVisitor::DrawVisitor(const std::shared_ptr<BaseDrawer>& drawer, const std::shared_ptr<Camera>& camera):
                        _drawer(drawer){
    _camera = camera->getImplementation();
}

double DrawVisitor::_toRad(double degrees)
{
    return M_PI * degrees / 180;
}

Point DrawVisitor::_projectPoint(const Point &point)
{
    // At first, reversing camera position
    Point res_point(point);

    Point center = this->_camera->getPosition();
    double ax = this->_camera->getXangle();
    double ay = this->_camera->getYangle();
    double az = this->_camera->getZangle();

    res_point.rotate(-ax, -ay, -az);
    res_point.move(-center.getX(), -center.getY(), -center.getZ());

    // Now we can project the camera image to 2d screen

    double new_x = res_point.getY();
    double new_y = res_point.getZ();

    res_point.setX(new_x);
    res_point.setY(new_y);

    return res_point;
}

void DrawVisitor::visit(const FrameModel &model)
{
    auto points = model.getImplementation()->_getPoints();

    for (const auto &edge: model.getImplementation()->_getEdges())
    {
        this->_drawer->drawLine(
                this->_projectPoint(points[edge.getFirst()]),
                this->_projectPoint(points[edge.getSecond()])
        );
    }
}

DrawVisitorCreator::DrawVisitorCreator(const std::shared_ptr<BaseDrawer> &drawer, const std::shared_ptr<Camera> &camera)
{
    _drawer = drawer;
    _camera = camera;
}

std::unique_ptr<BaseVisitor> DrawVisitorCreator::create()
{
    return std::make_unique<DrawVisitor>(_drawer, _camera);
}

void DrawVisitor::visit(const Composite &composite) {}

void DrawVisitor::visit(const Camera &camera) {}

void DrawVisitor::visit(const Model& model) {}
