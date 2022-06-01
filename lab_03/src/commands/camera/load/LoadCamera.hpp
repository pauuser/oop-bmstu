//
// Created by Pavel Ivanov on 17.05.2022.
//

#ifndef LAB_03_LOADCAMERA_HPP
#define LAB_03_LOADCAMERA_HPP

#include <string>

#include "commands/camera/BaseCameraCommand.hpp"
#include "managers/LoadManager/LoadManager.hpp"

class LoadCamera : public BaseCameraCommand
{
    using Action = void(LoadManager::*)();

public:
    LoadCamera() = delete;
    explicit LoadCamera(std::string name);
    ~LoadCamera() override = default;

    void execute() override;

private:
    Action _act;

    std::string _name{};
    std::string _config_file{};

    std::shared_ptr<LoadManager> _manager;
};


#endif//LAB_03_LOADCAMERA_HPP
