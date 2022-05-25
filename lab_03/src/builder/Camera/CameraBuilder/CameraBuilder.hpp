//
// Created by Pavel Ivanov on 16.05.2022.
//

#ifndef LAB_03_CAMERABUILDER_HPP
#define LAB_03_CAMERABUILDER_HPP

#include "builder/Camera/BaseCameraBuilder.hpp"
#include "objects/Camera/Camera/Camera.hpp"

class CameraBuilder : public BaseCameraBuilder
{
public:
    CameraBuilder() = default;
    ~CameraBuilder() override = default;

    void build() override;
    bool is_built() override;
    void reset() override;

    std::shared_ptr<Object> get() override;

    void buildPosition(double x, double y, double z) override;
    void buildAngle(double ax, double ay, double az) override;

private:
    std::shared_ptr<CameraImplementation> _camera;
};

class CameraBuilderCreator : public BuilderCreator
{
public:
    CameraBuilderCreator() = default;
    ~CameraBuilderCreator() override = default;

    std::shared_ptr<BaseBuilder> createBuilder() override;
};


#endif//LAB_03_CAMERABUILDER_HPP
