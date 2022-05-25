//
// Created by Pavel Ivanov on 25.05.2022.
//

#include "CameraImplementation.hpp"

CameraImplementation::CameraImplementation(const Point &pos, double ax, double ay, double az)
{
    _pos = pos;
    _ax = ax;
    _ay = ay;
    _az = az;
}

void CameraImplementation::transform(const Point &move_params, const Point &scale_params, const Point &rotate_params)
{
    this->_move(move_params);
    this->_scale(scale_params);
    this->_rotate(rotate_params);
}

Point CameraImplementation::getPosition()
{
    return this->_pos;
}

double CameraImplementation::getXangle()
{
    return this->_ax;
}

double CameraImplementation::getYangle()
{
    return this->_ay;
}

double CameraImplementation::getZangle()
{
    return this->_az;
}

void CameraImplementation::setPoisition(const Point &point)
{
    _pos = point;
}

void CameraImplementation::setXangle(double ax)
{
    _ax = ax;
}

void CameraImplementation::setYangle(double ay)
{
    _ay = ay;
}

void CameraImplementation::setZangle(double az)
{
    _az = az;
}

void CameraImplementation::_move(const Point& move_params)
{
    Point rotate_params(_ax, _ay, _az);

    this->_pos.rotate(-rotate_params.getX(), -rotate_params.getY(), -rotate_params.getZ());
    this->_pos.move(move_params.getX(), move_params.getY(), move_params.getZ());
    this->_pos.rotate(rotate_params.getX(), rotate_params.getY(), rotate_params.getZ());
}

void CameraImplementation::_scale(const Point& scale_params)
{
    Point rotate_params(_ax, _ay, _az);

    this->_pos.rotate(-rotate_params.getX(), -rotate_params.getY(), -rotate_params.getZ());
    this->_pos.scale(scale_params.getX(), scale_params.getY(), scale_params.getZ());
    this->_pos.rotate(rotate_params.getX(), rotate_params.getY(), rotate_params.getZ());
}

void CameraImplementation::_rotate(const Point &rotate_params)
{
    Point init_rotate_params(_ax, _ay, _az);

    this->_pos.rotate(-init_rotate_params.getX(), -init_rotate_params.getY(), -init_rotate_params.getZ());
    this->_pos.rotate(rotate_params.getX(), rotate_params.getY(), rotate_params.getZ());
    this->_pos.rotate(init_rotate_params.getX(), init_rotate_params.getY(), init_rotate_params.getZ());

    _ax += rotate_params.getX();
    _ay += rotate_params.getY();
    _az += rotate_params.getZ();
}
