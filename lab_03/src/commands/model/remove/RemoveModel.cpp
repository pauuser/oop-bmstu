//
// Created by Pavel Ivanov on 14.05.2022.
//

#include "RemoveModel.hpp"
#include "managers/SceneManager/SceneManager.hpp"

RemoveModel::RemoveModel(std::size_t id): _id(id) {}

void RemoveModel::execute()
{
    auto scene = SceneManagerCreator().getManager()->getScene();
    auto it = scene->begin();

    std::advance(it, this->_id);

    scene->removeObject(it);
}
