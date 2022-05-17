//
// Created by Pavel Ivanov on 11.05.2022.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow.h" resolved

#include <QFileDialog>
#include <QMessageBox>

#include <string>
#include <vector>

#include "../src/configuration/Solution/ConfigurationSolution.hpp"
#include "../src/configuration/TextConfiguration/TextConfiguration.hpp"
#include "./ui/ui_mainwindow.h"
#include "commands/camera/add/AddCamera.hpp"
#include "commands/camera/load/LoadCamera.hpp"
#include "commands/camera/move/MoveCamera.hpp"
#include "commands/camera/remove/RemoveCamera.hpp"
#include "commands/camera/set/SetCamera.hpp"
#include "commands/model/add/AddModel.hpp"
#include "commands/model/load/LoadModel.hpp"
#include "commands/model/move/MoveModel.hpp"
#include "commands/model/remove/RemoveModel.hpp"
#include "commands/model/rotate/RotateModel.hpp"
#include "commands/model/scale/ScaleModel.hpp"
#include "commands/scene/draw/DrawScene.hpp"
#include "mainwindow.h"
#include "objects/Model/FrameModel/FrameModel.hpp"
#include "objects/Model/FrameModelImplementation/FrameModelImplementation.hpp"
#include "commands/model/count/CountModel.hpp"
#include "commands/camera/count/CountCamera.hpp"
#include "exceptions/ui/UiException.hpp"


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    setupScene();

    this->_facade = std::make_unique<Facade>();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::setupScene() {
    this->_scene = std::make_shared<QGraphicsScene>(this);
    ui->graphicsView->setScene(this->_scene.get());
    ui->graphicsView->setAlignment(Qt::AlignTop | Qt::AlignLeft);

    this->_scene->setSceneRect(-(ui->graphicsView->width()) / 2, -(ui->graphicsView->height()) / 2,
                               ui->graphicsView->width() / 2, ui->graphicsView->height() / 2);

    std::unique_ptr<AbstractFactory> factory = std::make_unique<QtFactory>(this->_scene);
    this->_drawer = factory->createDrawer();
}


void MainWindow::on_pushButton_load_model_clicked() {
    if (this->_getCameraCount() < 1)
    {
        QMessageBox::critical(nullptr, "Error!", "Add a camera first!");
        return;
    }

    std::string config = "C:\\Users\\Pavel Ivanov\\labs\\GitHub\\oop-bmstu\\lab_03\\build\\config.txt";
    auto _Qfile = QFileDialog::getOpenFileName();
    auto file = _Qfile.toStdString();

    auto load_cmd = std::make_shared<LoadModel>(file, config);

    _facade->execute(load_cmd);

    ui->comboBox_models->addItem(QFileInfo(_Qfile.toUtf8().data()).fileName());
    ui->comboBox_models->setCurrentIndex(ui->comboBox_models->count() - 1);
    updateScene();
}


void MainWindow::on_pushButton_del_model_cur_clicked() {
    if (_getModelCount() < 1)
    {
        QMessageBox::critical(nullptr, "Error!", "No models yet!");
        return;
    }

    int id = ui->comboBox_models->currentIndex();

    auto remove_cmd = std::make_shared<RemoveModel>(id);
    _facade->execute(remove_cmd);

    updateScene();
    ui->comboBox_models->removeItem(ui->comboBox_models->currentIndex());
    ui->comboBox_models->setCurrentIndex(ui->comboBox_models->count() - 1);
}

void MainWindow::on_pushButton_del_model_all_clicked() {
    if (_getModelCount() < 1)
    {
        QMessageBox::critical(nullptr, "Error!", "No models yet!");
        return;
    }

    int max_ind = ui->comboBox_models->count() - 1;

    for (int i = 0; i <= max_ind; i++) {
        auto remove_cmd = std::make_shared<RemoveModel>(0);
        _facade->execute(remove_cmd);
        ui->comboBox_models->removeItem(ui->comboBox_models->currentIndex());
    }

    updateScene();
    ui->comboBox_models->setCurrentIndex(ui->comboBox_models->count() - 1);
}


