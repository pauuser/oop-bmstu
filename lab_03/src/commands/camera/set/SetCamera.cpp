//
// Created by Pavel Ivanov on 14.05.2022.
//

#include "SetCamera.hpp"
#include "managers/SceneManager/SceneManager.hpp"

SetCamera::SetCamera(std::size_t id): _id(id) {}

void SetCamera::execute(std::shared_ptr<Controller> controller)
{
    controller->SetCamera(_id);
}