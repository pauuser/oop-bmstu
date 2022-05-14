//
// Created by Pavel Ivanov on 14.05.2022.
//

#include "MoveModel.hpp"
#include "managers/SceneManager/SceneManager.hpp"

MoveModel::MoveModel(std::size_t id, double dx, double dy, double dz): _id(id), _dx(dx), _dy(dy), _dz(dz) {}

void MoveModel::execute()
{
    auto scene = SceneManagerCreator().getManager()->getScene();
    auto it = scene->begin();
    std::advance(it, this->_id);

    Point move{ _dx, _dy, _dz };
    Point scale{ 1, 1, 1 };
    Point rotate{ 0, 0, 0 };

    (*it)->transform(move, scale, rotate);
}