//
// Created by Pavel Ivanov on 12.05.2022.
//

#ifndef LAB_03_BASECOMMAND_HPP
#define LAB_03_BASECOMMAND_HPP

class BaseCommand
{
public:
    BaseCommand() = default;
    virtual ~BaseCommand() = default;

    virtual void execute() = 0;
};

// TODO: add load and export (??) everywhere

#endif//LAB_03_BASECOMMAND_HPP
