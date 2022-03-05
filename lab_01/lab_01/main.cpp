#include "mainwindow.h"
#include "file_io.h"
#include <iostream>

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    /*
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
    */


    MainWindow w;
    w.show();
    return a.exec();
}
