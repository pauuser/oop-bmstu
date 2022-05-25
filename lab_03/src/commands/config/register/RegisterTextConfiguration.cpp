//
// Created by Pavel Ivanov on 18.05.2022.
//

#include "RegisterTextConfiguration.hpp"
#include "configuration/Solution/ConfigurationSolution.hpp"
#include "configuration/TextConfiguration/TextConfiguration.hpp"

RegisterTextConfiguration::RegisterTextConfiguration(std::string filename)
{
    _filename = filename;
}

void RegisterTextConfiguration::execute()
{
    auto solution = ConfigurationSolution();
    solution.registration(TextConfigurationCreator(_filename).getConfiguration());
    solution.createCreator()->register_framework();
}