//
// Created by Pavel Ivanov on 14.05.2022.
//

#include "ScaleModel.hpp"
#include "managers/SceneManager/SceneManager.hpp"
#include "managers/TransformManager/TransformManager.hpp"

ScaleModel::ScaleModel(std::size_t id, double kx, double ky, double kz): _id(id), _kx(kx), _ky(ky), _kz(kz) {
    _manager = TransformManagerCreator().getManager();
    _act = &TransformManager::transformVisible;
}

void ScaleModel::execute()
{
    ((*_manager).*_act)(_id, {0, 0, 0}, { _kx, _ky, _kz }, {0, 0, 0});
}

