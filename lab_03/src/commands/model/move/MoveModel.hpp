//
// Created by Pavel Ivanov on 14.05.2022.
//

#ifndef LAB_03_MOVEMODEL_HPP
#define LAB_03_MOVEMODEL_HPP

#include <memory>

#include "commands/model/BaseModelCommand.hpp"
#include "managers/TransformManager/TransformManager.hpp"

class MoveModel : public BaseModelCommand
{
public:
    MoveModel() = delete;
    explicit MoveModel(std::size_t id, double dx, double dy, double dz);
    ~MoveModel() override = default;

    void execute() override;

private:
    std::size_t _id = 0;
    double _dx = 0, _dy = 0, _dz = 0;

    std::shared_ptr<TransformManager> _manager;
};


#endif//LAB_03_MOVEMODEL_HPP
