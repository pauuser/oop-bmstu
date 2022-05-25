//
// Created by Pavel Ivanov on 13.05.2022.
//

#include "Camera.hpp"

Camera::Camera(std::shared_ptr<CameraImplementation> imp)
{
    this->_implementation = imp;
}

std::shared_ptr<CameraImplementation> Camera::getImplementation() const
{
    return this->_implementation;
}

void Camera::transform(const Point &move_params, const Point &scale_params, const Point &rotate_params)
{
    this->_implementation->transform(move_params, scale_params, rotate_params);
}

void Camera::accept(std::shared_ptr<BaseVisitor> visitor)
{
    visitor->visit(*this);
}

CameraCreator::CameraCreator(const Point &position, double ax, double ay, double az)
{
    _pos = position;
    _ax = ax;
    _ay = ay;
    _az = az;
}

std::shared_ptr<BaseCamera> CameraCreator::create()
{
    return std::make_shared<Camera>(std::make_shared<CameraImplementation>());
}