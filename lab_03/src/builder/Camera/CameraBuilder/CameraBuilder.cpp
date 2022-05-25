//
// Created by Pavel Ivanov on 16.05.2022.
//

#include "CameraBuilder.hpp"

void CameraBuilder::build()
{
    _camera = std::make_shared<CameraImplementation>();
}

bool CameraBuilder::is_built()
{
    return _camera == nullptr;
}

void CameraBuilder::reset()
{
    _camera.reset();
}

void CameraBuilder::buildPosition(double x, double y, double z)
{
    Point pos(x, y, z);
    _camera->setPoisition(pos);
}

void CameraBuilder::buildAngle(double ax, double ay, double az)
{
    _camera->setXangle(ax);
    _camera->setYangle(ay);
    _camera->setZangle(az);
}

std::shared_ptr<Object> CameraBuilder::get()
{
    return std::make_shared<Camera>(_camera);
}

std::shared_ptr<BaseBuilder> CameraBuilderCreator::createBuilder()
{
    return std::make_shared<CameraBuilder>();
}

