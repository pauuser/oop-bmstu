//
// Created by Pavel Ivanov on 29.05.2022.
//

#include "Controller.hpp"

#include <QDebug>

Controller::Controller(QWidget *parent) : QWidget(parent)
{
    this->_layout = std::make_unique<QVBoxLayout>();
    this->setLayout(this->_layout.get());

    for (size_t i = 0; i < FLOORS; i++)
    {
        auto new_button = std::make_shared<Button>();
        new_button->setFloor(FLOORS - i);
        new_button->setText(QString::number(FLOORS - i));

        this->_buttons.insert(this->_buttons.begin(), new_button);
        _layout->addWidget(dynamic_cast<QPushButton *>(new_button.get()));

        _floorsToVisit.push_back(false);

        // нажата кнопка => добавляем этаж в цели
        QObject::connect(new_button.get(), SIGNAL(pressSignal(bool,int)), this, SLOT(newTarget(bool,int)));
    }

    QObject::connect(this, SIGNAL(reachFloorSignal()), this, SLOT(reachFloor()));
}

void Controller::newTarget(bool got_new, int floor)
{
    //qDebug() << "HERE!!" << got_new << floor;
    this->_state = BUSY;
    if (got_new)
    {
        this->_floorsToVisit[floor - 1] = true;

        _identifyNewTarget(floor);
        _targetFloor = floor;
        _decideDirection();
        //qDebug() << "direction: " << _direction << "Cur floor" << _curFloor << "Target" << _targetFloor;
        if (_direction == STAY)
        {
            emit reachFloorSignal();
        }
        else
        {
            emit moveCabinSignal();
        }
    }
    else if (_identifyNewTarget(floor))
    {
        _targetFloor = floor;
        _decideDirection();

        //qDebug() << "direction: " << _direction << "Cur floor" << _curFloor << "Target" << _targetFloor;

        if (_direction != STAY)
        {
            //qDebug() << "HERE!!";
             _updateFloor();
            emit moveCabinSignal();
        }
        else
        {
            emit reachFloorSignal();
        }
     }
}

void Controller::_decideDirection()
{
    if (_targetFloor > _curFloor)
    {
        _direction = UP;
    }
    else if (_targetFloor < _curFloor)
    {
        _direction = DOWN;
    }
    else
    {
        _direction = STAY;
    }
}

bool Controller::_identifyNewTarget(int &new_target)
{
    bool rc = false;

    Direction dir;

    if (_direction != STAY)
    {
        dir = _direction;
    }
    else
    {
        dir = DOWN;
    }

    for (int i = _curFloor; !rc && i <= FLOORS && i > 0; i = i + dir)
    {
        if (_floorsToVisit[i - 1])
        {
            new_target = i;
            rc = true;
        }
    }

    if (!rc)
    {
        dir = ((dir == UP) ? DOWN : UP);

        for (int i = _curFloor; !rc && i <= FLOORS && i > 0; i = i + dir)
        {
            if (_floorsToVisit[i - 1])
            {
                new_target = i;
                rc = true;
            }
        }
    }

    return rc;
}

void Controller::reachFloor()
{
    //qDebug() << _floorsToVisit;
    // Если контроллер не занят, выходим [лифт не движется]
    if (_state != BUSY) return;

    qDebug() << "[!] Лифт приехал на этаж № " << _targetFloor;

    emit _buttons[_targetFloor - 1]->unpressSignal(); // кнопка разжимается
    _floorsToVisit[_targetFloor - 1] = false; // посещать его уже не надо

    // проверим, есть ли ещё цели
    if (_identifyNewTarget(_targetFloor))
    {
        emit stopCabinSignal();
    }
    else
    {
        // Целей нет
        _state = FREE; // Контроллер освободился
        emit stopCabinSignal();
    }
}

void Controller::_updateFloor()
{
    _curFloor += _direction;

     qDebug() << "... Лифт едет на этаж № " << _curFloor;
}
