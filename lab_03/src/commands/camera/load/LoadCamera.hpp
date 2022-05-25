//
// Created by Pavel Ivanov on 17.05.2022.
//

#ifndef LAB_03_LOADCAMERA_HPP
#define LAB_03_LOADCAMERA_HPP

#include <string>

#include "commands/camera/BaseCameraCommand.hpp"

class LoadCamera : public BaseCameraCommand
{
public:
    LoadCamera() = delete;
    explicit LoadCamera(std::string name);
    ~LoadCamera() override = default;

    void execute() override;

private:
    std::string _name{};
    std::string _config_file{};
};


#endif//LAB_03_LOADCAMERA_HPP
