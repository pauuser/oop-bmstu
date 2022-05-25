//
// Created by Pavel Ivanov on 12.05.2022.
//

#ifndef LAB_03_FACADE_HPP
#define LAB_03_FACADE_HPP

#include <memory>
#include "commands/BaseCommand.hpp"
#include "controller/Controller.hpp"

class Facade
{
public:
    Facade();
    ~Facade();

    void execute(std::shared_ptr<BaseCommand> command);

private:
    std::shared_ptr<Controller> _controller;
};


#endif//LAB_03_FACADE_HPP
