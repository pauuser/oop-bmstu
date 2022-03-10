/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGraphicsView *graphicsView;
    QGroupBox *groupBox_upload;
    QLabel *label_filename;
    QLineEdit *lineEdit_filename;
    QPushButton *pushButton_upload;
    QGroupBox *groupBox_scale;
    QDoubleSpinBox *doubleSpinBox_scale_x;
    QDoubleSpinBox *doubleSpinBox_scale_y;
    QDoubleSpinBox *doubleSpinBox_scale_z;
    QLabel *label_kx;
    QLabel *label_ky;
    QLabel *label_kz;
    QPushButton *pushButton_scale;
    QGroupBox *groupBox_move;
    QDoubleSpinBox *doubleSpinBox_move_x;
    QDoubleSpinBox *doubleSpinBox_move_y;
    QDoubleSpinBox *doubleSpinBox_move_z;
    QLabel *label_dx;
    QLabel *label_dy;
    QLabel *label_dz;
    QPushButton *pushButton_move;
    QGroupBox *groupBox_rotate;
    QDoubleSpinBox *doubleSpinBox_rotate_x;
    QDoubleSpinBox *doubleSpinBox_rotate_y;
    QDoubleSpinBox *doubleSpinBox_rotate_z;
    QLabel *label_ax;
    QLabel *label_ay;
    QLabel *label_az;
    QPushButton *pushButton_rotate;
    QPushButton *pushButton_save_current;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1061, 781);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(350, 10, 701, 671));
        groupBox_upload = new QGroupBox(centralwidget);
        groupBox_upload->setObjectName(QString::fromUtf8("groupBox_upload"));
        groupBox_upload->setGeometry(QRect(9, -1, 331, 121));
        QFont font;
        font.setPointSize(14);
        groupBox_upload->setFont(font);
        label_filename = new QLabel(groupBox_upload);
        label_filename->setObjectName(QString::fromUtf8("label_filename"));
        label_filename->setGeometry(QRect(10, 40, 121, 31));
        QFont font1;
        font1.setPointSize(12);
        label_filename->setFont(font1);
        lineEdit_filename = new QLineEdit(groupBox_upload);
        lineEdit_filename->setObjectName(QString::fromUtf8("lineEdit_filename"));
        lineEdit_filename->setGeometry(QRect(120, 40, 201, 31));
        pushButton_upload = new QPushButton(groupBox_upload);
        pushButton_upload->setObjectName(QString::fromUtf8("pushButton_upload"));
        pushButton_upload->setGeometry(QRect(30, 80, 261, 29));
        pushButton_upload->setFont(font1);
        groupBox_scale = new QGroupBox(centralwidget);
        groupBox_scale->setObjectName(QString::fromUtf8("groupBox_scale"));
        groupBox_scale->setGeometry(QRect(10, 120, 331, 201));
        groupBox_scale->setFont(font);
        doubleSpinBox_scale_x = new QDoubleSpinBox(groupBox_scale);
        doubleSpinBox_scale_x->setObjectName(QString::fromUtf8("doubleSpinBox_scale_x"));
        doubleSpinBox_scale_x->setGeometry(QRect(60, 40, 251, 31));
        doubleSpinBox_scale_x->setFont(font1);
        doubleSpinBox_scale_x->setMinimum(-100.000000000000000);
        doubleSpinBox_scale_x->setValue(1.000000000000000);
        doubleSpinBox_scale_y = new QDoubleSpinBox(groupBox_scale);
        doubleSpinBox_scale_y->setObjectName(QString::fromUtf8("doubleSpinBox_scale_y"));
        doubleSpinBox_scale_y->setGeometry(QRect(60, 80, 251, 31));
        doubleSpinBox_scale_y->setFont(font1);
        doubleSpinBox_scale_y->setMinimum(-100.000000000000000);
        doubleSpinBox_scale_y->setValue(1.000000000000000);
        doubleSpinBox_scale_z = new QDoubleSpinBox(groupBox_scale);
        doubleSpinBox_scale_z->setObjectName(QString::fromUtf8("doubleSpinBox_scale_z"));
        doubleSpinBox_scale_z->setGeometry(QRect(60, 120, 251, 31));
        doubleSpinBox_scale_z->setFont(font1);
        doubleSpinBox_scale_z->setMinimum(-100.000000000000000);
        doubleSpinBox_scale_z->setValue(1.000000000000000);
        label_kx = new QLabel(groupBox_scale);
        label_kx->setObjectName(QString::fromUtf8("label_kx"));
        label_kx->setGeometry(QRect(20, 40, 31, 31));
        label_kx->setFont(font1);
        label_ky = new QLabel(groupBox_scale);
        label_ky->setObjectName(QString::fromUtf8("label_ky"));
        label_ky->setGeometry(QRect(20, 80, 21, 31));
        label_ky->setFont(font1);
        label_kz = new QLabel(groupBox_scale);
        label_kz->setObjectName(QString::fromUtf8("label_kz"));
        label_kz->setGeometry(QRect(20, 120, 21, 21));
        label_kz->setFont(font1);
        pushButton_scale = new QPushButton(groupBox_scale);
        pushButton_scale->setObjectName(QString::fromUtf8("pushButton_scale"));
        pushButton_scale->setGeometry(QRect(30, 160, 261, 29));
        QFont font2;
        font2.setPointSize(12);
        font2.setItalic(false);
        pushButton_scale->setFont(font2);
        groupBox_move = new QGroupBox(centralwidget);
        groupBox_move->setObjectName(QString::fromUtf8("groupBox_move"));
        groupBox_move->setGeometry(QRect(10, 320, 331, 201));
        groupBox_move->setFont(font);
        doubleSpinBox_move_x = new QDoubleSpinBox(groupBox_move);
        doubleSpinBox_move_x->setObjectName(QString::fromUtf8("doubleSpinBox_move_x"));
        doubleSpinBox_move_x->setGeometry(QRect(70, 40, 251, 31));
        doubleSpinBox_move_x->setFont(font1);
        doubleSpinBox_move_x->setDecimals(5);
        doubleSpinBox_move_x->setMinimum(-100.000000000000000);
        doubleSpinBox_move_x->setMaximum(5000.000000000000000);
        doubleSpinBox_move_x->setValue(0.000000000000000);
        doubleSpinBox_move_y = new QDoubleSpinBox(groupBox_move);
        doubleSpinBox_move_y->setObjectName(QString::fromUtf8("doubleSpinBox_move_y"));
        doubleSpinBox_move_y->setGeometry(QRect(70, 80, 251, 31));
        doubleSpinBox_move_y->setFont(font1);
        doubleSpinBox_move_y->setDecimals(5);
        doubleSpinBox_move_y->setMinimum(-100.000000000000000);
        doubleSpinBox_move_y->setMaximum(5000.000000000000000);
        doubleSpinBox_move_y->setValue(0.000000000000000);
        doubleSpinBox_move_z = new QDoubleSpinBox(groupBox_move);
        doubleSpinBox_move_z->setObjectName(QString::fromUtf8("doubleSpinBox_move_z"));
        doubleSpinBox_move_z->setGeometry(QRect(70, 120, 251, 31));
        doubleSpinBox_move_z->setFont(font1);
        doubleSpinBox_move_z->setDecimals(5);
        doubleSpinBox_move_z->setMinimum(-100.000000000000000);
        doubleSpinBox_move_z->setMaximum(5000.000000000000000);
        doubleSpinBox_move_z->setValue(0.000000000000000);
        label_dx = new QLabel(groupBox_move);
        label_dx->setObjectName(QString::fromUtf8("label_dx"));
        label_dx->setGeometry(QRect(30, 40, 31, 31));
        label_dx->setFont(font1);
        label_dy = new QLabel(groupBox_move);
        label_dy->setObjectName(QString::fromUtf8("label_dy"));
        label_dy->setGeometry(QRect(30, 80, 21, 31));
        label_dy->setFont(font1);
        label_dz = new QLabel(groupBox_move);
        label_dz->setObjectName(QString::fromUtf8("label_dz"));
        label_dz->setGeometry(QRect(30, 120, 21, 21));
        label_dz->setFont(font1);
        pushButton_move = new QPushButton(groupBox_move);
        pushButton_move->setObjectName(QString::fromUtf8("pushButton_move"));
        pushButton_move->setGeometry(QRect(30, 160, 261, 29));
        pushButton_move->setFont(font1);
        groupBox_rotate = new QGroupBox(centralwidget);
        groupBox_rotate->setObjectName(QString::fromUtf8("groupBox_rotate"));
        groupBox_rotate->setGeometry(QRect(10, 530, 331, 201));
        groupBox_rotate->setFont(font);
        doubleSpinBox_rotate_x = new QDoubleSpinBox(groupBox_rotate);
        doubleSpinBox_rotate_x->setObjectName(QString::fromUtf8("doubleSpinBox_rotate_x"));
        doubleSpinBox_rotate_x->setGeometry(QRect(60, 40, 251, 31));
        doubleSpinBox_rotate_x->setFont(font1);
        doubleSpinBox_rotate_x->setDecimals(5);
        doubleSpinBox_rotate_x->setMinimum(-360.000000000000000);
        doubleSpinBox_rotate_x->setMaximum(360.000000000000000);
        doubleSpinBox_rotate_x->setValue(0.000000000000000);
        doubleSpinBox_rotate_y = new QDoubleSpinBox(groupBox_rotate);
        doubleSpinBox_rotate_y->setObjectName(QString::fromUtf8("doubleSpinBox_rotate_y"));
        doubleSpinBox_rotate_y->setGeometry(QRect(60, 80, 251, 31));
        doubleSpinBox_rotate_y->setFont(font1);
        doubleSpinBox_rotate_y->setDecimals(5);
        doubleSpinBox_rotate_y->setMinimum(-360.000000000000000);
        doubleSpinBox_rotate_y->setMaximum(360.000000000000000);
        doubleSpinBox_rotate_y->setValue(0.000000000000000);
        doubleSpinBox_rotate_z = new QDoubleSpinBox(groupBox_rotate);
        doubleSpinBox_rotate_z->setObjectName(QString::fromUtf8("doubleSpinBox_rotate_z"));
        doubleSpinBox_rotate_z->setGeometry(QRect(60, 120, 251, 31));
        doubleSpinBox_rotate_z->setFont(font1);
        doubleSpinBox_rotate_z->setDecimals(5);
        doubleSpinBox_rotate_z->setMinimum(-360.000000000000000);
        doubleSpinBox_rotate_z->setMaximum(360.000000000000000);
        doubleSpinBox_rotate_z->setValue(0.000000000000000);
        label_ax = new QLabel(groupBox_rotate);
        label_ax->setObjectName(QString::fromUtf8("label_ax"));
        label_ax->setGeometry(QRect(20, 40, 31, 31));
        label_ax->setFont(font1);
        label_ay = new QLabel(groupBox_rotate);
        label_ay->setObjectName(QString::fromUtf8("label_ay"));
        label_ay->setGeometry(QRect(20, 80, 21, 31));
        label_ay->setFont(font1);
        label_az = new QLabel(groupBox_rotate);
        label_az->setObjectName(QString::fromUtf8("label_az"));
        label_az->setGeometry(QRect(20, 120, 21, 21));
        label_az->setFont(font1);
        pushButton_rotate = new QPushButton(groupBox_rotate);
        pushButton_rotate->setObjectName(QString::fromUtf8("pushButton_rotate"));
        pushButton_rotate->setGeometry(QRect(30, 160, 261, 29));
        pushButton_rotate->setFont(font1);
        pushButton_save_current = new QPushButton(centralwidget);
        pushButton_save_current->setObjectName(QString::fromUtf8("pushButton_save_current"));
        pushButton_save_current->setGeometry(QRect(710, 690, 321, 29));
        pushButton_save_current->setFont(font1);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1061, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox_upload->setTitle(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\272\320\260 \320\274\320\276\320\264\320\265\320\273\320\270 \320\270\320\267 \321\204\320\260\320\271\320\273\320\260", nullptr));
        label_filename->setText(QCoreApplication::translate("MainWindow", "\320\230\320\274\321\217 \321\204\320\260\320\271\320\273\320\260:", nullptr));
        lineEdit_filename->setText(QCoreApplication::translate("MainWindow", "./test/coub.txt", nullptr));
        pushButton_upload->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214 \320\274\320\276\320\264\320\265\320\273\321\214", nullptr));
        groupBox_scale->setTitle(QCoreApplication::translate("MainWindow", "\320\234\320\260\321\201\321\210\321\202\320\260\320\261\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265", nullptr));
        label_kx->setText(QCoreApplication::translate("MainWindow", "kx", nullptr));
        label_ky->setText(QCoreApplication::translate("MainWindow", "ky", nullptr));
        label_kz->setText(QCoreApplication::translate("MainWindow", "kz", nullptr));
        pushButton_scale->setText(QCoreApplication::translate("MainWindow", "\320\234\320\260\321\201\321\210\321\202\320\260\320\261\320\270\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        groupBox_move->setTitle(QCoreApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\275\320\276\321\201", nullptr));
        label_dx->setText(QCoreApplication::translate("MainWindow", "dx", nullptr));
        label_dy->setText(QCoreApplication::translate("MainWindow", "dy", nullptr));
        label_dz->setText(QCoreApplication::translate("MainWindow", "dz", nullptr));
        pushButton_move->setText(QCoreApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\275\320\265\321\201\321\202\320\270", nullptr));
        groupBox_rotate->setTitle(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\262\320\276\321\200\320\276\321\202", nullptr));
        label_ax->setText(QCoreApplication::translate("MainWindow", "ax", nullptr));
        label_ay->setText(QCoreApplication::translate("MainWindow", "ay", nullptr));
        label_az->setText(QCoreApplication::translate("MainWindow", "az", nullptr));
        pushButton_rotate->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\262\320\265\321\200\320\275\321\203\321\202\321\214", nullptr));
        pushButton_save_current->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
