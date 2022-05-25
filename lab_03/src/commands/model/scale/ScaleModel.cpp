//
// Created by Pavel Ivanov on 14.05.2022.
//

#include "ScaleModel.hpp"
#include "managers/SceneManager/SceneManager.hpp"
#include "managers/TransformManager/TransformManager.hpp"

ScaleModel::ScaleModel(std::size_t id, double kx, double ky, double kz): _id(id), _kx(kx), _ky(ky), _kz(kz) {}

void ScaleModel::execute(std::shared_ptr<Controller> controller)
{
    controller->ScaleModel(_id, _kx, _ky, _kz);
}