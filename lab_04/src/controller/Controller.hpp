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
    void stopCabinSignal();
    void moveCabinSignal();
    void reachFloorSignal();

public slots:
    void newTarget(bool ,int = 1);  // FREE -> BUSY
    void reachFloor();                      // BUSY -> FREE

private:
    bool _identifyNewTarget(int &new_target);
    void _decideDirection();
    void _updateFloor();

private:
    int _curFloor = 1;
    int _targetFloor = 1;

    Direction _direction = STAY;

    controllerState _state = FREE;
    std::vector<bool> _floorsToVisit;

    std::vector<std::shared_ptr<Button>> _buttons;
    std::unique_ptr<QVBoxLayout> _layout;
};

#endif//LAB_04_CONTROLLER_HPP
