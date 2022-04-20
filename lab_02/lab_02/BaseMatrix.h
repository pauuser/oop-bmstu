#pragma once

class BaseMatrix
{
public:
	//  онструкторы и деструктор
	explicit BaseMatrix(size_t rows=0, size_t cols=0) : ncols(cols), nrows(rows) {};
	virtual ~BaseMatrix() = 0;

	// Ѕазовые методы абстрактного класса
	virtual size_t getColumns() const { return ncols; }
	virtual size_t getRows() const { return nrows; }
	virtual bool is_square() { return ncols == nrows; }

	// ѕерегрузка оператора bool - проверка на инициализацию
	explicit virtual operator bool() const { return ncols && nrows; }

protected:
	size_t ncols;
	size_t nrows;
};

