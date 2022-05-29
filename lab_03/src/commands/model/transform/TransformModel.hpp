//
// Created by Pavel Ivanov on 14.05.2022.
//

#ifndef LAB_03_TRANSFORMMODEL_HPP
#define LAB_03_TRANSFORMMODEL_HPP

#include <memory>

#include "commands/model/BaseModelCommand.hpp"
#include "objects/Point/Point.hpp"
#include "managers/TransformManager/TransformManager.hpp"

class TransformModel : public BaseModelCommand
{
public:
    TransformModel() = delete;
    explicit TransformModel(std::size_t id, const Point& move_params,
                                            const Point& scale_params,
                                            const Point& rotate_params);
    ~TransformModel() override = default;

    void execute() override;

private:
    const Point& _move_params, _scale_params, _rotate_params;
    std::size_t  _id;

    std::shared_ptr<TransformManager> _manager;
};


#endif//LAB_03_TRANSFORMMODEL_HPP
