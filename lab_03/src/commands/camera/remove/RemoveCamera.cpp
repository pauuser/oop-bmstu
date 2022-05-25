//
// Created by Pavel Ivanov on 14.05.2022.
//

#include "RemoveCamera.hpp"
#include "managers/SceneManager/SceneManager.hpp"

RemoveCamera::RemoveCamera(std::size_t id): _id(id) {}

void RemoveCamera::execute(std::shared_ptr<Controller> controller)
{
    controller->RemoveCamera(_id);
}