//
// Created by Pavel Ivanov on 14.05.2022.
//

#ifndef LAB_03_SCALEMODEL_HPP
#define LAB_03_SCALEMODEL_HPP

#include <memory>

#include "commands/model/BaseModelCommand.hpp"
#include "managers/TransformManager/TransformManager.hpp"

class ScaleModel : public BaseModelCommand
{
    using Action = void(TransformManager::*)(size_t, const Point &, const Point &, const Point &);

public:
    ScaleModel() = delete;
    explicit ScaleModel(std::size_t id, double kx, double ky, double kz);
    ~ScaleModel() override = default;

    void execute() override;

private:
    Action _act;

    std::size_t _id = 0;
    double _kx = 0, _ky = 0, _kz = 0;

    std::shared_ptr<TransformManager> _manager;
};


#endif//LAB_03_SCALEMODEL_HPP
