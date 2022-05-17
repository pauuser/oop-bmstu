//
// Created by Pavel Ivanov on 16.05.2022.
//

#include "LoaderSolution.hpp"
#include "exceptions/director/DirectorException.hpp"

bool LoaderSolution::registration(const std::string object_type, std::shared_ptr<LoaderCreator> loader_creator)
{
    if (check(object_type))
    {
        _callbacks->erase(object_type);
    }

    return _callbacks->insert(LoaderMap::value_type(object_type, loader_creator)).second;
}

LoaderSolution::LoaderSolution()
{
    static auto loader_map = std::make_shared<LoaderMap>();
    _callbacks = loader_map;
}

bool LoaderSolution::check(const std::string& object_type)
{
    return _callbacks->count(object_type) > 0;
}

std::shared_ptr<LoaderCreator> LoaderSolution::getLoaderCreator(const std::string& object_type)
{
    auto it = _callbacks->find(object_type);

    if (it == _callbacks->end())
    {
        throw NoLoaderException(__FILE__, __LINE__);
    }

    return std::shared_ptr<LoaderCreator>(it->second);
}