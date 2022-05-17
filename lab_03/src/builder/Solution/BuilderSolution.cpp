//
// Created by Pavel Ivanov on 16.05.2022.
//

#include "BuilderSolution.hpp"

bool BuilderSolution::registration(const std::string object_type, std::shared_ptr<BuilderCreator> builder_creator)
{
    return _callbacks.insert(BuilderMap::value_type(object_type, builder_creator)).second;
}

bool BuilderSolution::check(const std::string &object_type)
{
    return _callbacks.count(object_type) > 0;
}

std::shared_ptr<BuilderCreator> BuilderSolution::getBuilderCreator(const std::string object_type)
{
    auto it = _callbacks.find(object_type);

    if (it == _callbacks.end())
    {
        // TODO: throw exception
    }

    return std::shared_ptr<BuilderCreator>(it->second);
}