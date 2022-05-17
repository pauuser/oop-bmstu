//
// Created by Pavel Ivanov on 16.05.2022.
//

#ifndef LAB_03_BASECONFIGURATION_HPP
#define LAB_03_BASECONFIGURATION_HPP

#include <memory>
#include <string>

class BaseConfiguration
{
public:
    BaseConfiguration() = default;
    virtual ~BaseConfiguration() = default;

    virtual void read_configuration() = 0;
    virtual void register_framework() = 0;
};

class ConfigurationCreator
{
public:
    ConfigurationCreator() = default;
    virtual ~ConfigurationCreator() = default;

    virtual std::shared_ptr<BaseConfiguration> getConfiguration() = 0;
};


#endif//LAB_03_BASECONFIGURATION_HPP
