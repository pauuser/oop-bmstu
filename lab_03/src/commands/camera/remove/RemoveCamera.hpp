//
// Created by Pavel Ivanov on 14.05.2022.
//

#ifndef LAB_03_REMOVECAMERA_HPP
#define LAB_03_REMOVECAMERA_HPP

#include <memory>

#include "commands/camera/BaseCameraCommand.hpp"
#include "managers/SceneManager/SceneManager.hpp"

class RemoveCamera : public BaseCameraCommand
{
public:
    RemoveCamera() = delete;
    explicit RemoveCamera(std::size_t id);
    ~RemoveCamera() override = default;

    void execute() override;

private:
    std::size_t _id;

    std::shared_ptr<SceneManager> _manager;
};


#endif//LAB_03_REMOVECAMERA_HPP
