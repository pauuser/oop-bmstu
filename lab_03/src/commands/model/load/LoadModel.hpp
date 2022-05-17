//
// Created by Pavel Ivanov on 17.05.2022.
//

#ifndef LAB_03_LOADMODEL_HPP
#define LAB_03_LOADMODEL_HPP

#include <string>

#include "commands/model/BaseModelCommand.hpp"

class LoadModel : public BaseModelCommand
{
public:
    LoadModel() = delete;
    explicit LoadModel(std::string name, std::string config_file);
    ~LoadModel() override = default;

    void execute() override;

private:
    std::string _name{};
    std::string _config_file{};
};


#endif//LAB_03_LOADMODEL_HPP
