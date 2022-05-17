//
// Created by Pavel Ivanov on 11.05.2022.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow.h" resolved

#include <string>
#include <QFileDialog>

#include "mainwindow.h"
#include "./ui/ui_mainwindow.h"
#include "../src/configuration/Solution/ConfigurationSolution.hpp"
#include "../src/configuration/TextConfiguration/TextConfiguration.hpp"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setupScene();

    this->_facade = std::make_unique<Facade>();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setupScene()
{
    this->_scene = std::make_shared<QGraphicsScene>(this);
    ui->graphicsView->setScene(this->_scene.get());
    ui->graphicsView->setAlignment(Qt::AlignTop | Qt::AlignLeft);

    this->_scene->setSceneRect(-(ui->graphicsView->width()) / 2, -(ui->graphicsView->height()) / 2,
                                ui->graphicsView->width() / 2, ui->graphicsView->height() / 2);

    std::unique_ptr<AbstractFactory> factory = std::make_unique<QtFactory>(this->_scene);
    this->_drawer = factory->createDrawer();

    // TODO: возможно перенести фабрику в конфиг
}

#include "objects/Model/FrameModelImplementation/FrameModelImplementation.hpp"
#include "objects/Model/FrameModel/FrameModel.hpp"
#include <vector>
#include "commands/model/add/AddModel.hpp"
#include "commands/model/load/LoadModel.hpp"

void MainWindow::on_pushButton_load_model_clicked()
{
    std::cout << "Inside!\n";

    std::string config = "C:\\Users\\Pavel Ivanov\\labs\\GitHub\\oop-bmstu\\lab_03\\build\\config.txt";
    auto _Qfile = QFileDialog::getOpenFileName();
    auto file = _Qfile.toStdString();

    auto load_cmd = std::make_shared<LoadModel>(file, config);

    _facade->execute(load_cmd);

    ui->comboBox_models->addItem(QFileInfo(_Qfile.toUtf8().data()).fileName());
    ui->comboBox_models->setCurrentIndex(ui->comboBox_models->count() - 1);
    updateScene();
}

#include "commands/model/remove/RemoveModel.hpp"

void MainWindow::on_pushButton_del_model_cur_clicked()
{
    // TODO: add check if 1 model is added

    int id = ui->comboBox_models->currentIndex();

    auto remove_cmd = std::make_shared<RemoveModel>(id);
    _facade->execute(remove_cmd);

    updateScene();
    ui->comboBox_models->removeItem(ui->comboBox_models->currentIndex());
    ui->comboBox_models->setCurrentIndex(ui->comboBox_models->count() - 1);
}

void MainWindow::on_pushButton_del_model_all_clicked()
{
    // TODO: add check si les models ne existent pas

    int max_ind = ui->comboBox_models->count() - 1;

    for (int i = 0; i <= max_ind; i++)
    {
        auto remove_cmd = std::make_shared<RemoveModel>(0);
        _facade->execute(remove_cmd);
        ui->comboBox_models->removeItem(ui->comboBox_models->currentIndex());
    }

    updateScene();
    ui->comboBox_models->setCurrentIndex(ui->comboBox_models->count() - 1);
}

#include "commands/scene/draw/DrawScene.hpp"

void MainWindow::updateScene()
{
    auto cmd = std::make_shared<DrawScene>(this->_drawer);
    this->_facade->execute(cmd);
}

#include "commands/camera/add/AddCamera.hpp"

void MainWindow::on_pushButton_add_camera_clicked()
{
    /*
    double x = ui->doubleSpinBox->value();
    double y = ui->doubleSpinBox_2->value();
    double z = ui->doubleSpinBox_3->value();

    double ax = ui->doubleSpinBox_5->value();
    double ay = ui->doubleSpinBox_6->value();
    double az = ui->doubleSpinBox_4->value();
    */

    std::cout << "Inside add camera!";
    auto cmd = std::make_shared<AddCamera>(0, 0, 0, 0, 0, 0);
    this->_facade->execute(cmd);
}

#include "commands/model/rotate/RotateModel.hpp"

void MainWindow::on_pushButton_spin_clicked()
{
    double ax = ui->doubleSpinBox_spin_x->value();
    double ay = ui->doubleSpinBox_spin_y->value();
    double az = ui->doubleSpinBox_spin_z->value();

    int id = ui->comboBox_models->currentIndex();

    auto rotcmd = std::make_shared<RotateModel>(id, ax, ay, az);
    this->_facade->execute(rotcmd);
    updateScene();
}

#include "commands/model/scale/ScaleModel.hpp"

void MainWindow::on_pushButton_scale_clicked()
{
    // TODO: add ID choose to all transformation commands
    double kx = ui->doubleSpinBox_scale_x->value();
    double ky = ui->doubleSpinBox_scale_y->value();
    double kz = ui->doubleSpinBox_scale_z->value();

    int id = ui->comboBox_models->currentIndex();

    auto sclcmd = std::make_shared<ScaleModel>(id, kx, ky, kz);
    this->_facade->execute(sclcmd);
    updateScene();
}

#include "commands/model/move/MoveModel.hpp"

void MainWindow::on_pushButton_move_clicked()
{
    // TODO: вставить проверку если модели вообще есть

    double dx = ui->doubleSpinBox_move_x->value();
    double dy = ui->doubleSpinBox_move_y->value();
    double dz = ui->doubleSpinBox_move_z->value();

    int id = ui->comboBox_models->currentIndex();

    auto movcmd = std::make_shared<MoveModel>(id, dx, dy, dz); // TODO: fix ID here
    this->_facade->execute(movcmd);
    updateScene();
}

#include "commands/camera/move/MoveCamera.hpp"

void MainWindow::on_pushButton_move_3_clicked()
{
    double dx = ui->doubleSpinBox_move_x_3->value();
    double dy = ui->doubleSpinBox_move_y_3->value();
    double dz = ui->doubleSpinBox_move_z_3->value();

    Point move_params{ dx, dy, dz };
    Point scale_params{ 1, 1, 1 };
    Point rotate_params{ 0, 0, 0 };

    auto cmd = std::make_shared<MoveCamera>(0, move_params, scale_params, rotate_params);
    this->_facade->execute(cmd);
    updateScene();
}

void MainWindow::on_pushButton_scale_3_clicked()
{
    double kx = ui->doubleSpinBox_scale_x_3->value();
    double ky = ui->doubleSpinBox_scale_y_3->value();
    double kz = ui->doubleSpinBox_scale_z_3->value();

    Point move_params{ 0, 0, 0 };
    Point scale_params{ kx, ky, kz };
    Point rotate_params{ 0, 0, 0 };

    auto cmd = std::make_shared<MoveCamera>(0, move_params, scale_params, rotate_params);
    this->_facade->execute(cmd);
    updateScene();
}

void MainWindow::on_pushButton_spin_3_clicked()
{
    double ax = ui->doubleSpinBox_spin_x_3->value();
    double ay = ui->doubleSpinBox_spin_y_3->value();
    double az = ui->doubleSpinBox_spin_z_3->value();

    Point move_params{ 0, 0, 0 };
    Point scale_params{ 1, 1, 1 };
    Point rotate_params{ ax, ay, az };

    auto cmd = std::make_shared<MoveCamera>(0, move_params, scale_params, rotate_params);
    this->_facade->execute(cmd);
    updateScene();
}




