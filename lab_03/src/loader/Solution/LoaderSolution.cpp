//
// Created by Pavel Ivanov on 16.05.2022.
//

#include "LoaderSolution.hpp"

bool LoaderSolution::registration(std::string &object_type, std::unique_ptr<LoaderCreator> (*createLoader)())
{
    return _callbacks.insert(CallBackMap::value_type(object_type, createLoader)).second;
}

bool LoaderSolution::check(const std::string& object_type)
{
    return _callbacks.count(object_type) > 0;
}

std::unique_ptr<LoaderCreator> LoaderSolution::getLoaderCreator(std::string object_type)
{
    auto it = _callbacks.find(object_type);

    if (it == _callbacks.end())
    {
        // TODO: throw exception
    }

    return std::unique_ptr<LoaderCreator>((it->second)());
}