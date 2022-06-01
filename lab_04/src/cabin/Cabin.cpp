//
// Created by Pavel Ivanov on 30.05.2022.
//

#include "Cabin.hpp"
#include <QDebug>

Cabin::Cabin(QObject *parent) : QObject(parent)
{
    _state = FREE;

    // Сигнал открывания дверей => просим двери открыть двери
    QObject::connect(this, SIGNAL(openDoors()), &_doors, SLOT(startOpening()));

    // Кабина закончила движение => она свободна, выдаём сигнал cabinFinished()
    QObject::connect(&_moveTimer, SIGNAL(timeout()), this, SLOT(free()));

    // Двери закрылись => кабина освободилась, выдаём сигнал cabinFinished()
    QObject::connect(&_doors, SIGNAL(doorClosed()), this, SLOT(free()));
}

void Cabin::stopCabin()
{
    if (_state == MOVING)
    {
        _state = WAITS;

        _moveTimer.stop();
        emit openDoors(); // просьба открыть двери
    }
}

void Cabin::moveCabin()
{
    if (_state == FREE)
    {
        _state = MOVING;
        _moveTimer.start(MOVE_TIME);
    }
}

void Cabin::free()
{
    if (_state == WAITS)
    {
        _state = FREE;
        emit cabinFinished(false);
    }
}



