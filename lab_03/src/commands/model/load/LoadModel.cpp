//
// Created by Pavel Ivanov on 17.05.2022.
//

#include "LoadModel.hpp"

LoadModel::LoadModel(std::string name)
{
    _name = name;
}

void LoadModel::execute(std::shared_ptr<Controller> controller)
{
    controller->LoadModel(_name);
}