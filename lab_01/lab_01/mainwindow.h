#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "model.h"
#include "file_io.h"
#include "draw.h"
#include "errors.h"

#define WINDOW_X 701
#define WINDOW_Y 671

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_upload_clicked();
    void on_pushButton_scale_clicked();
    void on_pushButton_move_clicked();
    void on_pushButton_rotate_clicked();
    void on_pushButton_save_current_clicked();
    void on_pushButton_return_default_clicked();

private:
    model_t model;
    scene_t scene;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
