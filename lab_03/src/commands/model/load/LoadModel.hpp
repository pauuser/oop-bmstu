//
// Created by Pavel Ivanov on 17.05.2022.
//

#ifndef LAB_03_LOADMODEL_HPP
#define LAB_03_LOADMODEL_HPP

#include <string>

#include "commands/model/BaseModelCommand.hpp"
#include "managers/LoadManager/LoadManager.hpp"

class LoadModel : public BaseModelCommand
{
    using Action = void(LoadManager::*)();

public:
    LoadModel() = delete;
    explicit LoadModel(std::string name);
    ~LoadModel() override = default;

    void execute() override;

private:
    Action _act;

    std::string _name{};

    std::shared_ptr<LoadManager> _manager;
};


#endif//LAB_03_LOADMODEL_HPP
