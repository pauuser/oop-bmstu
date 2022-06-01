//
// Created by Pavel Ivanov on 12.05.2022.
//

#ifndef LAB_03_FACADE_HPP
#define LAB_03_FACADE_HPP

#include <memory>
#include "commands/BaseCommand.hpp"

class Facade
{
public:
    void execute(std::shared_ptr<BaseCommand> command);
};


#endif//LAB_03_FACADE_HPP
