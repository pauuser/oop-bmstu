#include "mainwindow.h"
#include "file_io.h"
#include <iostream>

#include <QApplication>

int main(int argc, char *argv[])
{
    setbuf(stdout, NULL);
    QApplication a(argc, argv);

    MainWindow w;
    w.show();
    return a.exec();
}
