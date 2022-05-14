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

    this->_scene->setSceneRect(0, 0, ui->graphicsView->width(), ui->graphicsView->height());

    std::unique_ptr<AbstractFactory> factory = std::make_unique<QtFactory>(this->_scene);
    this->_drawer = factory->createDrawer();
}





