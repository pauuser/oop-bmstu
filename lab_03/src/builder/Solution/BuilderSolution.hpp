//
// Created by Pavel Ivanov on 16.05.2022.
//

#ifndef LAB_03_BUILDERSOLUTION_HPP
#define LAB_03_BUILDERSOLUTION_HPP

#include <map>
#include <memory>
#include <string>

#include "builder/BaseBuilder.hpp"

using BuilderMap = std::map<const std::string, std::shared_ptr<BuilderCreator>>;

class BuilderSolution
{
public:
    BuilderSolution() = default;
    ~BuilderSolution() = default;

    bool registration(const std::string object_type, std::shared_ptr<BuilderCreator> builder_creator);
    bool check(const std::string& object_type);
    std::shared_ptr<BuilderCreator> getBuilderCreator(const std::string object_type);

private:
    static BuilderMap _callbacks;
};

#endif//LAB_03_BUILDERSOLUTION_HPP
