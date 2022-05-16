//
// Created by Pavel Ivanov on 16.05.2022.
//

#ifndef LAB_03_CAMERABUILDER_HPP
#define LAB_03_CAMERABUILDER_HPP

#include "builder/Camera/BaseCameraBuilder.hpp"
#include "objects/Camera/Camera.hpp"

class CameraBuilder : public BaseCameraBuilder
{
public:
    CameraBuilder() = default;
    ~CameraBuilder() override = default;

    void build() override;
    bool is_built() override;
    void reset() override;

    void buildPosition(double x, double y, double z);
    void buildAngle(double ax, double ay, double az);

private:
    std::shared_ptr<Camera> _camera;
};


#endif//LAB_03_CAMERABUILDER_HPP
