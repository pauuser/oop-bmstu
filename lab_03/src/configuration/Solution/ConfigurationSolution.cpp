//
// Created by Pavel Ivanov on 17.05.2022.
//

#include "ConfigurationSolution.hpp"
#include "exceptions/configuration/ConfigurationException.hpp"

std::shared_ptr<BaseConfiguration> ConfigurationSolution::createCreator()
{
    if (!this->_configuration)
    {
        throw NoConfigurationException(__FILE__, __LINE__);
    }

    return this->_configuration;
}

void ConfigurationSolution::registration(std::shared_ptr<BaseConfiguration> configuration)
{
    _configuration = configuration;
}
