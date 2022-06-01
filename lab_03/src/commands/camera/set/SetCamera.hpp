//
// Created by Pavel Ivanov on 14.05.2022.
//

#ifndef LAB_03_SETCAMERA_HPP
#define LAB_03_SETCAMERA_HPP

#include <memory>

#include "commands/camera/BaseCameraCommand.hpp"
#include "objects/Camera/Camera/Camera.hpp"
#include "managers/SceneManager/SceneManager.hpp"

class SetCamera : public BaseCameraCommand
{
    using Action = void(SceneManager::*)(size_t);

public:
    SetCamera() = delete;
    explicit SetCamera(std::size_t id);
    ~SetCamera() override = default;

    void execute() override;

private:
    Action _act;

    std::size_t _id;

    std::shared_ptr<SceneManager> _manager;
};


#endif//LAB_03_SETCAMERA_HPP
