//
// Created by Pavel Ivanov on 14.05.2022.
//

#ifndef LAB_03_MOVECAMERA_HPP
#define LAB_03_MOVECAMERA_HPP

#include <memory>

#include "commands/camera/BaseCameraCommand.hpp"
#include "objects/Point/Point.hpp"

class MoveCamera : public BaseCameraCommand
{
public:
    MoveCamera() = delete;
    explicit MoveCamera(std::size_t id, const Point& move_params,
                                        const Point& scale_params,
                                        const Point& rotate_params);
    ~MoveCamera() override = default;

    void execute(std::shared_ptr<Controller> controller) override;
private:
    const Point& _move_params, _scale_params, _rotate_params;
    std::size_t  _id;
};


#endif//LAB_03_MOVECAMERA_HPP
