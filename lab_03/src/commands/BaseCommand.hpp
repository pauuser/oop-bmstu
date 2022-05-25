//
// Created by Pavel Ivanov on 12.05.2022.
//

#ifndef LAB_03_BASECOMMAND_HPP
#define LAB_03_BASECOMMAND_HPP

#include "controller/Controller.hpp"

class BaseCommand
{
public:
    BaseCommand() = default;
    virtual ~BaseCommand() = default;

    virtual void execute(std::shared_ptr<Controller> controller) = 0;
};

#endif//LAB_03_BASECOMMAND_HPP
