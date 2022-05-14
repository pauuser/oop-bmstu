//
// Created by Pavel Ivanov on 14.05.2022.
//

#ifndef LAB_03_REMOVECAMERA_H
#define LAB_03_REMOVECAMERA_H

#include <memory>

#include "commands/camera/BaseCameraCommand.hpp"

class RemoveCamera : public BaseCameraCommand
{
public:
    RemoveCamera() = delete;
    explicit RemoveCamera(std::size_t id);
    ~RemoveCamera() override = default;

    void execute() override;

private:
    std::size_t _id;
};


#endif//LAB_03_REMOVECAMERA_H
