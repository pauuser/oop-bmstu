//
// Created by Pavel Ivanov on 30.05.2022.
//

#ifndef LAB_04_CABIN_HPP
#define LAB_04_CABIN_HPP

#include <QObject>
#include <QTimer>

#include "src/defines.hpp"
#include "src/doors/Doors.hpp"

class Cabin : public QObject
{
    Q_OBJECT

    using cabinState = enum {
        WAITING,
        MOVING,
        FREE
    };

public:
    explicit Cabin(QObject *parent = nullptr);
    ~Cabin() override = default;

signals:
    void openDoors();
    void stopped(bool = true, size_t = 1);
    void reachFloor(size_t floor, Direction dir);
    void moved();

public slots:
    void stopCabin(bool last, size_t floor = 1);
    void moveCabin();
    void updateTarget(size_t floor);

private:
    size_t _curFloor;
    size_t _targetFloor;

    Direction _dir;
    cabinState _state;

    Doors _doors;

    QTimer _moveTimer;
};


#endif//LAB_04_CABIN_HPP
