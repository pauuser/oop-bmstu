//
// Created by Pavel Ivanov on 16.05.2022.
//

#include "LoadManager.hpp"

void LoadManager::setDirector(std::shared_ptr<BaseLoadDirector> director)
{
    _director = director;
}

std::shared_ptr<Object> LoadManager::load()
{
    return _director->load();
}

void LoadManagerCreator::_createManager()
{
    _manager = std::make_shared<LoadManager>();
}

std::shared_ptr<LoadManager> LoadManagerCreator::getManager()
{
    if (_manager == nullptr)
    {
        _createManager();
    }

    return _manager;
}
