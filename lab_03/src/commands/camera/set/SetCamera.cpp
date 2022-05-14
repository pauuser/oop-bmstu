//
// Created by Pavel Ivanov on 14.05.2022.
//

#include "SetCamera.hpp"
#include "managers/SceneManager/SceneManager.hpp"

SetCamera::SetCamera(std::size_t id): _id(id) {}

void SetCamera::execute()
{
    auto scene_manager = SceneManagerCreator().getManager();
    auto it = scene_manager->getScene()->begin();

    std::advance(it, this->_id);
    scene_manager->setMainCamera(it);
}