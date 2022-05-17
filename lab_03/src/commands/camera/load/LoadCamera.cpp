//
// Created by Pavel Ivanov on 17.05.2022.
//

#include "LoadCamera.hpp"
#include "managers/LoadManager/LoadManager.hpp"
#include "managers/SceneManager/SceneManager.hpp"
#include "director/CameraDirector/CameraDirector.hpp"
#include "configuration/Solution/ConfigurationSolution.hpp"
#include "configuration/TextConfiguration/TextConfiguration.hpp"

LoadCamera::LoadCamera(std::string name, std::string config_file)
{
    _name = name;
    _config_file = config_file;
}

void LoadCamera::execute()
{
    ConfigurationSolution().registration(TextConfigurationCreator(_config_file).getConfiguration());

    ConfigurationSolution().createCreator()->register_framework();

    auto manager = LoadManagerCreator().getManager();
    auto director = CameraDirectorCreator().getDirector(this->_name);
    manager->setDirector(director);

    auto model = manager->load();
    SceneManagerCreator().getManager()->getScene()->addObject(model);
}