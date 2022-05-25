//
// Created by Pavel Ivanov on 14.05.2022.
//

#include "RotateModel.hpp"
#include "managers/SceneManager/SceneManager.hpp"
#include "managers/TransformManager/TransformManager.hpp"

RotateModel::RotateModel(std::size_t id, double ax, double ay, double az): _id(id), _ax(ax), _ay(ay), _az(az) {}

void RotateModel::execute(std::shared_ptr<Controller> controller)
{
    controller->RotateModel(_id, _ax, _ay, _az);
}
