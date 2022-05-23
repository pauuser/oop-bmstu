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
    auto director = CameraDirectorCreator().getDirector(this->_name);
    LoadManagerCreator().getManager(director)->load();
}