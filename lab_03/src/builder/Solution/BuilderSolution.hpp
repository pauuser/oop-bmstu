//
// Created by Pavel Ivanov on 16.05.2022.
//

#ifndef LAB_03_BUILDERSOLUTION_HPP
#define LAB_03_BUILDERSOLUTION_HPP

#include <map>
#include <memory>
#include <string>

#include "builder/BaseBuilder.hpp"

using CallBackMap = std::map<std::string, std::unique_ptr<BuilderCreator> (*)()>;

class BuilderSolution
{
public:
    BuilderSolution() = default;
    ~BuilderSolution() = default;

    bool registration(std::string& object_type, std::unique_ptr<BuilderCreator> (*createLoader)());
    bool check(const std::string& object_type);
    std::unique_ptr<BuilderCreator> getBuilderCreator(std::string object_type);

private:
    static CallBackMap _callbacks;
};

#endif//LAB_03_BUILDERSOLUTION_HPP
