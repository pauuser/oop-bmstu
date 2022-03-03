#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <math.h>

#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->statusbar->showMessage("Лабораторная работа №1. Иванов Павел ИУ7-45Б.");

    QGraphicsScene *scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    scene->setSceneRect(-WINDOW_X / 2, -WINDOW_Y / 2, WINDOW_X / 2, WINDOW_Y / 2);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_upload_clicked(void)
{
    for (int i = -500; i < 500; i = i + 2)
        ui->graphicsView->scene()->addLine(0,0,500 * cos(i),500 * sin(i));
    std::cout << "YeaAHH!!!" << std::endl;
}


void MainWindow::on_pushButton_scale_clicked()
{

}

void MainWindow::on_pushButton_move_clicked()
{

}

void MainWindow::on_pushButton_rotate_clicked()
{

}

void MainWindow::on_pushButton_save_current_clicked()
{

}

void MainWindow::on_pushButton_return_default_clicked()
{

}
