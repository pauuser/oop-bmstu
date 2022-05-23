//
// Created by Pavel Ivanov on 14.05.2022.
//

#include "TransformManager.hpp"
#include "managers/SceneManager/SceneManager.hpp"

void TransformManager::transformVisible(size_t scene_id, const Point &move_params, const Point &scale_params, const Point &rotate_params)
{
    auto it =  SceneManagerCreator().getManager()->getScene()->begin();
    std::size_t _cur = 0;

    do
    {
        if ((*it)->isVisible())
        {
            _cur++;
        }

        it++;
    }
    while (_cur < scene_id + 1);

    (*(it - 1))->transform(move_params, scale_params, rotate_params);
}

void TransformManager::transformInvisible(size_t scene_id, const Point &move_params, const Point &scale_params, const Point &rotate_params)
{
    auto it = SceneManagerCreator().getManager()->getScene()->begin();
    std::size_t _cur = 0;

    do
    {
        if (!((*it)->isVisible()))
        {
            _cur++;
        }

        it++;
    }
    while (_cur < scene_id + 1);

    (*(it - 1))->transform(move_params, scale_params, rotate_params);
}

void TransformManagerCreator::_createManager()
{
    static auto manager = std::make_shared<TransformManager>();
    this->_manager = manager;
}

std::shared_ptr<TransformManager> TransformManagerCreator::getManager()
{
    if (this->_manager == nullptr)
    {
        this->_createManager();
    }

    return this->_manager;
}

