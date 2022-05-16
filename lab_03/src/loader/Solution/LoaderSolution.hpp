//
// Created by Pavel Ivanov on 16.05.2022.
//

#ifndef LAB_03_LOADERSOLUTION_HPP
#define LAB_03_LOADERSOLUTION_HPP

#include <map>
#include <memory>
#include <string>

#include "loader/BaseLoader.hpp"

using CallBackMap = std::map<std::string, std::unique_ptr<LoaderCreator> (*)()>;

class LoaderSolution
{
public:
    LoaderSolution() = default;
    ~LoaderSolution() = default;

    bool registration(std::string& object_type, std::unique_ptr<LoaderCreator> (*createLoader)());
    bool check(const std::string& object_type);
    std::unique_ptr<LoaderCreator> getLoaderCreator(std::string object_type);

private:
     static CallBackMap _callbacks;
};


#endif//LAB_03_LOADERSOLUTION_HPP
