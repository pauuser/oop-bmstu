#include <QMessageBox>

#include "../inc/errors.h"

void print_error(int error)
{
    if (error == INVALID_INPUT)
        QMessageBox::critical(NULL, "Ошибка!",
                                          "Файл содержит некорректный ввод.");
    else if (error == INAPPROPRIATE_INPUT)
        QMessageBox::critical(NULL, "Ошибка!",
                                          "Файл содержит неработающие данные.");
    else if (error == NO_FILE)
        QMessageBox::critical(NULL, "Ошибка!",
                                          "Не удалось открыть файл.");
    else if (error == NO_MODEL)
        QMessageBox::critical(NULL, "Ошибка!",
                                          "Нет модели!");
}
