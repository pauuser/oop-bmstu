//
// Created by Pavel Ivanov on 14.05.2022.
//

#ifndef LAB_03_ADDMODEL_HPP
#define LAB_03_ADDMODEL_HPP

#include "commands/model/BaseModelCommand.hpp"
#include "objects/Object.hpp"

class AddModel : public BaseModelCommand
{
public:
    AddModel() = delete;
    explicit AddModel(std::shared_ptr<Object> obj);
    ~AddModel() override = default;

    void execute(std::shared_ptr<Controller> controller) override;

private:
    std::shared_ptr<Object> _obj;
};


#endif//LAB_03_ADDMODEL_HPP
