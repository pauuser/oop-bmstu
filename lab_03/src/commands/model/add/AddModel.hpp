//
// Created by Pavel Ivanov on 14.05.2022.
//

#ifndef LAB_03_ADDMODEL_HPP
#define LAB_03_ADDMODEL_HPP

#include "commands/model/BaseModelCommand.hpp"
#include "objects/Object.hpp"
#include "managers/SceneManager/SceneManager.hpp"

class AddModel : public BaseModelCommand
{
    using Action = void(SceneManager::*)(const std::shared_ptr<Object> &);

public:
    AddModel() = delete;
    explicit AddModel(std::shared_ptr<Object> obj);
    ~AddModel() override = default;

    void execute() override;

private:
    Action _act;

    std::shared_ptr<Object> _obj;

    std::shared_ptr<SceneManager> _manager;
};


#endif//LAB_03_ADDMODEL_HPP
