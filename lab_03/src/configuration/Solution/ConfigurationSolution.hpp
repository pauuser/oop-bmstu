//
// Created by Pavel Ivanov on 17.05.2022.
//

#ifndef LAB_03_CONFIGURATIONSOLUTION_HPP
#define LAB_03_CONFIGURATIONSOLUTION_HPP

#include "configuration/BaseConfiguration.hpp"


class ConfigurationSolution
{
public:
    ConfigurationSolution() = default;
    ~ConfigurationSolution() = default;

    std::shared_ptr<BaseConfiguration> createCreator();
    void registration(std::shared_ptr<BaseConfiguration> configuration);

private:
    std::shared_ptr<BaseConfiguration> _configuration;
};


#endif//LAB_03_CONFIGURATIONSOLUTION_HPP
