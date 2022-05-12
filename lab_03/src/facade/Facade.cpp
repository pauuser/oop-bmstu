//
// Created by Pavel Ivanov on 12.05.2022.
//

#include "Facade.hpp"

void Facade::execute(const std::shared_ptr<Command> command)
{
    command->exexute();
}
