//
// Created by Pavel Ivanov on 30.05.2022.
//

#include "Cabin.hpp"
#include <QDebug>

Cabin::Cabin(QObject *parent) : QObject(parent)
{
    _state = FREE;
    _curFloor = 1;
    _targetFloor = 1;
    _dir = STAY;

    QObject::connect(this, SIGNAL(openDoors()), &_doors, SLOT(startOpening()));

    QObject::connect(&_doors, SIGNAL(doorClosed()), this, SLOT(moveCabin()));

    QObject::connect(this, SIGNAL(move()), &_doors, SLOT(readyToMove()));

    QObject::connect(&_moveTimer, SIGNAL(timeout()), this, SLOT(moveCabin()));
}

void Cabin::stopCabin(bool last, size_t floor)
{
    if (last)
    {
        _state = FREE; // лифт освободился (обслужен последний этаж)
    }
    else
    {
        _state = WAITING; // ждём действий со стороны двери
        _targetFloor = floor;
    }

    _moveTimer.stop();
    emit openDoors(); // просьба открыть двери
}

void Cabin::moveCabin()
{
    if (_state == MOVING || _state == WAITING)
    {
        _state = MOVING;
        _moveTimer.start(MOVE_TIME);

        qDebug() << "Лифт в пути на этаже №" << _curFloor;
        emit reachFloor(_curFloor, _dir);

        if (_curFloor != _targetFloor)
        {
            if (_targetFloor < _curFloor)
            {
                _dir = DOWN;
                _curFloor -= 1;
            }
            else
            {
                _dir = UP;
                _curFloor += 1;
            }
        }
    }
}

void Cabin::updateTarget(size_t floor)
{
    if (_state == FREE)
    {
        _state = WAITING;
        _targetFloor = floor;

        if (_curFloor == _targetFloor)
        {
            emit reachFloor(_curFloor, _dir);
        }
        else if (_curFloor < _targetFloor)
        {
            _dir = UP;
            emit move();
        }
        else
        {
            _dir = DOWN;
            emit move();
        }
    }
}

