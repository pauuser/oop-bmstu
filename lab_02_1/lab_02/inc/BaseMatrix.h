#pragma once

class BaseMatrix
{
public:
	// ������������ � ����������
	explicit BaseMatrix(size_t rows=0, size_t cols=0) : ncols(cols), nrows(rows) {};
	virtual ~BaseMatrix() = 0;

	// ������� ������ ������������ ������
	virtual size_t getColumns() const { return ncols; }
	virtual size_t getRows() const { return nrows; }
	virtual bool isSquare() const { return ncols == nrows; }

	// ���������� ��������� bool - �������� �� �������������
	explicit virtual operator bool() const { return ncols && nrows; }

protected:
	size_t ncols;
	size_t nrows;
};

BaseMatrix::~BaseMatrix()
{
	nrows = 0;
	ncols = 0;
}
