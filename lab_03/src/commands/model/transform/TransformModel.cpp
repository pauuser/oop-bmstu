//
// Created by Pavel Ivanov on 14.05.2022.
//

#include "TransformModel.hpp"
#include "managers/TransformManager/TransformManager.hpp"
#include "managers/SceneManager/SceneManager.hpp"

TransformModel::TransformModel(std::size_t id, const Point &move_params, const Point &scale_params, const Point &rotate_params):
                               _id(id), _move_params(move_params), _scale_params(scale_params), _rotate_params(rotate_params) {}

void TransformModel::execute()
{
    auto scene = SceneManagerCreator().getManager()->getScene();
    auto it = scene->begin();

    std::size_t _cur = 0;

    do
    {
        if ((*it)->isVisible())
        {
            _cur++;
        }

        it++;
    }
    while (_cur < _id + 1);

    TransformManagerCreator().getManager()->transform(*(it - 1), this->_move_params,
                                                      this->_scale_params, this->_rotate_params);
}