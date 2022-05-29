//
// Created by Pavel Ivanov on 29.05.2022.
//

#include "Button.hpp"
#include <QDebug>

Button::Button(QWidget *parent) : QPushButton(parent)
{
    QObject::connect(this, SIGNAL(clicked()), this, SLOT(press()));
    QObject::connect(this, SIGNAL(unpressSignal()), this, SLOT(unpress())); // Выключается когда лифт приедет и издаст сигнал

    _state = INACTIVE;
    _curButtonFloor = 1;
}

void Button::setFloor(size_t floor)
{
    _curButtonFloor = floor;
}

void Button::press()
{
    // Если кнопка уже нажата, выходим
    if (this->_state == ACTIVE) return;

    // Визуальное изменение кнопки
    this->setStyleSheet("background-color:red");
    this->update();

    qDebug() << "[!] Вызов на этаж №" << this->_curButtonFloor;

    // Изменение состояния
    this->_curButtonFloor = ACTIVE;
    this->setDisabled(true);

    // Сигнал всем, что нажата данная кнопка
    emit pressSignal(this->_curButtonFloor);
}

void Button::unpress()
{
    // Если кнопка уже разжата, выходим
    if (this->_state == INACTIVE) return;

    // Визуальное изменение кнопки
    this->setStyleSheet("background-color:blue");
    this->update();

    // Изменение состояния
    this->_curButtonFloor = INACTIVE;
    this->setDisabled(false);
}
