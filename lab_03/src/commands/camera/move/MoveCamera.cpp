//
// Created by Pavel Ivanov on 14.05.2022.
//

#include "MoveCamera.hpp"
#include "managers/TransformManager/TransformManager.hpp"
#include "managers/SceneManager/SceneManager.hpp"

MoveCamera::MoveCamera(std::size_t id, const Point &move_params, const Point &scale_params, const Point &rotate_params):
                       _id(id), _move_params(move_params), _scale_params(scale_params), _rotate_params(rotate_params) {
    _manager = TransformManagerCreator().getManager();
    _act = &TransformManager::transformInvisible;
}

void MoveCamera::execute()
{
    ((*_manager).*_act)(_id, _move_params, _scale_params, _rotate_params);
}