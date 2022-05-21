//
// Created by Pavel Ivanov on 18.05.2022.
//

#ifndef LAB_03_REGISTERTEXTCONFIGURATION_HPP
#define LAB_03_REGISTERTEXTCONFIGURATION_HPP

#include <string>

#include "commands/config/BaseConfigCommand.hpp"

class RegisterTextConfiguration : public BaseConfigCommand
{
public:
    RegisterTextConfiguration() = delete;
    explicit RegisterTextConfiguration(std::string filename);
    ~RegisterTextConfiguration() override = default;

    void execute() override;

private:
    std::string _filename;

};


#endif//LAB_03_REGISTERTEXTCONFIGURATION_HPP
