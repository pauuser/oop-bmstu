//
// Created by Pavel Ivanov on 14.05.2022.
//

#include "SetCamera.hpp"
#include "managers/SceneManager/SceneManager.hpp"

SetCamera::SetCamera(std::size_t id)
{
    auto scene = SceneManagerCreator().getManager()->getScene();
}