//
// Created by Pavel Ivanov on 14.05.2022.
//

#ifndef LAB_03_ADDCAMERA_HPP
#define LAB_03_ADDCAMERA_HPP

#include <memory>

#include "commands/camera/BaseCameraCommand.hpp"
#include "objects/Camera/Camera/Camera.hpp"
#include "managers/SceneManager/SceneManager.hpp"

class AddCamera : public BaseCameraCommand
{
    using Action = void(SceneManager::*)(const std::shared_ptr<Object> &);

public:
    AddCamera() = delete;
    explicit AddCamera(double posx, double posy, double posz,
                       double ax,   double ay,   double az);
    ~AddCamera() override = default;

    void execute() override;

private:
    Action _act;

    double _posx = 0, _posy = 0, _posz = 0;
    double _ax = 0, _ay = 0, _az = 0;

    std::shared_ptr<BaseCamera>   _camera;
    std::shared_ptr<SceneManager> _manager;
};


#endif//LAB_03_ADDCAMERA_HPP
