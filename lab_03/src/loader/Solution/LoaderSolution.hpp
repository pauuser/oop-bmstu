//
// Created by Pavel Ivanov on 16.05.2022.
//

#ifndef LAB_03_LOADERSOLUTION_HPP
#define LAB_03_LOADERSOLUTION_HPP

#include <map>
#include <memory>
#include <string>

#include "loader/BaseLoader.hpp"

using LoaderMap = std::map<const std::string, std::shared_ptr<LoaderCreator>>;

class LoaderSolution
{
public:
    LoaderSolution() = default;
    ~LoaderSolution() = default;

    bool registration(const std::string object_type, std::shared_ptr<LoaderCreator> loader_creator);
    bool check(const std::string& object_type);
    std::shared_ptr<LoaderCreator> getLoaderCreator(const std::string& object_type);

private:
     static LoaderMap _callbacks;
};


#endif//LAB_03_LOADERSOLUTION_HPP
