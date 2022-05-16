//
// Created by Pavel Ivanov on 16.05.2022.
//

#include "CameraBuilder.hpp"

void CameraBuilder::build()
{
    _camera = std::make_shared<Camera>();
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
    _camera = std::make_shared<Camera>(pos, 0, 0 ,0);
}

void CameraBuilder::buildAngle(double ax, double ay, double az)
{
    if (_camera != nullptr)
    {
        _camera = std::make_shared<Camera>(_camera->getPosition(), ax, ay, az);
    }
    else
    {
        _camera = std::make_shared<Camera>(Point{0, 0, 0}, ax, ay, az);
    }
}

