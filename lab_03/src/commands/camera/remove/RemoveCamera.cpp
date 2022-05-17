//
// Created by Pavel Ivanov on 14.05.2022.
//

#include "RemoveCamera.hpp"
#include "managers/SceneManager/SceneManager.hpp"

RemoveCamera::RemoveCamera(std::size_t id): _id(id) {}

void RemoveCamera::execute()
{
    auto scene = SceneManagerCreator().getManager()->getScene();
    auto it = scene->begin();

    std::size_t _cur = 0;

    do
    {
        if (!((*it)->isVisible()))
        {
            _cur++;
        }

        it++;
    }
    while (_cur < _id + 1);

    scene->removeObject(it - 1);
}