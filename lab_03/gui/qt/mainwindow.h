//
// Created by Pavel Ivanov on 11.05.2022.
//

#ifndef LAB_03_MAINWINDOW_H
#define LAB_03_MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>

#include "src/facade/Facade.hpp"
#include "gui/drawer/BaseDrawer.hpp"
#include "gui/drawer/AbstractFactory/AbstractFactory.hpp"
#include "gui/qt/QtDrawer/QtDrawer.hpp"
#include "gui/qt/QtFactory/QtFactory.hpp"

#include <iostream>

QT_BEGIN_NAMESPACE
namespace Ui {
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

private slots:
    void on_pushButton_move_clicked();
    void on_pushButton_add_camera_clicked();
    void on_pushButton_spin_clicked();
    void on_pushButton_scale_clicked();
    void on_pushButton_load_model_clicked();
    void on_pushButton_move_3_clicked();
    void on_pushButton_scale_3_clicked();
    void on_pushButton_spin_3_clicked();
    void on_pushButton_del_model_cur_clicked();
    void on_pushButton_del_model_all_clicked();
    void on_pushButton_add_camera_2_clicked();
    void on_pushButton_del_camera_cur_clicked();
    void on_comboBox_cameras_currentIndexChanged(int index);

protected:
    void setupScene();
    void updateScene();

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private:
    Ui::MainWindow *ui;
    std::shared_ptr<Facade> _facade;
    std::shared_ptr<QGraphicsScene> _scene;
    std::shared_ptr<BaseDrawer> _drawer;

    size_t _getModelCount();
    size_t _getCameraCount();
};


#endif//LAB_03_MAINWINDOW_H
