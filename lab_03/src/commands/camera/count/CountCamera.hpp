//
// Created by Pavel Ivanov on 14.05.2022.
//

#ifndef LAB_03_COUNTCAMERA_HPP
#define LAB_03_COUNTCAMERA_HPP

#include <memory>

#include "commands/camera/BaseCameraCommand.hpp"
#include "managers/SceneManager/SceneManager.hpp"

class CountCamera : public BaseCameraCommand
{
public:
    CountCamera() = delete;
    explicit CountCamera(std::shared_ptr<size_t>& size);
    ~CountCamera() override = default;

    void execute() override;

private:
    std::shared_ptr<size_t> _count;
    std::shared_ptr<SceneManager> _manager;
};


#endif//LAB_03_COUNTCAMERA_HPP
