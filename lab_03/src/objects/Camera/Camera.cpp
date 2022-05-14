//
// Created by Pavel Ivanov on 13.05.2022.
//

#include "Camera.hpp"

Camera::Camera(const Point& position, double ax, double ay, double az):
               _pos(position), _ax(ax), _ay(ay), _az(az) {}


void Camera::_move(const Point& move_params)
{
    Point rotate_params(_ax, _ay, _az);

    this->_pos.rotate(-rotate_params.getX(), -rotate_params.getY(), -rotate_params.getZ());
    this->_pos.move(move_params.getX(), move_params.getY(), move_params.getZ());
    this->_pos.rotate(rotate_params.getX(), rotate_params.getY(), rotate_params.getZ());
}

void Camera::_scale(const Point& scale_params)
{
    Point rotate_params(_ax, _ay, _az);

    this->_pos.rotate(-rotate_params.getX(), -rotate_params.getY(), -rotate_params.getZ());
    this->_pos.scale(scale_params.getX(), scale_params.getY(), scale_params.getZ());
    this->_pos.rotate(rotate_params.getX(), rotate_params.getY(), rotate_params.getZ());
}

void Camera::_rotate(const Point &rotate_params)
{
    Point init_rotate_params(_ax, _ay, _az);

    this->_pos.rotate(-init_rotate_params.getX(), -init_rotate_params.getY(), -init_rotate_params.getZ());
    this->_pos.rotate(rotate_params.getX(), rotate_params.getY(), rotate_params.getZ());
    this->_pos.rotate(init_rotate_params.getX(), init_rotate_params.getY(), init_rotate_params.getZ());

    _ax += rotate_params.getX();
    _ay += rotate_params.getY();
    _az += rotate_params.getZ();
}

void Camera::transform(const Point &move_params, const Point &scale_params, const Point &rotate_params)
{
    this->_move(move_params);
    this->_scale(scale_params);
    this->_rotate(rotate_params);
}

void Camera::accept(std::shared_ptr<BaseVisitor> visitor)
{
    visitor->visit(*this);
}

Point Camera::getPosition()
{
    return this->_pos;
}

double Camera::getXangle()
{
    return this->_ax;
}

double Camera::getYangle()
{
    return this->_ay;
}

double Camera::getZangle()
{
    return this->_az;
}