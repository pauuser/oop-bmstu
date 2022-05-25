//
// Created by Pavel Ivanov on 17.05.2022.
//

#include "LoadCamera.hpp"
#include "managers/LoadManager/LoadManager.hpp"

LoadCamera::LoadCamera(std::string name)
{
    _name = name;
}

void LoadCamera::execute(std::shared_ptr<Controller> controller)
{
    controller->LoadCamera(this->_name);
}