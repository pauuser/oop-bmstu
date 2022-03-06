#include "mainwindow.h"
#include "ui_mainwindow.h"


#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->statusbar->showMessage("Лабораторная работа №1. Иванов Павел ИУ7-45Б.");

    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    scene->setSceneRect(-WINDOW_X / 2, -WINDOW_Y / 2, WINDOW_X / 2, WINDOW_Y / 2);

    init_model(model);
}

MainWindow::~MainWindow()
{
    free_model(model);
    delete ui;
}

void MainWindow::on_pushButton_upload_clicked()
{
    QString text = ui->lineEdit_filename->text();

    std::string str = text.toStdString();
    const char *filename = str.c_str();

    int rc = input_model_from_file(model, filename);

    if (rc == OK)
        draw_model(scene, model);

    print_error(rc);
}


void MainWindow::on_pushButton_scale_clicked()
{
    double kx = ui->doubleSpinBox_scale_x->value();
    double ky = ui->doubleSpinBox_scale_y->value();
    double kz = ui->doubleSpinBox_scale_z->value();

    int rc = scale_model(model, kx, ky, kz);

    if (rc == OK)
        draw_model(scene, model);

    print_error(rc);
}

void MainWindow::on_pushButton_move_clicked()
{
    double dx = ui->doubleSpinBox_move_x->value();
    double dy = ui->doubleSpinBox_move_y->value();
    double dz = ui->doubleSpinBox_move_z->value();

    int rc = move_model(model, dx, dy, dz);

    if (rc == OK)
        draw_model(scene, model);

    print_error(rc);
}

void MainWindow::on_pushButton_rotate_clicked()
{
    double ax = ui->doubleSpinBox_rotate_x->value();
    double ay = ui->doubleSpinBox_rotate_y->value();
    double az = ui->doubleSpinBox_rotate_z->value();

    int rc = rotate_model(model, ax, ay, az);

    if (rc == OK)
        draw_model(scene, model);

    print_error(rc);
}

void MainWindow::on_pushButton_save_current_clicked()
{
    upload_model_to_file("out.txt", model);
}

void MainWindow::on_pushButton_return_default_clicked()
{
    init_matrix(model.transform_matrix);
    draw_model(scene, model);
}
