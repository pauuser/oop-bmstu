//
// Created by Pavel Ivanov on 14.05.2022.
//

#ifndef LAB_03_ADDCAMERA_HPP
#define LAB_03_ADDCAMERA_HPP

#include <memory>

#include "commands/camera/BaseCameraCommand.hpp"
#include "objects/Camera/Camera.hpp"

class AddCamera : public BaseCameraCommand
{
public:
    AddCamera() = delete;
    explicit AddCamera(double posx, double posy, double posz);
    ~AddCamera() override = default;

    void execute() override;

private:
    double _posx = 0, _posy = 0, _posz = 0;
};


#endif//LAB_03_ADDCAMERA_HPP