void MainWindow::updateScene() {
    auto cmd = std::make_shared<DrawScene>(this->_drawer);
    this->_facade->execute(cmd);
}


void MainWindow::on_pushButton_add_camera_clicked() {
    double x = ui->doubleSpinBox->value();
    double y = ui->doubleSpinBox_2->value();
    double z = ui->doubleSpinBox_3->value();

    double ax = ui->doubleSpinBox_5->value();
    double ay = ui->doubleSpinBox_6->value();
    double az = ui->doubleSpinBox_4->value();

    auto cmd = std::make_shared<AddCamera>(x, y, z, ax, ay, az);
    this->_facade->execute(cmd);

    ui->comboBox_cameras->addItem("CustomCamera");
    ui->comboBox_cameras->setCurrentIndex(ui->comboBox_cameras->count() - 1);
}


void MainWindow::on_pushButton_add_camera_2_clicked() {
    std::string config = "C:\\Users\\Pavel Ivanov\\labs\\GitHub\\oop-bmstu\\lab_03\\build\\config.txt";
    auto _Qfile = QFileDialog::getOpenFileName();
    auto file = _Qfile.toStdString();

    auto load_cmd = std::make_shared<LoadCamera>(file, config);

    _facade->execute(load_cmd);

    ui->comboBox_cameras->addItem(QFileInfo(_Qfile.toUtf8().data()).fileName());
    ui->comboBox_cameras->setCurrentIndex(ui->comboBox_cameras->count() - 1);
    updateScene();
}


void MainWindow::on_pushButton_del_camera_cur_clicked() {
    if (this->_getCameraCount() < 1)
    {
        QMessageBox::critical(nullptr, "Error!", "No cameras!");
        return;
    }

    if (this->_getModelCount() > 1 && this->_getCameraCount() == 1)
    {
        QMessageBox::critical(nullptr, "Error!", "Cannot delete the last camera before all models are deleted!");
        return;
    }

    int id = ui->comboBox_cameras->currentIndex();

    auto remove_cmd = std::make_shared<RemoveCamera>(id);
    _facade->execute(remove_cmd);

    updateScene();
    ui->comboBox_cameras->removeItem(ui->comboBox_cameras->currentIndex());
    ui->comboBox_cameras->setCurrentIndex(ui->comboBox_cameras->count() - 1);
}


void MainWindow::on_pushButton_spin_clicked() {
    if (this->_getCameraCount() < 1)
    {
        QMessageBox::critical(nullptr, "Error!", "No cameras!");
        return;
    }

    if (this->_getModelCount() < 1)
    {
        QMessageBox::critical(nullptr, "Error!", "No models!");
        return;
    }

    double ax = ui->doubleSpinBox_spin_x->value();
    double ay = ui->doubleSpinBox_spin_y->value();
    double az = ui->doubleSpinBox_spin_z->value();

    int id = ui->comboBox_models->currentIndex();

    auto rotcmd = std::make_shared<RotateModel>(id, ax, ay, az);
    this->_facade->execute(rotcmd);
    updateScene();
}


void MainWindow::on_pushButton_scale_clicked() {
    if (this->_getCameraCount() < 1)
    {
        QMessageBox::critical(nullptr, "Error!", "No cameras!");
        return;
    }

    if (this->_getModelCount() < 1)
    {
        QMessageBox::critical(nullptr, "Error!", "No models!");
        return;
    }

    double kx = ui->doubleSpinBox_scale_x->value();
    double ky = ui->doubleSpinBox_scale_y->value();
    double kz = ui->doubleSpinBox_scale_z->value();

    int id = ui->comboBox_models->currentIndex();

    auto sclcmd = std::make_shared<ScaleModel>(id, kx, ky, kz);
    this->_facade->execute(sclcmd);
    updateScene();
}

