//
// Created by Pavel Ivanov on 14.05.2022.
//

#ifndef LAB_03_SETCAMERA_HPP
#define LAB_03_SETCAMERA_HPP

#include <memory>

#include "commands/camera/BaseCameraCommand.hpp"
#include "objects/Camera/Camera.hpp"

class SetCamera : public BaseCameraCommand
{
public:
    SetCamera() = delete;
    explicit SetCamera(std::size_t id);
    ~SetCamera() override = default;

    void execute() override; // TODO: finish

private:
    std::size_t _id;
};


#endif//LAB_03_SETCAMERA_HPP
