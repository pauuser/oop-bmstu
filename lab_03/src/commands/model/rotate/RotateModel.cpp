//
// Created by Pavel Ivanov on 14.05.2022.
//

#include "RotateModel.hpp"
#include "managers/SceneManager/SceneManager.hpp"
#include "managers/TransformManager/TransformManager.hpp"

RotateModel::RotateModel(std::size_t id, double ax, double ay, double az): _id(id), _ax(ax), _ay(ay), _az(az) {
    _manager = TransformManagerCreator().getManager();
}

void RotateModel::execute()
{
    Point move{ 0, 0, 0 }, scale{ 1, 1, 1 }, rotate{ _ax, _ay, _az };
    _manager->transformVisible(_id, move, scale, rotate);
}
