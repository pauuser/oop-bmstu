//
// Created by Pavel Ivanov on 14.05.2022.
//

#include "SetCamera.hpp"
#include "managers/SceneManager/SceneManager.hpp"

SetCamera::SetCamera(std::size_t id): _id(id) {
    _manager = SceneManagerCreator().getManager();
    _act = &SceneManager::setMainCamera;
}

void SetCamera::execute()
{
    ((*_manager).*_act)(_id);
}