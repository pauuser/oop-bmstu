//
// Created by Pavel Ivanov on 14.05.2022.
//

#include "MoveModel.hpp"
#include "managers/SceneManager/SceneManager.hpp"
#include "managers/TransformManager/TransformManager.hpp"

MoveModel::MoveModel(std::size_t id, double dx, double dy, double dz): _id(id), _dx(dx), _dy(dy), _dz(dz) {}

void MoveModel::execute()
{
    Point move{ _dx, _dy, _dz }, scale{ 1, 1, 1 }, rotate{ 0, 0, 0 };
    _transformmanager->transformVisible(_id, move, scale, rotate);
}