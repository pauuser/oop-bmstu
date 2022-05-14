//
// Created by Pavel Ivanov on 14.05.2022.
//

#include "RemoveCamera.h"
#include "managers/SceneManager/SceneManager.hpp"

RemoveCamera::RemoveCamera(std::size_t id): _id(id) {}

void RemoveCamera::execute()
{
    auto scene = SceneManagerCreator().getManager()->getScene();
    auto it = scene->begin();
    std::advance(it, this->_id);

    scene->removeObject(it);
}