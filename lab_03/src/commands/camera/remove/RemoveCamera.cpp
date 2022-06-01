//
// Created by Pavel Ivanov on 14.05.2022.
//

#include "RemoveCamera.hpp"
#include "managers/SceneManager/SceneManager.hpp"

RemoveCamera::RemoveCamera(std::size_t id): _id(id) {
    _manager = SceneManagerCreator().getManager();
    _act = &SceneManager::removeInvisible;
}

void RemoveCamera::execute()
{
    ((*_manager).*_act)(_id);
}