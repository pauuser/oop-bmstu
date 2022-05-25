//
// Created by Pavel Ivanov on 14.05.2022.
//

#include "AddModel.hpp"
#include "managers/SceneManager/SceneManager.hpp"

AddModel::AddModel(std::shared_ptr<Object> obj): _obj(obj) {}

void AddModel::execute(std::shared_ptr<Controller> controller)
{
    controller->AddModel(_obj);
}
