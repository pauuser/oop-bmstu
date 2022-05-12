//
// Created by Pavel Ivanov on 12.05.2022.
//

#ifndef LAB_03_FACADE_HPP
#define LAB_03_FACADE_HPP

#include <memory>

class Facade
{
public:
    void execute(const std::shared_ptr<Command> command);
};


#endif//LAB_03_FACADE_HPP
