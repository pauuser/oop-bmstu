//
// Created by Pavel Ivanov on 17.05.2022.
//

#include "LoadModel.hpp"
#include "managers/LoadManager/LoadManager.hpp"
#include "managers/SceneManager/SceneManager.hpp"
#include "director/ModelDirector/ModelDirector.hpp"
#include "configuration/TextConfiguration/TextConfiguration.hpp"
#include "configuration/Solution/ConfigurationSolution.hpp"

LoadModel::LoadModel(std::string name)
{
    _name = name;
}

void LoadModel::execute()
{
    auto manager = LoadManagerCreator().getManager();
    auto director = ModelDirectorCreator().getDirector(this->_name);
    manager->setDirector(director);

    auto model = manager->load();
    SceneManagerCreator().getManager()->getScene()->addObject(model);
}