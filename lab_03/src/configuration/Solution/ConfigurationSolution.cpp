//
// Created by Pavel Ivanov on 17.05.2022.
//

#include "ConfigurationSolution.hpp"

std::shared_ptr<BaseConfiguration> ConfigurationSolution::createCreator()
{
    if (!this->_configuration)
    {
        // TODO : add_exception
    }

    return this->_configuration;
}

void ConfigurationSolution::registration(std::shared_ptr<BaseConfiguration> configuration)
{
    _configuration = configuration;
}
