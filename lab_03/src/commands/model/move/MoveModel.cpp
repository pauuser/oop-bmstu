//
// Created by Pavel Ivanov on 14.05.2022.
//

#include "MoveModel.hpp"

MoveModel::MoveModel(std::size_t id, double dx, double dy, double dz): _id(id), _dx(dx), _dy(dy), _dz(dz) {
    _manager = TransformManagerCreator().getManager();
}

void MoveModel::execute()
{
    Point move{ _dx, _dy, _dz }, scale{ 1, 1, 1 }, rotate{ 0, 0, 0 };
    _manager->transformVisible(_id, move, scale, rotate);
}