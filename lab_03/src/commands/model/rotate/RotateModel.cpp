//
// Created by Pavel Ivanov on 14.05.2022.
//

#include "RotateModel.hpp"
#include "managers/SceneManager/SceneManager.hpp"

RotateModel::RotateModel(std::size_t id, double ax, double ay, double az): _id(id), _ax(ax), _ay(ay), _az(az) {}

void RotateModel::execute()
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
    while (_cur < _id);

    Point move{ 0, 0, 0 };
    Point scale{ 1, 1, 1 };
    Point rotate{ _ax, _ay, _az };

    (*(it--))->transform(move, scale, rotate);
}
