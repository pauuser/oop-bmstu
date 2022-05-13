//
// Created by Pavel Ivanov on 13.05.2022.
//

#include "FrameModel.hpp"

FrameModel::FrameModel(std::shared_ptr<FrameModelImplementation> imp) : _implementation(imp) {}

void FrameModel::accept(std::shared_ptr<Visitor> visitor)
{
    visitor->visit(*this); // TODO: check if visitor defined
}

void FrameModel::transform(const Point& move_params, const Point& scale_params, const Point& rotate_params)
{
    this->_implementation->transform(move_params, scale_params, rotate_params);
}

