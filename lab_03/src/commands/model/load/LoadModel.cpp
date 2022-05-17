//
// Created by Pavel Ivanov on 17.05.2022.
//

#include "LoadModel.hpp"
#include "managers/LoadManager/LoadManager.hpp"
#include "managers/SceneManager/SceneManager.hpp"
#include "director/ModelDirector/ModelDirector.hpp"
#include "configuration/TextConfiguration/TextConfiguration.hpp"
#include "configuration/Solution/ConfigurationSolution.hpp"

LoadModel::LoadModel(std::string name, std::string config_file)
{
    _name = name;
    _config_file = config_file;
}

void LoadModel::execute()
{
    auto configuration_solution = std::make_shared<ConfigurationSolution>();
    configuration_solution->registration(TextConfigurationCreator(_config_file).getConfiguration());

    configuration_solution->createCreator()->register_framework();

    auto manager = LoadManagerCreator().getManager();
    auto director = ModelDirectorCreator().getDirector(this->_name);
    manager->setDirector(director);

    auto model = manager->load();
    SceneManagerCreator().getManager()->getScene()->addObject(model);
}