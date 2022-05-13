//
// Created by Pavel Ivanov on 12.05.2022.
//

#ifndef LAB_03_POINT_HPP
#define LAB_03_POINT_HPP

#include <cmath>
#include <memory>

// TODO : test

class Point
{
public:
    Point() = default;
    Point(double x, double y, double z);
    ~Point() = default;

    Point(const Point &point) = default;
    Point& operator=(const Point &point) = default;

    Point(Point &&point) noexcept;
    Point& operator=(Point &&point) noexcept;

    void   setX(double new_x);
    double getX() const;

    void   setY(double new_y);
    double getY() const;

    void   setZ(double new_z);
    double getZ() const;

    Point  operator+ (const Point &point) const;
    Point& operator+=(const Point &point);

    Point  operator- (const Point &point) const;
    Point& operator-=(const Point &point);

    Point operator-() const;

    bool operator==(const Point& point) const;
    bool operator!=(const Point& point) const;

    void move  (double dx, double dy, double dz);
    void scale (double kx, double ky, double kz);
    void rotate(double ax, double ay, double az);

    void rotate_x(double ax);
    void rotate_y(double ay);
    void rotate_z(double az);

private:
    double _x = 0, _y = 0, _z = 0;

    static double _toRadians(double degrees);
};

#endif//LAB_03_POINT_HPP
