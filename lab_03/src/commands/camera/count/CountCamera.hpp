//
// Created by Pavel Ivanov on 14.05.2022.
//

#ifndef LAB_03_COUNTCAMERA_HPP
#define LAB_03_COUNTCAMERA_HPP

#include <memory>

#include "commands/camera/BaseCameraCommand.hpp"

class CountCamera : public BaseCameraCommand
{
public:
    CountCamera() = delete;
    explicit CountCamera(std::shared_ptr<size_t>& size);
    ~CountCamera() override = default;

    void execute(std::shared_ptr<Controller> controller) override;

private:
    std::shared_ptr<size_t> _count;
};


#endif//LAB_03_COUNTCAMERA_HPP
