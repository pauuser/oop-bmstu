//
// Created by Pavel Ivanov on 14.05.2022.
//

#ifndef LAB_03_ROTATEMODEL_HPP
#define LAB_03_ROTATEMODEL_HPP

#include <memory>

#include "commands/model/BaseModelCommand.hpp"

class RotateModel : public BaseModelCommand
{
public:
    RotateModel() = delete;
    explicit RotateModel(std::size_t id, double ax, double ay, double az);
    ~RotateModel() override = default;

    void execute(std::shared_ptr<Controller> controller) override;

private:
    std::size_t _id = 0;
    double _ax = 0, _ay = 0, _az = 0;
};


#endif//LAB_03_ROTATEMODEL_HPP
