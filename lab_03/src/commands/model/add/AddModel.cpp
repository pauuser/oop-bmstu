//
// Created by Pavel Ivanov on 14.05.2022.
//

#include "AddModel.hpp"
#include "managers/SceneManager/SceneManager.hpp"

AddModel::AddModel(std::shared_ptr<Object> obj): _obj(obj) {
    _manager = SceneManagerCreator().getManager();
}

void AddModel::execute()
{
    _manager->addObject(this->_obj);
}
