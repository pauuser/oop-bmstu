//
// Created by Pavel Ivanov on 15.05.2022.
//

#ifndef LAB_03_BASELOADER_HPP
#define LAB_03_BASELOADER_HPP

#include <string>

#include "builder/BaseBuilder.hpp"
#include "objects/Object.hpp"

class BaseLoader
{
public:
    BaseLoader() = default;
    virtual ~BaseLoader() = default;

    virtual std::shared_ptr<Object> load(std::shared_ptr<BaseBuilder> builder) = 0;
    virtual void open(std::string &name) = 0;
    virtual void close() = 0;
};

class LoaderCreator
{
public:
    LoaderCreator() = default;
    virtual ~LoaderCreator() = default;

    virtual std::shared_ptr<BaseLoader> createLoader() = 0;
};


#endif//LAB_03_BASELOADER_HPP
