//
// Created by Pavel Ivanov on 30.05.2022.
//

#include "Lift.hpp"

Lift::Lift(QObject *parent) : QObject(parent)
{
    _controller.setStyleSheet("background-color:lightblue");

    QObject::connect(&_cabin, SIGNAL(reachFloor(size_t,Direction)), &_controller, SLOT(reachFloor(size_t,Direction)));
    QObject::connect(&_controller, SIGNAL(newTargetSignal(size_t)), &_cabin, SLOT(updateTarget(size_t)));
    QObject::connect(&_controller, SIGNAL(stopSignal(bool,size_t)), &_cabin, SLOT(stopCabin(bool,size_t)));
}

QWidget *Lift::widget()
{
    return &_controller;
}
