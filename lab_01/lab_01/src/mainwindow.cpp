#include "../inc/mainwindow.h"
#include "../ui_mainwindow.h"
#include <stdio.h>

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
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_upload_clicked()
{
    QString text = ui->lineEdit_filename->text();

    std::string str = text.toStdString();
    const char *filename = str.c_str();

    request_t req = create_request(UPLOAD, 0, 0, 0, filename);
    int rc = controller(scene, req);

    print_error(rc);

    req.event = DRAW;
    controller(scene, req);
}


void MainWindow::on_pushButton_scale_clicked()
{
    double kx = ui->doubleSpinBox_scale_x->value();
    double ky = ui->doubleSpinBox_scale_y->value();
    double kz = ui->doubleSpinBox_scale_z->value();

    request_t req = create_request(SCALE, kx, ky, kz);

    int rc = controller(scene, req);
    print_error(rc);

    req = create_request(DRAW);
    controller(scene, req);
}

void MainWindow::on_pushButton_move_clicked()
{
    double dx = ui->doubleSpinBox_move_x->value();
    double dy = ui->doubleSpinBox_move_y->value();
    double dz = ui->doubleSpinBox_move_z->value();

    request_t req = create_request(MOVE, dx, dy, dz);

    int rc = controller(scene, req);
    print_error(rc);

    req = create_request(DRAW);
    controller(scene, req);
}

void MainWindow::on_pushButton_rotate_clicked()
{
    double ax = ui->doubleSpinBox_rotate_x->value();
    double ay = ui->doubleSpinBox_rotate_y->value();
    double az = ui->doubleSpinBox_rotate_z->value();

    request_t req = create_request(ROTATE, ax, ay, az);

    int rc = controller(scene, req);
    print_error(rc);

    req = create_request(DRAW);
    controller(scene, req);
}

void MainWindow::on_pushButton_save_current_clicked()
{
    request_t req = create_request(SAVE, 0, 0, 0, "./out/out.txt");

    int rc = controller(scene, req);
    print_error(rc);
}

