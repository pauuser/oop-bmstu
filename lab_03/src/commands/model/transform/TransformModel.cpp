//
// Created by Pavel Ivanov on 14.05.2022.
//

#include "TransformModel.hpp"
#include "managers/TransformManager/TransformManager.hpp"
#include "managers/SceneManager/SceneManager.hpp"

TransformModel::TransformModel(std::size_t id, const Point &move_params, const Point &scale_params, const Point &rotate_params):
                               _id(id), _move_params(move_params), _scale_params(scale_params), _rotate_params(rotate_params) {
    _manager = TransformManagerCreator().getManager();
    _act = &TransformManager::transformVisible;
}

void TransformModel::execute()
{
    ((*_manager).*_act)(_id, _move_params, _scale_params, _rotate_params);
}