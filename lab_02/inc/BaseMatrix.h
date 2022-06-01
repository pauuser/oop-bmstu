#pragma once

#include <memory>

class BaseMatrix
{
public:
    // Конструкторы и деструктор
    BaseMatrix(size_t rows = 0, size_t cols = 0) : ncols(cols), nrows(rows) {};
    virtual ~BaseMatrix() = 0;

    // Базовые методы абстрактного класса
    virtual size_t getColumns() const { return ncols; }
    virtual size_t getRows() const { return nrows; }
    virtual bool isSquare() const { return ncols == nrows; }

    // Перегрузка оператора bool - проверка на инициализацию
    explicit virtual operator bool() const { return ncols && nrows; }

protected:
    size_t ncols;
    size_t nrows;
};

