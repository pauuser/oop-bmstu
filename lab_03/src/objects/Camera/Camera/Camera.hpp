//
// Created by Pavel Ivanov on 13.05.2022.
//

#ifndef LAB_03_CAMERA_HPP
#define LAB_03_CAMERA_HPP

#include <memory>

#include "./CameraImplementation/CameraImplementation.hpp"
#include "objects/Object.hpp"
#include "objects/Camera/BaseCamera.hpp"
#include "objects/Point/Point.hpp"
#include "visitor/DrawVisitor/DrawVisitor.hpp"

class Camera : public BaseCamera
{
public:
    Camera() = default;
    Camera(std::shared_ptr<CameraImplementation> imp);
    ~Camera() override = default;

    void transform(const Point& move_params, const Point& scale_params, const Point& rotate_params) override;
    void accept(std::shared_ptr<BaseVisitor> visitor) override;

    friend DrawVisitor;

protected:
    [[nodiscard]] std::shared_ptr<CameraImplementation> getImplementation() const;

private:
    std::shared_ptr<CameraImplementation> _implementation = nullptr;
};

class CameraCreator : public BaseCameraCreator
{
public:
    CameraCreator(const Point& position, double ax, double ay, double az);
    ~CameraCreator() override = default;

    std::shared_ptr<BaseCamera> create() override;

private:
    Point _pos{};
    double _ax = 0, _ay = 0, _az = 0;
};;


#endif//LAB_03_CAMERA_HPP
