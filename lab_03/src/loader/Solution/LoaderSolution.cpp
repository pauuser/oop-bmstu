//
// Created by Pavel Ivanov on 16.05.2022.
//

#include "LoaderSolution.hpp"

bool LoaderSolution::registration(const std::string object_type, std::shared_ptr<LoaderCreator> loader_creator)
{
    return _callbacks.insert(LoaderMap::value_type(object_type, loader_creator)).second;
}

bool LoaderSolution::check(const std::string& object_type)
{
    return _callbacks.count(object_type) > 0;
}

std::shared_ptr<LoaderCreator> LoaderSolution::getLoaderCreator(const std::string& object_type)
{
    auto it = _callbacks.find(object_type);

    if (it == _callbacks.end())
    {
        // TODO: throw exception
    }

    return std::shared_ptr<LoaderCreator>(it->second);
}