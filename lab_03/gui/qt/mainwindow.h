//
// Created by Pavel Ivanov on 11.05.2022.
//

#ifndef LAB_03_MAINWINDOW_H
#define LAB_03_MAINWINDOW_H

#include <QMainWindow>


QT_BEGIN_NAMESPACE
namespace Ui {
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

private:
    void on_pushButton_move_clicked();
    void on_pushButton_scale_clicked();
    void on_pushButton_spin_clicked();
    void on_pushButton_del_model_cur_clicked();
    void on_pushButton_del_model_all_clicked();
    void on_pushButton_load_model_clicked();
    void on_pushButton_camera_move_up_clicked();
    void on_pushButton_camera_move_left_clicked();
    void on_pushButton_camera_move_down_clicked();
    void on_pushButton_camera_move_right_clicked();
    void on_pushButton_del_camera_cur_clicked();
    void on_pushButton_add_camera_clicked();
    void change_cam();

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private:
    Ui::MainWindow *ui;
};


#endif//LAB_03_MAINWINDOW_H
