//
// Created by Pavel Ivanov on 14.05.2022.
//

#include "ScaleModel.hpp"
#include "managers/SceneManager/SceneManager.hpp"
#include "managers/TransformManager/TransformManager.hpp"

ScaleModel::ScaleModel(std::size_t id, double kx, double ky, double kz): _id(id), _kx(kx), _ky(ky), _kz(kz) {}

void ScaleModel::execute()
{
    Point move{ 0, 0, 0 }, scale{ _kx, _ky, _kz }, rotate{ 0, 0, 0 };
    _transformmanager->transformVisible(_id, move, scale, rotate);
}

