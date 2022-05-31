//
// Created by Pavel Ivanov on 14.05.2022.
//

#ifndef LAB_03_MOVECAMERA_HPP
#define LAB_03_MOVECAMERA_HPP

#include <memory>

#include "commands/camera/BaseCameraCommand.hpp"
#include "objects/Point/Point.hpp"
#include "managers/TransformManager/TransformManager.hpp"

class MoveCamera : public BaseCameraCommand
{
    using Action = void(TransformManager::*)(size_t, const Point &, const Point &, const Point &);

public:
    MoveCamera() = delete;
    explicit MoveCamera(std::size_t id, const Point& move_params,
                                        const Point& scale_params,
                                        const Point& rotate_params);
    ~MoveCamera() override = default;

    void execute() override;

private:
    Action _act;

    const Point& _move_params, _scale_params, _rotate_params;
    std::size_t  _id;

    std::shared_ptr<TransformManager> _manager;
};


#endif//LAB_03_MOVECAMERA_HPP
