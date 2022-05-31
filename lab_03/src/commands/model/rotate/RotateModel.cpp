//
// Created by Pavel Ivanov on 14.05.2022.
//

#include "RotateModel.hpp"
#include "managers/SceneManager/SceneManager.hpp"
#include "managers/TransformManager/TransformManager.hpp"

RotateModel::RotateModel(std::size_t id, double ax, double ay, double az): _id(id), _ax(ax), _ay(ay), _az(az) {
    _manager = TransformManagerCreator().getManager();
    _act = &TransformManager::transformVisible;
}

void RotateModel::execute()
{
    ((*_manager).*_act)(_id, {0, 0, 0}, { 1, 1, 1 }, { _ax, _ay, _az });
}
