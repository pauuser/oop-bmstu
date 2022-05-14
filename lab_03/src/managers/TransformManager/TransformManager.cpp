//
// Created by Pavel Ivanov on 14.05.2022.
//

#include "TransformManager.hpp"

void TransformManager::transform(std::shared_ptr<Object> &obj, const Point &move_params, const Point &scale_params, const Point &rotate_params)
{
    obj->transform(move_params, scale_params, rotate_params);
}

void TransformManagerCreator::_createManager()
{
    this->_manager = std::make_shared<TransformManager>();
}

std::shared_ptr<TransformManager> TransformManagerCreator::getManager()
{
    if (this->_manager == nullptr)
    {
        this->_createManager();
    }

    return this->_manager;
}

