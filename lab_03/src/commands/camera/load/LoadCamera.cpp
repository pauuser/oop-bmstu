//
// Created by Pavel Ivanov on 17.05.2022.
//

#include "LoadCamera.hpp"
#include "director/CameraDirector/CameraDirector.hpp"

LoadCamera::LoadCamera(std::string name) : _name(name) {
    auto director = CameraDirectorCreator().getDirector(this->_name);
    _manager = LoadManagerCreator().getManager(director);
    _act = &LoadManager::load;
}

void LoadCamera::execute()
{
    ((*_manager).*_act)();
}