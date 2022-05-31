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
        QObject::connect(new_button.get(), SIGNAL(pressSignal(size_t)), this, SLOT(newTarget(size_t)));
    }
}

void Controller::newTarget(size_t floor)
{
    this->_state = BUSY;
    this->_floorsToVisit[floor - 1] = true;

    _identifyNewTarget(floor);

    _targetFloor = floor;
    emit newTargetSignal(floor);
}

bool Controller::_identifyNewTarget(size_t &new_target)
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

    for (size_t i = _curFloor; !rc && i <= FLOORS && i > 0; i = i + dir)
    {
        if (_floorsToVisit[i - 1])
        {
            new_target = i;
            rc = true;
        }
    }

    return rc;
}

void Controller::reachFloor(size_t floor, Direction dir)
{
    // Если контроллер не занят, выходим [лифт не движется]
    if (_state != BUSY) return;

    _curFloor = floor;
    _direction = dir;

    // Текущий этаж не равен цели => не приехали
    if (_curFloor != _targetFloor) return;

    qDebug() << "[!] Лифт приехал на этаж № " << _targetFloor;

    emit _buttons[_targetFloor - 1]->unpressSignal(); // кнопка разжимается
    _floorsToVisit[_targetFloor - 1] = false; // посещать его уже не надо

    // проверим, есть ли ещё цели
    if (_identifyNewTarget(floor))
    {
        _targetFloor = floor;
        emit stopSignal(false, floor);
    }
    else
    {
        // Целей нет
        _state = FREE; // Контроллер освободился
        emit stopSignal(true);
    }
}
