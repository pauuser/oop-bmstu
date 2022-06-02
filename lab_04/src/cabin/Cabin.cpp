//
// Created by Pavel Ivanov on 30.05.2022.
//

#include "Cabin.hpp"
#include <QDebug>

Cabin::Cabin(QObject *parent) : QObject(parent)
{
    _state = FREE;

    QObject::connect(this, SIGNAL(openDoors()), &_doors, SLOT(startOpening()));

    QObject::connect(&_moveTimer, SIGNAL(timeout()), this, SLOT(free()));

    QObject::connect(&_doors, SIGNAL(doorClosed()), this, SLOT(free()));
}

void Cabin::stopCabin()
{
        _state = WAITS;

        _moveTimer.stop();
        emit openDoors(); // просьба открыть двери
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
    if (_state != FREE)
    {
        _state = FREE;
        emit cabinFinished(false);
    }
}



