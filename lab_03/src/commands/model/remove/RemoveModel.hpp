//
// Created by Pavel Ivanov on 14.05.2022.
//

#ifndef LAB_03_REMOVEMODEL_HPP
#define LAB_03_REMOVEMODEL_HPP

#include <memory>

#include "commands/model/BaseModelCommand.hpp"

class RemoveModel : public BaseModelCommand
{
public:
    RemoveModel() = delete;
    explicit RemoveModel(std::size_t id);
    ~RemoveModel() override = default;

    void execute(std::shared_ptr<Controller> controller) override;

private:
    std::size_t _id = 0;
};


#endif//LAB_03_REMOVEMODEL_HPP
