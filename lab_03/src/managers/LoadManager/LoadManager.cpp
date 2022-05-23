//
// Created by Pavel Ivanov on 16.05.2022.
//

#include "LoadManager.hpp"
#include "managers/SceneManager/SceneManager.hpp"

void LoadManager::setDirector(std::shared_ptr<BaseLoadDirector> director)
{
    _director = director;
}

void LoadManager::load()
{
    auto obj =  _director->load();
    SceneManagerCreator().getManager()->addObject(obj);
}

void LoadManagerCreator::_createManager()
{
    _manager = std::make_shared<LoadManager>();
}

std::shared_ptr<LoadManager> LoadManagerCreator::getManager(std::shared_ptr<BaseLoadDirector> director)
{
    if (_manager == nullptr)
    {
        _createManager();
    }

    _manager->setDirector(director);

    return _manager;
}
