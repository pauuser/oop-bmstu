//
// Created by Pavel Ivanov on 12.05.2022.
//

#include "Point.hpp"

Point::Point(double x, double y, double z)
{
    this->_x = x;
    this->_y = y;
    this->_z = z;
}

Point::Point(Point &&point) noexcept
{
    this->_x = point._x;
    this->_y = point._y;
    this->_z = point._z;

    point.~Point();
}

Point &Point::operator=(Point &&point) noexcept
{
    this->_x = point._x;
    this->_y = point._y;
    this->_z = point._z;

    point.~Point();

    return *this;
}

void Point::setX(double new_x)
{
    this->_x = new_x;
}

double Point::getX() const
{
    return this->_x;
}

void Point::setY(double new_y)
{
    this->_y = new_y;
}

double Point::getY() const
{
    return this->_y;
}

void Point::setZ(double new_z)
{
    this->_z = new_z;
}

double Point::getZ() const
{
    return this->_z;
}

Point Point::operator+(const Point &point) const
{
    Point result{};

    result._x = this->_x + point._x;
    result._y = this->_y + point._y;
    result._z = this->_z + point._z;

    return result;
}

Point& Point::operator+=(const Point &point)
{
    this->_x += point._x;
    this->_y += point._y;
    this->_z += point._z;

    return *this;
}

Point Point::operator-(const Point &point) const
{
    Point result{};

    result._x = this->_x - point._x;
    result._y = this->_y - point._y;
    result._z = this->_z - point._z;

    return result;
}

Point& Point::operator-=(const Point &point)
{
    this->_x -= point._x;
    this->_y -= point._y;
    this->_z -= point._z;

    return *this;
}

Point Point::operator-() const
{
    Point result{};

    result._x = -this->_x;
    result._y = -this->_y;
    result._z = -this->_z;

    return result;
}

bool Point::operator==(const Point& point) const
{
    bool res = (this->_x == point._x) &&
               (this->_y == point._y) &&
               (this->_z == point._z);

    return res;
}

bool Point::operator!=(const Point& point) const
{
    bool res = (this->_x == point._x) &&
               (this->_y == point._y) &&
               (this->_z == point._z);

    return !res;
}

void Point::move(double dx, double dy, double dz)
{
    this->_x += dx;
    this->_y += dy;
    this->_z += dz;
}

void Point::scale(double kx, double ky, double kz)
{
    this->_x *= kx;
    this->_y *= ky;
    this->_z *= kz;
}

void Point::rotate(double ax, double ay, double az)
{
    rotate_x(ax);
    rotate_y(ay);
    rotate_z(az);
}

double Point::_toRadians(double degrees)
{
    return degrees * (M_PI / 180);
}

void Point::rotate_x(double ax)
{
    const double cosinus = cos(_toRadians(ax));
    const double sinus   = sin(_toRadians(ax));
    const double y       = this->_y;

    this->_y = y * cosinus - this->_z * sinus;
    this->_z = this->_z * cosinus + y * sinus;
}

void Point::rotate_y(double ay)
{
    const double cosinus = cos(_toRadians(ay));
    const double sinus   = sin(_toRadians(ay));
    const double x       = this->_x;

    this->_x = x * cosinus - this->_z * sinus;
    this->_z = this->_z * cosinus + x * sinus;
}

void Point::rotate_z(double az)
{
    const double cosinus = cos(_toRadians(az));
    const double sinus   = sin(_toRadians(az));
    const double x       = this->_x;

    this->_x = x * cosinus - this->_y * sinus;
    this->_y = this->_y * cosinus + x * sinus;
}