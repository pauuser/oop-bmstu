//
// Created by Pavel Ivanov on 17.05.2022.
//

#include "LoadCamera.hpp"
#include "managers/LoadManager/LoadManager.hpp"
#include "managers/SceneManager/SceneManager.hpp"
#include "director/CameraDirector/CameraDirector.hpp"
#include "configuration/Solution/ConfigurationSolution.hpp"
#include "configuration/TextConfiguration/TextConfiguration.hpp"

LoadCamera::LoadCamera(std::string name)
{
    _name = name;
}

void LoadCamera::execute()
{
    auto manager = LoadManagerCreator().getManager();
    auto director = CameraDirectorCreator().getDirector(this->_name);
    manager->setDirector(director);

    auto camera = manager->load();

    auto scene_manager = SceneManagerCreator().getManager();
    auto scene = scene_manager->getScene();

    scene->addObject(camera);
    scene_manager->setMainCamera(scene->end() - 1); // TODO здесь главную сцену можно не делать, а сделать отдельную команду
}