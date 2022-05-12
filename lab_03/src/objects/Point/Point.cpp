//
// Created by Pavel Ivanov on 12.05.2022.
//

#include "Point.hpp"

Point::Point(double x, double y, double z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

Point::Point(Point &&point) noexcept
{
    this->x = point.x;
    this->y = point.y;
    this->z = point.z;

    point.~Point();
}

Point &Point::operator=(Point &&point) noexcept
{
    this->x = point.x;
    this->y = point.y;
    this->z = point.z;

    point.~Point();

    return *this;
}

void Point::setX(double new_x)
{
    this->x = new_x;
}

double Point::getX() const
{
    return this->x;
}

void Point::setY(double new_y)
{
    this->y = new_y;
}

double Point::getY() const
{
    return this->y;
}

void Point::setZ(double new_z)
{
    this->z = new_z;
}

double Point::getZ() const
{
    return this->z;
}

Point Point::operator+(const Point &point) const
{
    Point result{};

    result.x = this->x + point.x;
    result.y = this->y + point.y;
    result.z = this->z + point.z;

    return result;
}

Point& Point::operator+=(const Point &point)
{
    this->x += point.x;
    this->y += point.y;
    this->z += point.z;

    return *this;
}

Point Point::operator-(const Point &point) const
{
    Point result{};

    result.x = this->x - point.x;
    result.y = this->y - point.y;
    result.z = this->z - point.z;

    return result;
}

Point& Point::operator-=(const Point &point)
{
    this->x -= point.x;
    this->y -= point.y;
    this->z -= point.z;

    return *this;
}

Point Point::operator-() const
{
    Point result{};

    result.x = -this->x;
    result.y = -this->y;
    result.z = -this->z;

    return result;
}

bool Point::operator==(const Point& point) const
{
    bool res = (this->x == point.x) &&
               (this->y == point.y) &&
               (this->z == point.z);

    return res;
}

bool Point::operator!=(const Point& point) const
{
    bool res = (this->x == point.x) &&
               (this->y == point.y) &&
               (this->z == point.z);

    return !res;
}

void Point::move(double dx, double dy, double dz)
{
    this->x += dx;
    this->y += dy;
    this->z += dz;
}

void Point::scale(double kx, double ky, double kz, const Point& point)
{
    *this = *this - point;

    this->x *= kx;
    this->y *= ky;
    this->z *= kz;

    *this = *this + point;
}

void Point::rotate(double ax, double ay, double az, const Point &point)
{
    *this = *this - point;

    rotate_x(ax);
    rotate_y(ay);
    rotate_z(az);

    *this = *this + point;
}

double Point::_toRadians(double degrees)
{
    return degrees * (M_PI / 180);
}

void Point::rotate_x(double ax)
{
    const double cosinus = cos(_toRadians(ax));
    const double sinus   = sin(_toRadians(ax));
    const double y       = this->y;

    this->y = y * cosinus - this->z * sinus;
    this->z = this->z * cosinus + y * sinus;
}

void Point::rotate_y(double ay)
{
    const double cosinus = cos(_toRadians(ay));
    const double sinus   = sin(_toRadians(ay));
    const double x       = this->x;

    this->x = x * cosinus - this->z * sinus;
    this->y = this->z * cosinus + x * sinus;
}

void Point::rotate_z(double az)
{
    const double cosinus = cos(_toRadians(az));
    const double sinus   = sin(_toRadians(az));
    const double x       = this->x;

    this->x = x * cosinus - this->y * sinus;
    this->y = this->y * cosinus + x * sinus;
}