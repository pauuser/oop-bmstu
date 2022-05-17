//
// Created by Pavel Ivanov on 17.05.2022.
//

#ifndef LAB_03_LOADEREXCEPTION_HPP
#define LAB_03_LOADEREXCEPTION_HPP

#include "exceptions/BaseException.hpp"

class LoaderException : public BaseException
{
public:
    LoaderException(const std::string& file, const std::size_t line, const std::string inf = "") :
            BaseException(file, line, "Error while loading an object! " + inf) {}
    ~LoaderException() override = default;

    const char * what() const noexcept override
    {
        return errinfo.c_str();
    }
};

class NoFileException : public LoaderException
{
public:
    NoFileException(const std::string& file, const std::size_t line, const std::string inf = "") :
            LoaderException(file, line, "No file! " + inf) {}
    ~NoFileException() override = default;

    const char * what() const noexcept override
    {
        return errinfo.c_str();
    }
};

class IncorrectInputException : public LoaderException
{
public:
    IncorrectInputException(const std::string& file, const std::size_t line, const std::string inf = "") :
           LoaderException(file, line, "Incorrect input! " + inf) {}
    ~IncorrectInputException() override = default;

    const char * what() const noexcept override
    {
        return errinfo.c_str();
    }
};


#endif//LAB_03_LOADEREXCEPTION_HPP
