#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <math.h>
#include "model.h"
#include "file_io.h"
#include "draw.h"

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

    FILE *f = fopen("test.txt", "r");
    std::cout << f << std::endl;

    model_t model;
    init_model(model);

    int rc = read_model(model, f);
    fprintf(stdout, "AAAAAAA RC = %d\n", rc);

    if (rc == OK)
    {
        fprintf(stdout, "%d\n", model.n);
        for (int i = 0; i < model.n; i++)
            fprintf(stdout, "%f %f %f\n", model.points[i].row[0], model.points[i].row[1], model.points[i].row[2]);
        fprintf(stdout, "%d\n", model.m);
        for (int i = 0; i < model.m; i++)
            fprintf(stdout, "%f %f %f -> %f %f %f\n", model.lines[i].point1.row[0], model.lines[i].point1.row[1], model.lines[i].point1.row[2],
                                             model.lines[i].point2.row[0], model.lines[i].point2.row[1], model.lines[i].point2.row[2]);
    }

    fclose(f);

    draw_model(scene, model);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_upload_clicked(void)
{
    for (int i = -500; i < 500; i = i + 2)
        ui->graphicsView->scene()->addLine(0,0,500 * cos(i),500 * sin(i));
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
