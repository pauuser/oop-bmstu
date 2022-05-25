//
// Created by Pavel Ivanov on 12.05.2022.
//

#include "Facade.hpp"

Facade::Facade() : _controller(Controller::getInstance()){}

Facade::~Facade()
{
    _controller.reset();
}

void Facade::execute(const std::shared_ptr<BaseCommand> command)
{
    command->execute(_controller);
}
