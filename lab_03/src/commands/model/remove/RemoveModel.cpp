//
// Created by Pavel Ivanov on 14.05.2022.
//

#include "RemoveModel.hpp"
#include "managers/SceneManager/SceneManager.hpp"

RemoveModel::RemoveModel(std::size_t id): _id(id) {}

void RemoveModel::execute()
{
    auto scene = SceneManagerCreator().getManager()->getScene();
    auto it = scene->begin();

    std::size_t _cur = 0;

    do
    {
        if ((*it)->isVisible())
        {
            _cur++;
        }

        it++;
    }
    while (_cur < _id);

    scene->removeObject(it--);
}
