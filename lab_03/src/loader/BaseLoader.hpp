//
// Created by Pavel Ivanov on 15.05.2022.
//

#ifndef LAB_03_BASELOADER_HPP
#define LAB_03_BASELOADER_HPP

#include <string>
#include <fstream>

class BaseLoader
{
public:
    BaseLoader() = default;
    virtual ~BaseLoader() = default;

    virtual void load(std::string &name) = 0; // TODO: здесь билдер
    virtual void open(std::string &filename) = 0;
    virtual void close() = 0;
};


#endif//LAB_03_BASELOADER_HPP
