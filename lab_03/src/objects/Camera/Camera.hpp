//
// Created by Pavel Ivanov on 13.05.2022.
//

#ifndef LAB_03_CAMERA_HPP
#define LAB_03_CAMERA_HPP

#include "../Object.hpp"
#include "../Point/Point.hpp"

// TODO : Add visitor

class Camera : public InvisibleObject
{
public:
    Camera() = default;
    Camera(const Point& position, double ax, double ay, double az);
    ~Camera() override = default;

    void transform(const Point& move_params, const Point& scale_params, const Point& rotate_params) override;
    void accept(std::shared_ptr<Visitor> visitor) override;

private:
    Point _pos{};
    double _ax = 0, _ay = 0, _az = 0;

    void _move(const Point& move_params);
    void _scale(const Point &scale_params);
    void _rotate(const Point &rotate_params);
};


#endif//LAB_03_CAMERA_HPP
