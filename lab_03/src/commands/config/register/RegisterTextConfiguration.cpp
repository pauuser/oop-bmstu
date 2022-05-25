//
// Created by Pavel Ivanov on 18.05.2022.
//

#include "RegisterTextConfiguration.hpp"

RegisterTextConfiguration::RegisterTextConfiguration(std::string filename)
{
    _filename = filename;
}

void RegisterTextConfiguration::execute(std::shared_ptr<Controller> controller)
{
    controller->RegisterTextConfiguration(_filename);
}