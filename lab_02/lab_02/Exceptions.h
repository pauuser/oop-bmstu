#pragma once

#include <exception>
#include <string>

class MatrixException : public std::exception
{
protected:
	std::string errinfo;
public:
	// Перегружаем конструктор, т.к. появился член errinfo
	MatrixException(const std::string time, const std::string filename,
		const size_t line, const std::string inf = "Undefined exception occured!")
	{
		errinfo = "\nTime: " + time + "File: " + filename + "\nLine : " + std::to_string(line) + "Message : " + inf;
	}

	virtual ~MatrixException() {}; // виртуальность для возможности подмены

	virtual char const* what() const noexcept override
	{
		return errinfo.c_str();
	}
};

class MemoryError : public MatrixException
{
	MemoryError(const std::string time, const std::string filename,
		const size_t line, const std::string inf = "") :
		MatrixException(time, filename, line, "Out of memory! " + inf) {}

	virtual ~MemoryError() {}; // виртуальность для возможности подмены

	virtual char const* what() const noexcept
	{
		return errinfo.c_str();
	}
};

class InitError : public MatrixException
{
	InitError(const std::string time, const std::string filename,
		const size_t line, const std::string inf = "") :
		MatrixException(time, filename, line, "Bad initialisation! " + inf) {}

	virtual ~InitError() {}; // виртуальность для возможности подмены

	virtual char const* what() const noexcept
	{
		return errinfo.c_str();
	}
};

