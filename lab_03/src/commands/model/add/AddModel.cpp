//
// Created by Pavel Ivanov on 14.05.2022.
//

#include "AddModel.hpp"
#include "managers/SceneManager/SceneManager.hpp"

AddModel::AddModel(std::shared_ptr<Object> obj): _obj(obj) {}

void AddModel::execute()
{
    SceneManagerCreator().getManager()->getScene()->addObject(this->_obj);
}
