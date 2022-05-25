//
// Created by Pavel Ivanov on 25.05.2022.
//

#ifndef LAB_03_CAMERAIMPLEMENTATION_HPP
#define LAB_03_CAMERAIMPLEMENTATION_HPP

#include "objects/Point/Point.hpp"

class CameraImplementation
{
public:
    CameraImplementation() = default;
    CameraImplementation(const Point& pos, double ax, double ay, double az);
    ~CameraImplementation() = default;

    void transform(const Point& move_params, const Point& scale_params, const Point& rotate_params);

    Point getPosition();
    double getXangle();
    double getYangle();
    double getZangle();

    void setPoisition(const Point& point);
    void setXangle(double ax);
    void setYangle(double ay);
    void setZangle(double az);

private:
    Point _pos{};
    double _ax = 0, _ay = 0, _az = 0;

    void _move(const Point& move_params);
    void _scale(const Point &scale_params);
    void _rotate(const Point &rotate_params);
};


#endif//LAB_03_CAMERAIMPLEMENTATION_HPP
