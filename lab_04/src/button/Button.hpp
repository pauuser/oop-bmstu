//
// Created by Pavel Ivanov on 29.05.2022.
//

#ifndef LAB_04_BUTTON_HPP
#define LAB_04_BUTTON_HPP

#include <QPushButton>
#include <memory>

class Button : public QPushButton
{
    Q_OBJECT;

    using buttonState = enum {
        ACTIVE,
        INACTIVE
    };

public:
    Button(QWidget *parent = nullptr);
    ~Button() = default;

    void setFloor(size_t floor);

signals:
    void pressSignal(size_t floor);
    void unpressSignal();

public slots:
    void press();
    void unpress();

private:
    buttonState _state;
    size_t _curButtonFloor;
};

#endif// LAB_04_BUTTON_HPP
