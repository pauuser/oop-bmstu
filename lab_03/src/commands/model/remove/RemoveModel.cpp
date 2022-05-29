//
// Created by Pavel Ivanov on 14.05.2022.
//

#include "RemoveModel.hpp"
#include "managers/SceneManager/SceneManager.hpp"

RemoveModel::RemoveModel(std::size_t id): _id(id) {
    _manager = SceneManagerCreator().getManager();
}

void RemoveModel::execute()
{
    _manager->removeVisible(_id);
}