void MainWindow::on_pushButton_move_clicked() {
    if (this->_getCameraCount() < 1)
    {
        QMessageBox::critical(nullptr, "Error!", "No cameras!");
        return;
    }

    if (this->_getModelCount() < 1)
    {
        QMessageBox::critical(nullptr, "Error!", "No models!");
        return;
    }

    double dx = ui->doubleSpinBox_move_x->value();
    double dy = ui->doubleSpinBox_move_y->value();
    double dz = ui->doubleSpinBox_move_z->value();

    int id = ui->comboBox_models->currentIndex();

    auto movcmd = std::make_shared<MoveModel>(id, dx, dy, dz);
    this->_facade->execute(movcmd);
    updateScene();
}

void MainWindow::on_pushButton_move_3_clicked() {
    if (this->_getCameraCount() < 1)
    {
        QMessageBox::critical(nullptr, "Error!", "No cameras!");
        return;
    }

    if (this->_getModelCount() < 1)
    {
        QMessageBox::critical(nullptr, "Error!", "No models!");
        return;
    }

    double dx = ui->doubleSpinBox_move_x_3->value();
    double dy = ui->doubleSpinBox_move_y_3->value();
    double dz = ui->doubleSpinBox_move_z_3->value();

    Point move_params{dx, dy, dz};
    Point scale_params{1, 1, 1};
    Point rotate_params{0, 0, 0};

    int id = ui->comboBox_cameras->currentIndex();

    auto set_cmd = std::make_shared<SetCamera>(id);
    this->_facade->execute(set_cmd);

    auto cmd = std::make_shared<MoveCamera>(id, move_params, scale_params, rotate_params);
    this->_facade->execute(cmd);

    updateScene();
}

void MainWindow::on_pushButton_scale_3_clicked() {
    if (this->_getCameraCount() < 1)
    {
        QMessageBox::critical(nullptr, "Error!", "No cameras!");
        return;
    }

    if (this->_getModelCount() < 1)
    {
        QMessageBox::critical(nullptr, "Error!", "No models!");
        return;
    }

    double kx = ui->doubleSpinBox_scale_x_3->value();
    double ky = ui->doubleSpinBox_scale_y_3->value();
    double kz = ui->doubleSpinBox_scale_z_3->value();

    Point move_params{0, 0, 0};
    Point scale_params{kx, ky, kz};
    Point rotate_params{0, 0, 0};

    int id = ui->comboBox_cameras->currentIndex();

    auto set_cmd = std::make_shared<SetCamera>(id);
    this->_facade->execute(set_cmd);

    auto cmd = std::make_shared<MoveCamera>(id, move_params, scale_params, rotate_params);
    this->_facade->execute(cmd);

    updateScene();
}

void MainWindow::on_pushButton_spin_3_clicked() {
    if (this->_getCameraCount() < 1)
    {
        QMessageBox::critical(nullptr, "Error!", "No cameras!");
        return;
    }

    if (this->_getModelCount() < 1)
    {
        QMessageBox::critical(nullptr, "Error!", "No models!");
        return;
    }

    double ax = ui->doubleSpinBox_spin_x_3->value();
    double ay = ui->doubleSpinBox_spin_y_3->value();
    double az = ui->doubleSpinBox_spin_z_3->value();

    Point move_params{0, 0, 0};
    Point scale_params{1, 1, 1};
    Point rotate_params{ax, ay, az};

    int id = ui->comboBox_cameras->currentIndex();

    auto set_cmd = std::make_shared<SetCamera>(id);
    this->_facade->execute(set_cmd);

    auto cmd = std::make_shared<MoveCamera>(id, move_params, scale_params, rotate_params);
    this->_facade->execute(cmd);

    updateScene();
}

void MainWindow::on_comboBox_cameras_currentIndexChanged(int index) {
    auto set_cmd = std::make_shared<SetCamera>(index);
    this->_facade->execute(set_cmd);

    updateScene();
}

size_t MainWindow::_getCameraCount() {
    std::shared_ptr<size_t> res = std::make_shared<size_t>();

    auto cmd = std::make_shared<CountCamera>(res);
    this->_facade->execute(cmd);

    return *res;
}

size_t MainWindow::_getModelCount() {
    std::shared_ptr<size_t> res = std::make_shared<size_t>();

    auto cmd = std::make_shared<CountModel>(res);
    this->_facade->execute(cmd);

    return *res;
}

