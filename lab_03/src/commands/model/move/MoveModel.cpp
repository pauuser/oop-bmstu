//
// Created by Pavel Ivanov on 14.05.2022.
//

#include "MoveModel.hpp"

MoveModel::MoveModel(std::size_t id, double dx, double dy, double dz): _id(id), _dx(dx), _dy(dy), _dz(dz) {
    _manager = TransformManagerCreator().getManager();
    _act = &TransformManager::transformVisible;
}

void MoveModel::execute()
{
    ((*_manager).*_act)(_id, { _dx, _dy, _dz }, { 1, 1, 1 }, {0, 0, 0});
}