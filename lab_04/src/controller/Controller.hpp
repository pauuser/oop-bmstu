//
// Created by Pavel Ivanov on 29.05.2022.
//

#ifndef LAB_04_CONTROLLER_HPP
#define LAB_04_CONTROLLER_HPP

#include <QVBoxLayout>
#include <QWidget>
#include <QDebug>
#include <memory>
#include <vector>

#include "src/defines.hpp"
#include "src/button/Button.hpp"

class Controller : public QWidget
{
    Q_OBJECT

    using controllerState = enum {
        FREE,
        BUSY
    };

public:
    explicit Controller(QWidget *parent = nullptr);
    ~Controller() override = default;

signals:
    void newTargetSignal(size_t floor);
    void stopSignal(bool, size_t floor = 1);

public slots:
    void newTarget(size_t floor);
    void reachFloor(size_t floor, Direction dir);

private:
    bool _identifyNewTarget(size_t &new_target);

private:
    size_t _curFloor;
    size_t _targetFloor;

    Direction _direction;

    controllerState _state;
    std::vector<bool> _floorsToVisit;

    std::vector<std::shared_ptr<Button>> _buttons;
    std::unique_ptr<QVBoxLayout> _layout;
};

#endif//LAB_04_CONTROLLER_HPP
