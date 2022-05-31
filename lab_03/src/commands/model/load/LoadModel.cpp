//
// Created by Pavel Ivanov on 17.05.2022.
//

#include "LoadModel.hpp"
#include "managers/LoadManager/LoadManager.hpp"
#include "managers/SceneManager/SceneManager.hpp"
#include "director/ModelDirector/ModelDirector.hpp"
#include "configuration/TextConfiguration/TextConfiguration.hpp"
#include "configuration/Solution/ConfigurationSolution.hpp"

LoadModel::LoadModel(std::string name) : _name(name) {
    auto director = ModelDirectorCreator().getDirector(this->_name);
    _manager = LoadManagerCreator().getManager(director);
    _act = &LoadManager::load;
}

void LoadModel::execute()
{
    ((*_manager).*_act)();
}