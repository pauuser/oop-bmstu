//
// Created by Pavel Ivanov on 16.05.2022.
//

#include "BuilderSolution.hpp"
#include "exceptions/builder/BuilderException.hpp"

bool BuilderSolution::registration(const std::string object_type, std::shared_ptr<BuilderCreator> builder_creator)
{
    if (check(object_type))
    {
        _callbacks->erase(object_type);
    }

    return _callbacks->insert(BuilderMap::value_type(object_type, builder_creator)).second;
}

BuilderSolution::BuilderSolution()
{
    static auto builder_map = std::make_shared<BuilderMap>();
    _callbacks = builder_map;
}

bool BuilderSolution::check(const std::string &object_type)
{
    return _callbacks->count(object_type) > 0;
}

std::shared_ptr<BuilderCreator> BuilderSolution::getBuilderCreator(const std::string object_type)
{
    auto it = _callbacks->find(object_type);

    if (it == _callbacks->end())
    {
        throw BuilderNotRegisteredException(__FILE__, __LINE__);
    }

    return it->second;
}