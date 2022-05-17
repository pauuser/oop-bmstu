//
// Created by Pavel Ivanov on 14.05.2022.
//

#include "ScaleModel.hpp"
#include "managers/SceneManager/SceneManager.hpp"

ScaleModel::ScaleModel(std::size_t id, double kx, double ky, double kz): _id(id), _kx(kx), _ky(ky), _kz(kz) {}

void ScaleModel::execute()
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

    Point move{ 0, 0, 0 };
    Point scale{ _kx, _ky, _kz };
    Point rotate{ 0, 0, 0 };

    (*(it - 1))->transform(move, scale, rotate);
}

