//
// Created by Pavel Ivanov on 14.05.2022.
//

#include "RemoveModel.hpp"
#include "managers/SceneManager/SceneManager.hpp"

RemoveModel::RemoveModel(std::size_t id): _id(id) {}

void RemoveModel::execute(std::shared_ptr<Controller> controller)
{
    controller->RemoveModel(_id);
}