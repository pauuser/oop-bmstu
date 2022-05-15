//
// Created by Pavel Ivanov on 11.05.2022.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow.h" resolved

#include "mainwindow.h"
#include "./ui/ui_mainwindow.h"


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

void MainWindow::on_pushButton_load_model_clicked()
{
    std::cout << "Inside!\n";

    Point a1(0, 50, 0);
    Point a2(50, 0, 0);
    Point a3(0, 0, 0);
    Point a4(50, 50, 0);
    Point a5(0, 50, 50);
    Point a6(50, 0, 50);
    Point a7(0, 0, 50);
    Point a8(50, 50, 50);

    Edge e1(2, 1);
    Edge e2(2, 0);
    Edge e3(0, 3);
    Edge e4(1, 3);
    Edge e5(6, 5);
    Edge e6(6, 4);
    Edge e7(4, 7);
    Edge e8(5, 7);
    Edge e9(0, 4);
    Edge e10(1, 5);
    Edge e11(2, 6);
    Edge e12(3, 7);

    std::vector points = std::vector{a1, a2, a3, a4, a5, a6, a7, a8};
    std::vector edges = std::vector{e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12};

    auto imp = std::make_shared<FrameModelImplementation>(points, edges, Point{0, 0, 0});
    auto model = std::make_shared<FrameModel>(imp);

    auto cmd = std::make_shared<AddModel>(model);
    this->_facade->execute(cmd);

    // TODO add update
    updateScene();
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
    std::cout << "Inside add camera!";
    auto cmd = std::make_shared<AddCamera>(-200, 0, 0);
    this->_facade->execute(cmd);
}

#include "commands/model/rotate/RotateModel.hpp"

void MainWindow::on_pushButton_spin_clicked()
{
    double ax = ui->doubleSpinBox_spin_x->value();
    double ay = ui->doubleSpinBox_spin_y->value();
    double az = ui->doubleSpinBox_spin_z->value();

    auto rotcmd = std::make_shared<RotateModel>(1, ax, ay, az);
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

    auto sclcmd = std::make_shared<ScaleModel>(1, kx, ky, kz);
    this->_facade->execute(sclcmd);
    updateScene();
}

#include "commands/model/move/MoveModel.hpp"

void MainWindow::on_pushButton_move_clicked()
{
    double dx = ui->doubleSpinBox_move_x->value();
    double dy = ui->doubleSpinBox_move_y->value();
    double dz = ui->doubleSpinBox_move_z->value();

    auto movcmd = std::make_shared<MoveModel>(1, dx, dy, dz);
    this->_facade->execute(movcmd);
    updateScene();
}




