//
// Created by Pavel Ivanov on 16.05.2022.
//

#include "BuilderSolution.hpp"

bool BuilderSolution::registration(std::string &object_type, std::unique_ptr<BuilderCreator> (*createBuilder)())
{
    return _callbacks.insert(CallBackMap::value_type(object_type, createBuilder)).second;
}

bool BuilderSolution::check(const std::string &object_type)
{
    return _callbacks.count(object_type) > 0;
}

std::unique_ptr<BuilderCreator> BuilderSolution::getBuilderCreator(std::string object_type)
{
    auto it = _callbacks.find(object_type);

    if (it == _callbacks.end())
    {
        // TODO: throw exception
    }

    return std::unique_ptr<BuilderCreator>((it->second)());
}