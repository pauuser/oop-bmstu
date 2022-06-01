#pragma once

#include <exception>
#include <string>
#include <ctime>
#include <chrono>

class MatrixException : public std::exception
{
protected:
    std::string errinfo;
public:
    MatrixException(const std::string filename,
        const size_t line, const std::string inf = "Undefined exception occured!")
    {
        time_t current_time = time(nullptr);
        auto local_time = localtime(&current_time);
        errinfo = "Time: " + std::string(asctime(local_time)) + " File: " + filename + "\nLine : " + std::to_string(line) + " Message : " + inf;
    }

    virtual ~MatrixException() {};

    virtual char const* what() const noexcept override
    {
        return errinfo.c_str();
    }
};

class MemoryError : public MatrixException
{
public:
    MemoryError(const std::string filename,
        const size_t line, const std::string inf = "") :
        MatrixException(filename, line, "Out of memory! " + inf) {}

    virtual ~MemoryError() {};

    virtual char const* what() const noexcept
    {
        return errinfo.c_str();
    }
};

class InitError : public MatrixException
{
public:
    InitError(const std::string filename, const size_t line, const std::string inf = "") :
        MatrixException(filename, line, "Bad initialisation data! " + inf) {}

    virtual ~InitError() {};

    virtual char const* what() const noexcept
    {
        return errinfo.c_str();
    }
};

class IndexOutOfRange : public MatrixException
{
public:
    IndexOutOfRange(size_t ind, const std::string filename,
        const size_t line, const std::string inf = "") :
        MatrixException(filename, line, "Index out of range! " + inf)
    {
        errinfo += " ind = " + std::to_string(ind);
    }

    virtual ~IndexOutOfRange() {};

    virtual char const* what() const noexcept
    {
        return errinfo.c_str();
    }
};

class SizeError : public MatrixException
{
public:
    SizeError(const size_t rows, const size_t cols, const std::string filename,
        const size_t line, const std::string inf = "") :
        MatrixException(filename, line, "Inappropriate size! " + inf)
    {
        errinfo += " rows = " + std::to_string(rows) + " cols = " + std::to_string(cols);
    }

    virtual ~SizeError() {};

    virtual char const* what() const noexcept
    {
        return errinfo.c_str();
    }
};

class ZeroDivMatrix : public MatrixException
{
public:
    ZeroDivMatrix(const size_t row, const size_t col, const std::string filename,
        const size_t line, const std::string inf = "") :
        MatrixException(filename, line, "Division by zero! " + inf)
    {
        errinfo += " row = " + std::to_string(row) + " col = " + std::to_string(col);
    }

    virtual ~ZeroDivMatrix() {};

    virtual char const* what() const noexcept
    {
        return errinfo.c_str();
    }
};

class SingularMatrixError : public MatrixException
{
public:
    SingularMatrixError(const std::string filename,
        const size_t line, const std::string inf = "") :
        MatrixException(filename, line, "Determinant equals zero! " + inf)
    {
    }

    virtual ~SingularMatrixError() {};

    virtual char const* what() const noexcept
    {
        return errinfo.c_str();
    }
};

class NotSquareError : public MatrixException
{
public:
    NotSquareError(const size_t rows, const size_t cols, const std::string filename,
        const size_t line, const std::string inf = "") :
        MatrixException(filename, line, "Inappropriate size! Excpected square matrix! " + inf)
    {
        errinfo += " rows = " + std::to_string(rows) + " cols = " + std::to_string(cols);
    }

    virtual ~NotSquareError() {};

    virtual char const* what() const noexcept
    {
        return errinfo.c_str();
    }
};
